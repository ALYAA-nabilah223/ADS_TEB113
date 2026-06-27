#include <iostream>
#include <string>
using namespace std;

class Queue {
public:
    string name;
    Queue* next = NULL;
    Queue* head = NULL;
    Queue* tail = NULL;

    void enqueue(string name) {
        Queue* newnode = new Queue();
        newnode->name = name;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            tail = newnode;
        }
        else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void dequeue() {
        if (head == NULL) {
            cout << "Underflow" << endl;
            return;
        }
        Queue* temp = head;
        head = head->next;
        delete temp;

        if (head == NULL) {
            tail = NULL;
        }
    }

    void display_queue() {
        Queue* current = head;
        while (current != NULL) {
            cout << current->name << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue* q = new Queue();

    cout << "\n1. Enqueue(): ";
    q->enqueue("A");
    q->enqueue("B");
    q->enqueue("C");
    q->enqueue("D");
    q->display_queue();

    cout << "\n2. Dequeue(): ";
    q->dequeue();
    q->display_queue();

}
