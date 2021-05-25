# get and configure an image
FROM debian:stretch-slim
RUN apt-get update
RUN apt-get install -y --no-install-recommends \
    ca-cacert \
    cmake \
    build-essential \
    libboost-all-dev \
    libssl-dev \
    wget \
    zlib1g-dev

# get and build wt4
WORKDIR /root
RUN wget https://github.com/emweb/wt/archive/4.0.4.tar.gz
RUN tar zxf 4.0.4.tar.gz
WORKDIR /root/wt-4.0.4/build
RUN cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=OFF -DBUILD_EXAMPLES=OFF ..
RUN make -j2 install
RUN ldconfig

# build our app
WORKDIR /root/myweb
ADD . /root/myweb
RUN g++ -O2 -o myweb myweb.cpp -lwthttp -lwt
CMD /root/myweb/myweb --docroot . --http-address 0.0.0.0 --http-port $PORT
