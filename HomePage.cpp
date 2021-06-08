#include "HomePage.hpp"  


using namespace std;
using namespace Wt;
	
page::page(const Wt::WEnvironment& env)
  : WApplication(env)
{
	setTitle("Hello world");                            // application title

  root()->addWidget(std::make_unique<Wt::WText>("Web site built in c++. Work in progress. ")); // show some text
}
	
page::~page()
{
	
}