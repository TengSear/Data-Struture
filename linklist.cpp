#include <iostream>
using namespace std;

class Node{
    public:
        //declaration data and links
        // [    data  |store address]
        int data;
        Node* next;
        
        // constructor
        Node(int data):data(data),next(nullptr) {}
};

class LinkedList{
    public:
        Node* head;
    public:
        LinkedList():head(nullptr) {}

        void add_first(int data){
            Node* newNode = new Node(data);
            //newNode->next point to current head
            newNode->next = head;
            //update head to new node
            head = newNode;
            
        }

        int get_first() {
            if (head == nullptr) {
                cout << "List is empty" << endl;
                return -1; // Return a default value or handle error as needed
            }
            return head->data;
        }

        // Returns a pointer to the first node
        Node* peek_first() {
            return head;
        }

        // Displays all the data in the list
        void show_all() {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        void add_last(int data) {
            Node* newNode = new Node(data);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
 
        int get_last() {
            if (head == nullptr) {
                cout << "List is empty" << endl;
                return -1; 
            }
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            return current->data;
        }

        Node* peek_last() {
            if (head == nullptr) {
                return nullptr;
            }
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            return current;
        }
        void clear() {
            Node* current = head;
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
            head = nullptr;
        }

        void add(int data, int position) {
            Node* newNode = new Node(data);
            if (position == 0) {
                newNode->next = head;
                head = newNode;
                return;
            }
            // 1
            Node* current = head;
            //          0          1               
            for (int i = 0; current != nullptr && i < position-1 ; ++i) {
                current = current->next;
            }

            if (current == nullptr) {
                cout << "Position out of bounds" << endl;
                delete newNode;
                return;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
};

int main(){
    LinkedList list;
    
    list.add_first(1);  
    list.add_first(2); 
    list.add_first(3); 

    cout << "First element: " << list.get_first() << endl;

    Node* first_node = list.peek_first();
    cout << "Peek at first node: " << first_node->data << endl;
    
    list.add_last(5);
    list.add_last(5);
    list.add_last(5);
    cout << "Last element: " << list.get_last() << endl;

    Node* last_node = list.peek_last();
    if (last_node != nullptr) {
        cout << "Peek at last node: " << last_node->data << endl;
    }

    // Adding element at position
    list.add(7, 1); // Add 7 at position 2
    cout << "All elements after adding 7 at position 2: ";
    list.show_all();

    // Clearing the list
    list.clear();
    cout << "All elements after clearing: ";
    list.show_all();


}
