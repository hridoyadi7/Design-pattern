#include<bits/stdc++.h>
using namespace std;

class EditorMemento {
private:
    const string content;
public:
    EditorMemento(const string& c) : content(c) {
    }
    string getContent() const {
        return content;
    }
};

class TextEditor {
private:
    string content;
public:
    void write(string text) {
        content = text;
    }
    //Return current state of the editor
    EditorMemento save() {
        return EditorMemento(content);
    }
    //Restore(memento-> update the state of current content)
    void restore(EditorMemento& memento) {
        content = memento.getContent();
    }
    string getContent() {
        return content;
    }
};

class Caretaker {
private:
    stack<EditorMemento> history;
public:
    void saveState(TextEditor& editor) {
        history.push(editor.save());
    }
    void undo(TextEditor& editor) {
        if(!history.empty()) {
            history.pop();
            if(!history.empty()) {
                editor.restore(history.top());
            } else {
                EditorMemento editorMemento(""); 
                editor.restore(editorMemento); // Restore to empty state if no history
            }
        }
    }
};

int main() {
    TextEditor editor;
    Caretaker caretaker; // History/State management
    editor.write("A");
    caretaker.saveState(editor); 
    editor.write("B");
    caretaker.saveState(editor);
    editor.write("C");
    caretaker.saveState(editor);
    cout << "Current Content:" << editor.getContent() << endl;
    caretaker.undo(editor);
    cout << "After Undo for first time content:" << editor.getContent() << endl;
    caretaker.undo(editor);
    cout << "After Undo for second time content:" << editor.getContent() << endl;
    return 0;
}