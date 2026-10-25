#include<iostream>
using namespace std;
int linear_search(int a[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x) return(i);
    }
    return(-1);
}
int main()
{
    int a[10],x,n;
    cout<<"How many element";
    cin>>n;
    cout<<"Enter"<<n<<"element";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the element to be searched";
    cin>>x;
    int position=linear_search(a,n,x);
    if(position==-1) cout<<"Element not found";
    else cout<<"Element found at position:"<<position;
    return(0);
}

/*PS D:\Siddhant Jadhav> g++ linear_search.cpp -o out
PS D:\Siddhant Jadhav> ./out                       
How many element 5
Enter5element 10
20
30
40
50
Enter the element to be searched 40
Element found at position:3*/