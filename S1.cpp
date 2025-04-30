#include<iostream>
using namespace std;
int main()
{
    int i;
    string s,s1;

        getline(cin,s);

     for(i=s.length()-1;i>=0;i--)
    {
       s1=s1+s[i];
    }

    if (s==s1)
    {
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 0;
}
