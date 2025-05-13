#include<iostream>
using namespace std;
class body
{
public:
int age,id;
void data()
{
cout<<"Enter the id = ";
cin>>id;
cout<<"Enter the age = ";
cin>>age;
cout<<endl;

}
void show()
{
cout<<"age = "<< age<<endl<<"id = "<<id<<endl;

}
/// Pre decrement :

body& operator -- ()
{
--age;
--id;
return *this;
}
body& operator ++ ()

{
++age;
++id;
return *this;
}
body operator ++ (int )
{
body temp=*this;
age++;
id++;
return temp;
}
body operator -- (int )
{
body temp=*this;
age--;
id--;
return temp;
}

};

int main()
{
body b1,b2,b3,b4;
cout<<"For B1 :-"<<endl;
b1.data();
--b1;
cout << "pre decrement :- "<<endl;
b1.show();

cout << endl;
++b1;
cout << "pre increment :-" <<endl;
b1.show();

b1--;
cout << "post decrement :- "<<endl;
b1.show();
cout << endl;
b1++;
cout << "post increment :-" <<endl;
b1.show();

}
}
