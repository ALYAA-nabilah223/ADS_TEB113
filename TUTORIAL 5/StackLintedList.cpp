#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    string name;
    Stack* next = NULL;
    Stack* head = NULL;

    void push(string name) {
        Stack* newnode = new Stack();
        newnode->name = name;
        newnode->next = head;
        head = newnode;
    }

    void pop() {
        if (head == NULL) {
            cout << "Underflow";
            return;
        }
        Stack* temp = head;
        head = head->next;
        delete temp;
    }

    void peek() {
        if (head != NULL)
            cout << head->name;
    }

    void display_stack() {
        Stack* display_node = head;
        while (display_node != NULL) {
            cout << display_node->name << endl;
            display_node = display_node->next;
        }
    }
};

int main() {
    Stack* stack = new Stack();

    cout << "\n1. Push(): ";
    stack->push("A");
    stack->push("B");
    stack->push("C");
    stack->push("D");

    stack->display_stack();

    stack->pop();
    cout << "\n2. Pop(): \n";
    stack->display_stack();

    cout << "\n3. Peek(): \n";
    stack->peek();
}