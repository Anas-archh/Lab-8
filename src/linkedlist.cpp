#include <iostream>
using namespace std;

// Node class representing each element in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList class managing the linked list operations
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Function to print all elements in the linked list
    void print() {
        // TODO: Traverse and print all elements
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }


    // Function to calculate the length of the linked list
    int length() {
        // TODO: Traverse and count all nodes
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }



    // Function to insert before a specific value
    void insertBefore(int target, int newValue) {
        // TODO: Insert newValue before target node
        Node* newNode = new Node(newValue);
        if (!head) {
            delete newNode;
            return;
        }

        if (head->data == target) { 
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != target) {
            current = current->next;
        }

        if (current->next != nullptr) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
             delete newNode;
        }
    }

    // Function to insert after a specific value
    void insertAfter(int target, int newValue) {
        // TODO: Insert newValue after target node
        Node* current = head;
        while (current != nullptr && current->data != target) {
            current = current->next;
        }

        if (current != nullptr) {
            Node* newNode = new Node(newValue);
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to delete node before a specific value
    void deleteBefore(int target) {
        // TODO: Delete node before target node
        if (!head || !head->next) return;

        if (head->next->data == target) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->next != nullptr) {
            if (current->next->next->data == target) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }


    // Function to delete node after a specific value
    void deleteAfter(int target) {
        // TODO: Delete node after target node

        Node* current = head;
        while (current != nullptr && current->data != target) {
            current = current->next;
        }

        if (current != nullptr && current->next != nullptr) {
            Node* temp = current->next;
            current->next = temp->next;    
            delete temp;
        }
    }
};

// Main function for testing
int main() {
    LinkedList list;
    int n, value;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Initial List: ";
    list.print();

    cout << "Length of list: " << list.length() << endl;

    // Demonstration of insertBefore, insertAfter, deleteBefore, deleteAfter
    cout << "\nInsert a value before a given element:\n";
    list.insertBefore(20, 15); // Example
    list.print();

    cout << "\nInsert a value after a given element:\n";
    list.insertAfter(30, 35); // Example
    list.print();

    cout << "\nDelete node before a given element:\n";
    list.deleteBefore(20);
    list.print();

    cout << "\nDelete node after a given element:\n";
    list.deleteAfter(30);
    list.print();

    return 0;
}
