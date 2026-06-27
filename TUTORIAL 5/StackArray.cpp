#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    string arr[10];
    int top = -1;

    void push(string name) {
        if (top == 9) {
            cout << "Overflow\n";
            return;
        }
        arr[++top] = name;
    }

    void pop() {
        if (top == -1) {
            cout << "Underflow\n";
            return;
        }
        top--;
    }

    void peek() {
        if (top != -1)
            cout << arr[top] << endl;
    }

    void display_stack() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack s;
    cout << "\n1. Push():\n";
    s.push("A");
    s.push("B");
    s.push("C");
    s.push("D");
    s.display_stack();

    s.pop();
    cout << "\n2. Pop():\n";
    s.display_stack();

    cout << "\n3. Peek():\n";
    s.peek();
}
