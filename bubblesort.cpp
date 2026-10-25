#include<iostream>
using namespace std;
void bubblesort(int a[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter number of element:";
    cin>>n;
    int a[n];
    cout<<"Enter"<<n<<"element:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bubblesort(a,n);
    cout<<"sorted array:";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;

}

/*PS D:\Anjali Bhakare> g++ bubblesort.cpp -o out
PS D:\Anjali Bhakare>  ./out                   
Enter number of element:5 
Enter5element:23
56
89
74
12
sorted array:12 23 56 74 89 */