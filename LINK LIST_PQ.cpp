#include <bits/stdc++.h>
using namespace std;

struct node {
    char data;
    node* next;
};

class Link_listPQ {
private:
    node* front[4];
    node* rear[4];

public:
    Link_listPQ() {
        for (int i = 0; i < 4; ++i) {
            front[i] = nullptr;
            rear[i] = nullptr;
        }
    }

    bool isEmpty(int row) {
        return front[row] == nullptr;
    }

    void Enqueue(int row, char val) {
        node* temp = new node;
        temp->data = val;
        temp->next = nullptr;

        if (isEmpty(row)) {
            front[row] = rear[row] = temp;
            rear[row]->next = front[row];  // Make it circular
        } else {
            rear[row]->next = temp;
            rear[row] = temp;
            rear[row]->next = front[row];  // Maintain circular link
        }
    }

    void Dequeue(int row) {
        if (isEmpty(row)) {
            cout << "Queue is Empty for row " << row << endl;
            return;
        }

        node* temp = front[row];

        // If there's only one node, set front and rear to nullptr
        if (front[row] == rear[row]) {
            front[row] = rear[row] = nullptr;
        } else {
            front[row] = front[row]->next;
            rear[row]->next = front[row];  // Maintain circular link
        }

        delete temp;
    }

    void Display() {
        for (int i = 0; i < 4; ++i) {
            if (isEmpty(i)) {
                cout << "Queue is Empty for row " << i << endl;
                continue;
            }

            node* curr = front[i];
            do {
                cout << curr->data << " ";
                curr = curr->next;
            } while (curr != front[i]);  // Stop when we loop back to the front
            cout << endl;
        }
    }

    ~Link_listPQ() {
        for (int i = 0; i < 4; ++i) {
            while (!isEmpty(i)) {
                Dequeue(i);
            }
        }
    }
};

int main() {
    Link_listPQ o1;
    o1.Enqueue(0, 'A');
    o1.Enqueue(0, 'B');
    o1.Enqueue(1, 'C');
    o1.Enqueue(1, 'D');
    o1.Enqueue(2, 'E');
    o1.Enqueue(3, 'F');
    o1.Display();

    return 0;
}
