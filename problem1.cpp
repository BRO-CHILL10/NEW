#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    set<char>name;
    for(int i=0;i<s.size();i++)
    {
        name.insert(s[i]);
    }
    if(name.size()%2==0)
    {
        cout<<"female";
    }
    else{
        cout<<"male";
    }
    return 0;
}
