#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class PriorityQueue2DLinkedList {
private:
    Node* front[4];  // Front pointers for each row
    Node* rear[4];   // Rear pointers for each row

public:
    PriorityQueue2DLinkedList() {
        // Initialize the front and rear pointers for all rows as null
        for (int i = 0; i < 4; ++i) {
            front[i] = nullptr;
            rear[i] = nullptr;
        }
    }

    bool isEmpty(int row) {
        return front[row] == nullptr;
    }

    void enqueue(int row, char value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty(row)) {
            // If the row is empty, both front and rear point to the new node
            front[row] = newNode;
            rear[row] = newNode;
        } else {
            // Otherwise, add the new node at the rear and update the rear pointer
            rear[row]->next = newNode;
            rear[row] = newNode;
        }

        cout << "Enqueued '" << value << "' to row " << row + 1 << endl;
    }

    void dequeue(int row) {
        if (isEmpty(row)) {
            cout << "Row " << row + 1 << " is empty!" << endl;
            return;
        }

        Node* temp = front[row];
        cout << "Dequeued '" << temp->data << "' from row " << row + 1 << endl;

        // Move the front pointer to the next node
        front[row] = front[row]->next;

        // If the row becomes empty, set rear to null as well
        if (front[row] == nullptr) {
            rear[row] = nullptr;
        }

        delete temp;
    }

    void display() {
        for (int i = 0; i < 4; ++i) {
            if (!isEmpty(i)) {
                cout << "Row " << i + 1 << ": ";
                Node* current = front[i];
                while (current != nullptr) {
                    cout << current->data << " ";
                    current = current->next;
                }
                cout << endl;
            } else {
                cout << "Row " << i + 1 << " is empty!" << endl;
            }
        }
    }

    ~PriorityQueue2DLinkedList() {
        // Destructor to free all nodes in the priority queue
        for (int i = 0; i < 4; ++i) {
            while (!isEmpty(i)) {
                dequeue(i);
            }
        }
    }
};

int main() {
    PriorityQueue2DLinkedList pq;

    // Enqueue elements into different rows
    pq.enqueue(0, 'A');
    pq.enqueue(1, 'B');
    pq.enqueue(1, 'C');
    pq.enqueue(1, 'D');
    pq.enqueue(2, 'E');
    pq.enqueue(2, 'F');
    pq.enqueue(3, 'G');
    pq.enqueue(3, 'H');
    pq.enqueue(3, 'I');

    // Display the priority queue
    cout << "\nDisplaying the Priority Queue:\n";
    pq.display();

    // Dequeue elements and display the queue after each operation
    pq.dequeue(2);
    cout << "\nAfter dequeuing from row 3:\n";
    pq.display();

    pq.dequeue(3);
    cout << "\nAfter dequeuing from row 4:\n";
    pq.display();

    return 0;
}


