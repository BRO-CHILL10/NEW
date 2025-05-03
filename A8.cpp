#include<iostream>
using namespace std;
int main()
{
    int i,n,a[10000];
    cin>>n;
    int sum=0;
    for(i=0;i<n;i++)
    {
      cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
      sum+=a[i];
    }
    cout<<sum;
    return 0;
}
