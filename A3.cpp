#include<iostream>
using namespace std;
int main()
{
    int i,n,arr[100000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
        for(i=0;i<n;i++)
    {
       if(arr[i]>0)
       {
           arr[i]=1;
           cout<<arr[i];
       }
       else if (arr[i]==0){
           arr[i]=0;
           cout<<arr[i];


       }
       else if(arr[i]<<0)
       {
           arr[i]=2;
           cout<<arr[i];
       }
    }
    return 0;
}
