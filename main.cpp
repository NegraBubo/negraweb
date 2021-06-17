
#include "HomePage.cpp"
#include "Database/DBConnect.hpp"
#include <array>

using namespace std;
// run the web app
int main(int argc, char **argv) {

  DBConnect* connection = new DBConnect();

    return Wt::WRun(argc, argv, [](const Wt::WEnvironment &env) {
    return std::make_unique<page>(env);

  });




}
