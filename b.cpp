#include <iostream>
using namespace std;

int main() {


     int x;
     float y,total;
     cin>>x;
     cin>>y;

     if(x==1)
     {
         total=(y*4.00);
     }
    else if(x==2)
     {
         total=(y*4.50);
     }


        else if(x==3)
     {
         total=(y*5.00);
     }
          else if(x==4)
     {
         total=(y*2.00);
     }
      else if(x==5)
     {
         total=(y*1.50);
     }

     cout<<total;




    return 0;
}
