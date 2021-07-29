#include "action/Action.h"
#include "menu/MenuItem.h"

using namespace std;


int main() {
    MenuBar menuBar;

    Menu File;
    Menu About;

    Action* actionNew = new CreateAction();
    MenuItem New("new", actionNew);
    Action* actionExit = new ExitAction();
    MenuItem Exit("exit", actionExit);

    Action* actionText = new CreateAction();
    MenuItem Text("text", actionText);
    Action* actionCPlusPlus = new CreateAction();
    MenuItem CPlusPlus("c++", actionCPlusPlus);

    File.add(New);
    File.add(Exit);

    About.add(Text);
    About.add(CPlusPlus);

    menuBar.add(File);
    menuBar.add(About);

//    File.clicked();
//    menuBar.print();
    File.print();
    New.clicked();
    CPlusPlus.clicked();
    Exit.clicked();

    //deletes...

    return 0;
}
