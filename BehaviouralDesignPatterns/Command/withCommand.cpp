#include<bits/stdc++.h>
using namespace std;

//Receiver: TextEditor class
class TextEditor {
public:
    void boldText() {
        cout << "Text has been bolded" << endl;
    }
    void changeColor() {
        cout << "Text color has been changed" << endl;
    }
};

//Command Interface
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

//Concrete classes for Commands
class BoldCommand : public Command {
private:
    TextEditor editor;
public:
    BoldCommand(TextEditor editor) : editor(editor) {
    }
    void execute() override {
        editor.boldText();
    }
};

class ChangeColor : public Command {
private:
    TextEditor editor;
public:
    ChangeColor(TextEditor editor) : editor(editor) {
    }
    void execute() override {
        editor.changeColor();
    }
};

//Button class
class Button {
private:
    shared_ptr<Command> command;
public:
    void setCommand(shared_ptr<Command> command) {
        this->command = command;
    }
    void click() {
        command->execute();
    }
};

int main() {
    TextEditor editor;
    shared_ptr<Command> boldCommand = make_shared<BoldCommand>(editor);
    shared_ptr<Command> changeColor = make_shared<ChangeColor>(editor);
    //Decouping -> one button can do many types of actions
    Button button;
    button.setCommand(boldCommand);
    button.click();
    button.setCommand(changeColor);
    button.click();
    return 0;
}
