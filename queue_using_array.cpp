
#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class queue
{
private:
    node *front, *rear;

public:
    queue()
    {
        front = NULL;
        rear = NULL;
    }

    int empty()
    {
        return front == NULL;
    }

    void enqueue(int x)
    {
        node *newnode = new node(x);

        if(front == NULL)
        {
            front = rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }

    int dequeue()
    {
        if(empty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }

        node *temp = front;
        int x = temp->data;

        front = front->next;

        if(front == NULL)
            rear = NULL;

        delete temp;
        return x;
    }

    int peek()
    {
        if(empty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }

        return front->data;
    }

    void display()
    {
        if(empty())
        {
            cout << "queue is empty" << endl;
            return;
        }

        node *temp = front;

        while(temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    queue q;

    q.enqueue(10);
    cout << "queue contents after enqueue operation:" << endl;
    q.display();

    q.enqueue(20);
    cout << "queue contents after enqueue operation:" << endl;
    q.display();

    q.enqueue(30);
    cout << "queue contents after enqueue operation:" << endl;
    q.display();

    q.enqueue(40);
    cout << "queue contents after enqueue operation:" << endl;
    q.display();

    q.enqueue(50);
    cout << "queue contents after enqueue operation:" << endl;
    q.display();

    q.enqueue(60);
    cout << "queue contents after enqueue operation:" << endl;
    q.display();

    // Dequeue operations
    for(int i = 0; i < 6; i++)
    {
        if(q.empty())
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            cout << "dequeued out element is "
                 << q.dequeue() << endl;
        }

        cout << "queue contents after dequeue operation:" << endl;
        q.display();
    }

    return 0;
}
/*PS C:\Users\Students> cd 'd:\Siddhant Jadhav\output'
PS D:\Siddhant Jadhav\output> & .\'queue_using_array.exe'
queue contents after enqueue operation:
10
queue contents after enqueue operation:
10      20
queue contents after enqueue operation:
10      20      30
queue contents after enqueue operation:
10      20      30      40
queue contents after enqueue operation:
10      20      30      40      50
queue contents after enqueue operation:
10      20      30      40      50      60
dequeued out element is 10
queue contents after dequeue operation:
20      30      40      50      60
dequeued out element is 20
queue contents after dequeue operation:
30      40      50      60
dequeued out element is 30
queue contents after dequeue operation:
40      50      60
dequeued out element is 40
queue contents after dequeue operation:
50      60
dequeued out element is 50
queue contents after dequeue operation:
60
dequeued out element is 60
queue contents after dequeue operation:
queue is empty
PS D:\Siddhant Jadhav\output> */