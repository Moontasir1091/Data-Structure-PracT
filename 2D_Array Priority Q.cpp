#include<bits/stdc++.h>
using namespace std;

#define ROWS 4
#define COL 5

class Priority_Q_2D
{
private:
    char queue[ROWS][COL];   /// Declaring 2D Array
    int front[ROWS];
    int rear[ROWS];

public:
    Priority_Q_2D()
    {
        for(int i=0; i<ROWS; ++i)
        {
            front[i] = -1;
            rear[i] = -1;
        }
    }


    bool isEmpty(int row)
    {
        return front[row] == -1;
    }

    bool isFull(int row)
    {
        return rear[row]==COL-1;
    }


    void Enqueue(int row, char value)
    {
        if(isFull(row))
        {
            cout << "Row " << row+1 << " is Full" << endl;
            return;
        }

        if(isEmpty(row))
        {
            front[row] = 0;
        }

        rear[row] = (rear[row] + 1)%COL;
        queue[row][rear[row]] = value;

        cout << "Enqueued " << value << "  to row " << row+1 << endl;


    }



    void Dequeued(int row)
    {

        if(isEmpty(row))
        {
            cout << "Row " << row+1 << " is Empty" << endl;
        }



        cout << "Dequeued " << queue[row][front[row]] << " from row" << row+1 << endl;


        if(front[row]==rear[row])
        {
            front[row] = rear[row] = -1;
        }
        else
        {
            front[row] = (front[row]+1)% COL;
        }
    }

    void display()
    {
        for(int i=0; i<ROWS; ++i)
        {
            if(!isEmpty(i))
            {
                cout << "Row " << i+1 << " ";
                int j = front[i];
                while(true)
                {

                    cout << queue[i][j] << " ";
                    if(j == rear[i])break;
                    j = (j+1)%COL;
                }
                cout << endl;
            }
            else
            {
                cout << "Row " << i+1 << "Empty" << endl;
            }
        }
    }

};


int main()
{
    Priority_Q_2D obj;
    obj.Enqueue(0,'A');
    obj.Enqueue(1,'B');
    obj.Enqueue(1,'C');
    obj.Enqueue(1,'D');
    obj.Enqueue(2,'E');
    obj.Enqueue(3,'F');
    obj.Enqueue(3,'G');

    obj.display();

    obj.Dequeued(1);
    obj.Dequeued(1);
    obj.display();








}





















