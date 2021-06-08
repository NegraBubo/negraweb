
using namespace std;
#include "HomePage.cpp"

// run the web app
int main(int argc, char **argv) {
 
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment &env) {
    return std::make_unique<page>(env);
  });

 

}
