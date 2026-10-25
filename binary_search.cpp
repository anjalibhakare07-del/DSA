#include<iostream>
using namespace std;
int binary_search(int a[],int n,int x)
{
    int first,last,mid;
    first=0;
    last=n-1;
    while(first<=last)
    {
        mid=(first+last)/2;
        if(a[mid]==x) return(mid);
        else if(a[mid]<x) first=mid+1;
        else last=mid-1;
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
    int position=binary_search(a,n,x);
    if(position==-1) cout<<"Element not found";
    else cout<<"Element found at position:"<<position;
    return(0);
}

/*PS D:\Siddhant Jadhav> g++ binary_search.cpp -o out
PS D:\Siddhant Jadhav> ./out                       
How many element4
Enter4element10
20
30
40
Enter the element to be searched20
Element found at position:1*/