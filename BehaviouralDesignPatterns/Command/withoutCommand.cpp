#include<bits/stdc++.h>
using namespace std;

class TextEditor {
public:
    void boldText() {
        cout << "Text has been bolded" << endl;
    }
    void italicizeText() {
        cout << "Text has been italicized" << endl;
    }
    void underlineText() {
        cout << "Text has been underlined" << endl;
    }
};

//UI buttons
class BoldButton {
private:
    TextEditor editor;
public:
    BoldButton(TextEditor editor) {
        this->editor = editor;
    }
    void click() {
        editor.boldText();
    }
};

class ItalicButton {
private:
    TextEditor editor;
public:
    ItalicButton(TextEditor editor) {
        this->editor = editor;
    }
    void click() {
        editor.italicizeText();
    }
};

class UnderlineButton {
private:
    TextEditor editor;
public:
    UnderlineButton(TextEditor editor) {
        this->editor = editor;
    }
    void click() {
        editor.underlineText();
    }
};

int main()
{
    TextEditor editor;
    BoldButton boldButton(editor);
    ItalicButton italicButton(editor);
    boldButton.click();
    italicButton.click();
    return 0;
}