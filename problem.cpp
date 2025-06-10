#include<iostream>
using namespace std;
int main()
{
    int t,c=0;;
    cin>>t;
    while(t--)
    {
        int arr[100000],i;
        int n=0;

        for(i=0;i<3;i++)
        {
            cin>>arr[i];
        }
         for(i=0;i<3;i++)
        {
            n+=arr[i];
        }
        if(n==2||n==3)

        {
            c++;
        }

      }
cout<<c;

    return 0;
}
