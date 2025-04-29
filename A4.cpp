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
        if(arr[i]<=10)
        {

            cout<<"Arr["<<i<<"]"<<arr[i]<<endl;

        }
    }
    return 0;
}
