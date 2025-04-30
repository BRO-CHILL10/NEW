#include<iostream>
using namespace std;
int main()
{
    int i;
  string s,t,a;
  cin>>s;
  cin>>t;
  for(i=0;i<max(s.size(),t.size());i++){
  a+=s[i];
  a+=t[i];

  }
  cout <<a;
    return 0;
}
