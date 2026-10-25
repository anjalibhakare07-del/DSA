#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=NULL;

    }
};

class stack{
    private:
    node *top;
    public:
    stack()
    {
        top=NULL;
    }

    int empty()
    {
        if(top==NULL)
        return(1);
        else
        return(0);
     }
     void push(int x)
     {
        node *p=new node(x);
        p->next=top;
        top=p;

     }
     int pop()
     {
        if(empty())
        {
            cout<<"stack underflow"<<endl;
            return(-1);
        }
        int x=top->data;
        node *p=top;
        top=top->next;
        delete p;
        return(x);

     }
     void display()
     {
        node *p=top;
        while(p!=NULL)
        {
            cout<<p->data<<endl;
            p=p->next;
        }
     }
     int peek()
     {
        if(empty())
        {
            cout<<"stack underflow"<<endl;
            return(-1);
        }
        return(top->data);

     }

};
int main()
{
    stack s;
    int x;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    x=s.peek();
    cout<<"top element is "<<x<<endl;
    x=s.pop();
    cout<<"removed element is "<<x<<endl;
    s.display();

    s.pop();
    s.pop();
    s.pop();   //stack underflow
     
    return 0;
}
/*PS D:\Anjali Bhakare> cd 'd:\Anjali Bhakare\output'
PS D:\Anjali Bhakare\output> & .\'stack_using_linkdlist.exe'
30
20
10
top element is 30
removed element is 30
20
10
stack underflow
PS D:\Anjali Bhakare\output> */



    


