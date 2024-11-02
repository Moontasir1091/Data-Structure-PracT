#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    node* next;
};

class Linked_list_PQ
{
private:
    node* front[4];
    node* rear[4];

public:
    Linked_list_PQ()
    {
        for(int i=0; i<4; ++i)
        {
            front[i] = nullptr;
            rear[i] = nullptr;
        }
    }


    bool isEmpty(int row)
    {
        return front[row]==nullptr;
    }

    void ENQ(int row, char data)
    {
        node* temp = new node;
        temp->data = data;
        temp->next = nullptr;


        if(isEmpty(row))
        {
            front[row] = rear[row] = temp;
        }

        else
        {

            rear[row]->next = temp;
            rear[row] = temp;
        }

        cout << "Enqueued " << data << " to row" << row+1 << endl;

    }


    void DEQ(int row)
    {

        if(isEmpty(row))
        {
            cout << "Row " << row + 1 << " is empty";
            return;
        }
        node* temp = front[row];
        cout << "Dequeued " << temp->data << " from row " << row+1;
        front[row] = front[row]->next;
        if(front[row]==nullptr)
        {
            rear[row]=nullptr;
        }

        delete temp;
    }


    void display()
    {
        for(int i=0; i<4; ++i)
        {
            if(!isEmpty(i))
            {
                cout << "Row " << i+1 << ": ";
                node* current = front[i];
                while(current!=NULL)
                {
                    cout << current->data << " ";
                    current = current->next;
                }
                cout << endl;
            }
                else
                {
                    cout << "Row " << i+1 << " is Empty" << endl;
                }

        }
    }

    ~Linked_list_PQ() {
        // Destructor to free all nodes in the priority queue
        for (int i = 0; i < 4; ++i) {
            while (!isEmpty(i)) {
                DEQ(i);
            }
        }
    }



};

int main() {
    Linked_list_PQ pq;

    // Enqueue elements into different rows
    pq.ENQ(0, 'A');
    pq.ENQ(1, 'B');
    pq.ENQ(1, 'C');
    pq.ENQ(1, 'D');
    pq.ENQ(2, 'E');
    pq.ENQ(2, 'F');
    pq.ENQ(3, 'G');
    pq.ENQ(3, 'H');
    pq.ENQ(3, 'I');

    // Display the priority queue
    cout << "\nDisplaying the Priority Queue:\n";
    pq.display();

    // Dequeue elements and display the queue after each operation
    pq.DEQ(2);
    cout << "\nAfter dequeuing from row 3:\n";
    pq.display();

    pq.DEQ(3);
    cout << "\nAfter dequeuing from row 4:\n";
    pq.display();

    return 0;
}
