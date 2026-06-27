#include <iostream>
#include <string>
using namespace std;

class Queue {
public:
    string arr[10];
    int front = 0;
    int rear = -1;
    int size = 0;

    void enqueue(string name) {
        if (rear == 9) {
            cout << "Overflow\n";
            return;
        }
        arr[++rear] = name;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Underflow\n";
            return;
        }
        front++;
        size--;
    }

    void display_queue() {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    cout << "\n1. Enqueue():\n";
    q.enqueue("A");
    q.enqueue("B");
    q.enqueue("C");
    q.enqueue("D");
    q.display_queue();

    cout << "\n2. Dequeue():\n";
    q.dequeue();
    q.display_queue();
}
