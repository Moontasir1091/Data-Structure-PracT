#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

class CIRCULAR_Q
{
private:
    node* Front,*Rear;


public:
    CIRCULAR_Q()
    {
        Front = Rear = nullptr;
    }

    bool isEmpty()
    {
        return Front == nullptr;
    }

    void enQueue(int value)
    {
        node* temp = new node;
        temp->data = value;
        ///temp->next = nullptr;


        if(isEmpty())
        {
            Front = Rear = temp;
            Rear->next = Front; /// Make it Circular;
        }

        else
        {
            Rear->next = temp;
            Rear = temp;
            Rear->next = Front; /// Make it Circular;
        }

        cout << "Enqueued Value: " << value << endl;


    }


    void DEQUEUE()
    {
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int value;
        if(Front==Rear) /// Only one Element
        {
            value = Front->data;
            delete Front;
            Front = Rear = nullptr;
        }

        else
        {
            node* temp = Front;
            value = Front->data;
            Front = Front->next;
            Rear->next = Front;/// Make it Circular;
            delete temp;
        }


        cout << "Dequeued value: " << value << endl;

    }

     void DISPLAY()
    {
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        node* temp = Front;
        cout << "Queue Elements: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while(temp != Front);  /// Stop when we reach the front again (circular condition)

        cout << endl;
    }
};

int main()
{
    CIRCULAR_Q obj;
    obj.enQueue(10);
    obj.enQueue(20);
    obj.enQueue(30);
    obj.enQueue(30);
    cout << endl ;

    obj.DISPLAY();
    cout << endl << endl;

    obj.DEQUEUE();
    obj.DEQUEUE();
    obj.DEQUEUE();
    cout << endl ;

    obj.DISPLAY();




}
