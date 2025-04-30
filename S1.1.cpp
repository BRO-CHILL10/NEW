#include<iostream>
using namespace std;
int main()
{
    int i,f=0;
    string s;

        getline(cin,s);

     for(i=0;i<s.size();i++)
    {
       if(s[i]!=s[s.size()-1-i])
           {
               f=1;
               break;
    }

}    if(f==0)
     {
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    return 0;
}
