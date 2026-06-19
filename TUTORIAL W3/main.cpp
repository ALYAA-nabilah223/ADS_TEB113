#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* next = NULL;
    
    void insertion(Node* newNode) {
        if (newNode == NULL) return;
        Node* temp = this;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    Node* deletion(Node* head, string targetName) {
        if (head == NULL) return NULL;
        
        // Case 1: The node to delete is the head node
        if (head->name == targetName) {
            Node* temp = head->next;
            delete head;
            return temp; // New head
        }
        
        // Case 2: The node is somewhere else in the list
        Node* current = head;
        Node* prev = NULL;
        
        while (current != NULL && current->name != targetName) {
            prev = current;
            current = current->next;
        }
        
        // If the name was found, unlink the node and free memory
        if (current != NULL) {
            prev->next = current->next;
            delete current;
        } else {
            cout << "Name \"" << targetName << "\" not found in the list.\n";
        }
        
        return head; // Head remains the same
    }
    
    void display_list(Node* head) {
        Node* display_node = head;
        while (display_node != NULL) {
            cout << display_node->name << " -> ";
            display_node = display_node->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Node* node1 = new Node();
    node1->name = "Aiman";
    
    Node* node2 = new Node();
    node2->name = "Ahmad";
    
    Node* node3 = new Node();
    node3->name = "Anajana";
    
    Node* node4 = new Node();
    node4->name = "Jessy";
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    // --- Testing Insertion ---
    Node* node5 = new Node();
    node5->name = "Ali";
    node1->insertion(node5); 
    
    cout << "Original List after inserting Ali:" << endl;
    node1->display_list(node1);
    cout << "-----------------------------------" << endl;
    
    // --- Testing Deletion ---
    cout << "Deleting 'Anajana' from the list:" << endl;
    Node* head = node1;
    head = head->deletion(head, "Anajana");
    
    // Display final list
    head->display_list(head);
    
  
    while (head != NULL) {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }
    
    return 0;
}