#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() : head(nullptr) {}

    // Function to insert a node at the end
    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode; // Link the last node to the new node
            newNode->next = head; // Make it circular
        }
        cout << "Inserted: " << data << endl;
    }

    // Function to delete a node
    void deleteNode(int key) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // If the node to be deleted is the head
        if (head->data == key) {
            // If there is only one node
            if (head->next == head) {
                delete head;
                head = nullptr;
                cout << "Deleted: " << key << endl;
                return;
            } else {
                // Find the last node
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = head->next; // Point last node to the next of head
                delete head; // Delete head
                head = temp->next; // Update head
                cout << "Deleted: " << key << endl;
                return;
            }
        }

        // Traverse the list to find the node to delete
        while (temp->next != head && temp->next->data != key) {
            temp = temp->next;
        }

        // If the node was not found
        if (temp->next == head) {
            cout << "Node with value " << key << " not found." << endl;
            return;
        }

        // Delete the node
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next; // Bypass the node
        delete nodeToDelete; // Delete node
        cout << "Deleted: " << key << endl;
    }

    // Function to traverse the list
    void traverse() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        if (head == nullptr) return;

        Node* temp = head;
        Node* toDelete;

        // Loop until we reach back to head
        do {
            toDelete = temp;
            temp = temp->next;
            delete toDelete;
        } while (temp != head);

        head = nullptr;
    }
};

int main() {
    CircularLinkedList cll;

    // Insert elements
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.insert(40);

    // Display elements
    cout << "Circular Linked List: ";
    cll.traverse();

    // Delete an element
    cll.deleteNode(20);
    cout << "After deleting 20: ";
    cll.traverse();

    // Delete head element
    cll.deleteNode(10);
    cout << "After deleting 10: ";
    cll.traverse();

    // Attempt to delete a non-existing element
    cll.deleteNode(50);

    return 0;
}
