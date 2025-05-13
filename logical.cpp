#include<iostream>
using namespace std;
class body
{
public:
    int a,b;
    void seti()
    {
        cin>>a>>b;


    }
    body operator &&(body h)
    {
        body uno;
        uno.a=a&&h.a;
        uno.b=b&&h.b;
        return uno;


    }
    body operator || (body h)
    {
        body uno;
        uno.a=a||h.a;
        uno.b=b||h.b;
        return uno;


    }



    void show ()
    {
        a=!a;
        b=!b;

cout<< "   "<< a<<"  "<< b;

    }

};
int main()
{
    body b1,b2,b3,b4;
    b1.seti();
    b2.seti();
    b3=b1&&b2;
    b4=b1||b2;
    b3.show();
   b4.show();
    return 0;
}





