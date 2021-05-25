#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WText.h>

using namespace std;
using namespace Wt;

// define a web app
struct App : WApplication {
  App(const WEnvironment& env) : WApplication(env) {

    // add widgets
    auto myEdit = root()->addWidget(make_unique<WLineEdit>());
    root()->addWidget(make_unique<WBreak>());
    auto myText = root()->addWidget(make_unique<WText>());

    // connect widgets to callback functions
    auto editFunc = [=]{ myText->setText(myEdit->text()); };
    myEdit->textInput().connect(editFunc);
  }
};

// run the web app
int main(int argc, char **argv) {
  auto mkApp = [](const WEnvironment& env) { return make_unique<App>(env); };
  return WRun(argc, argv, mkApp);
}
