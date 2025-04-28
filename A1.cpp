#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--){
   int i,mx,n,a[100000];
   cin>>n;
   for(i=0;i<n;i++)
   {
       cin>>a[i];
   }
   mx=a[0];
    for(i=0;i<n;i++)
   {
       if(a[i]>mx){
       mx=a[i];
   }}
   cout<<mx<<endl;
    }

   return 0;
}

