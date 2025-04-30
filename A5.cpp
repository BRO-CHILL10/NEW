#include<iostream>
using namespace std;
int main()
{
    int i,arr[100000],n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int f=0;
     for(i=n-1;i>=0;i--)
    {
       if(arr[i]!=arr[n-1-i])
       {
          f=1;
          break;
       }
    }
    if (f==0)
    {
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 0;
}
