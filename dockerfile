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

RUN apt-get install -y libmysqlcppconn-dev


# get and build wt4
WORKDIR /root
RUN wget https://github.com/emweb/wt/archive/4.0.4.tar.gz
RUN tar zxf 4.0.4.tar.gz
WORKDIR /root/wt-4.0.4/build
RUN cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=OFF -DBUILD_EXAMPLES=OFF ..
RUN make -j2 install
RUN ldconfig


# build our app
WORKDIR /root/main
ADD . /root/main
RUN g++ -O2 -o main Database/DBConnect.cpp main.cpp -lwthttp -lwt  -L/usr/lib -lmysqlcppconn
CMD /root/main/main --docroot . --http-address 0.0.0.0 --http-port $PORT 
