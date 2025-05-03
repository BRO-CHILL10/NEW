#include<iostream>
using namespace std;
int main()
{
    int i,n,a[100000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int mini=a[0];

    for(i=0;i<n;i++)
    {
        if(mini>a[i])
        {
            mini=a[i];
        }

    }

    int c=0;
    for(i=0;i<n;i++)
    {
        if(mini==a[i])
        {
            c++;
        }
    }
   if(c%2==0)
   {
       cout<< "unlucky";
   }
   else {
    cout<<"lucky";
   }


    return 0;

}
