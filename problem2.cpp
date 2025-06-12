#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[1000],i,b=0;
    set<int>a;
    for(i=0;i<4;i++)
    {
        cout<<"Enter the shoe num = ";
        cin>>arr[i];
    }
   /// set<int>a;
    for(i=0;i<4;i++)
    {
        a.insert(arr[i]);
    }
    b=4-a.size();
    cout<<"Need of shoe = "<<b;
    return 0;
}
