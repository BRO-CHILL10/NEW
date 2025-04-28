#include<iostream>
using namespace std;
int main()
{
    int N,X,i,A[100000];
    cin>>N>>X;
    for(i=0;i<N;i++)
    {
       cin>>A[i];

    }


    int f=0;
    for(i=0;i<N;i++)
    {
       if(X==A[i]){
        f=1;
        break;}
    }

     if(f==1)
     {
         cout<<"YES";
     }
     else {
        cout<<"NO";
     }
      return 0;
}

