#include<iostream>
using namespace std;

#define MAX 5

class queue
{
private:
    int a[MAX];
    int front, rear;

public:

    queue()
    {
        front = -1;
        rear = -1;
    }

    int empty()
    {
        if(front == -1)
            return 1;
        else
            return 0;
    }

    int full()
    {
        if(rear == MAX - 1)
            return 1;
        else
            return 0;
    }

    void enqueue(int x)
    {
        if(rear == -1)
            front = 0;

        rear++;
        a[rear] = x;
    }

    int dequeue()
    {
        int x = a[front];

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }

        return x;
    }

    int peek()
    {
        return a[front];
    }

    void display()
    {
        for(int i = front; i <= rear; i++)
            cout << a[i] << "\t";
    }
};

int main()
{
    queue q;

    if(!q.full())
        q.enqueue(10);
    else
        cout << "queue is full" << endl;

    cout << "queue contents after enqueue operation: " << endl;
    q.display();

    if(!q.full())
        q.enqueue(20);
    else
        cout << "queue is full" << endl;

    cout << "queue contents after enqueue operation: " << endl;
    q.display();

    if(!q.full())
        q.enqueue(30);
    else
        cout << "queue is full" << endl;

    cout << "queue contents after enqueue operation: " << endl;
    q.display();

    if(!q.full())
        q.enqueue(40);
    else
        cout << "queue is full" << endl;

    cout << "queue contents after enqueue operation: " << endl;
    q.display();

    if(!q.full())
        q.enqueue(50);
    else
        cout << "queue is full" << endl;

    cout << "queue contents after enqueue operation: " << endl;
    q.display();

    if(!q.full())
        q.enqueue(60);
    else
        cout << "queue is full" << endl;

    cout << "queue contents after enqueue operation: " << endl;
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
            cout << "dequeued out element is " << q.dequeue() << endl;
        }

        cout << "queue contents after dequeue operation: " << endl;

        if(!q.empty())
            q.display();
        else
            cout << "queue is empty" << endl;
    }

    return 0;
}
/*PS D:\Siddhant Jadhav> cd 'd:\Siddhant Jadhav\output'
PS D:\Siddhant Jadhav\output> & .\'stack_using_linkdlist.exe'
30
20
10
top element is 30
removed element is 30
20
10
stack underflow
PS D:\Siddhant Jadhav\output> cd 'd:\Siddhant Jadhav\output'
PS D:\Siddhant Jadhav\output> & .\'queue_using_linkedlist.exe'
queue contents after enqueue operation: 
10      queue contents after enqueue operation: 
10      20      queue contents after enqueue operation: 
10      20      30      queue contents after enqueue operation: 
10      20      30      40      queue contents after enqueue operation: 
10      20      30      40      50      queue is full
queue contents after enqueue operation: 
10      20      30      40      50      dequeued out element is 10
queue contents after dequeue operation: 
20      30      40      50      dequeued out element is 20
queue contents after dequeue operation: 
30      40      50      dequeued out element is 30
queue contents after dequeue operation: 
40      50      dequeued out element is 40
queue contents after dequeue operation: 
50      dequeued out element is 50
queue contents after dequeue operation: 
queue is empty
queue is empty
queue contents after dequeue operation: 
queue is empty
PS D:\Siddhant Jadhav\output> */