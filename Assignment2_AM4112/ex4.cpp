#include <iostream>
#include <cmath>
#include "class.cpp"
using namespace std;

int main()
{
   Vector2 c1(5,3),c2(3,1); //ftiaxnw 2 objects gia na tsekarw osa ekana kai kalw ta panta 
   cout<<"Test demo"<<endl;
   cout<<"Enter C1"<<endl;
   cin>>c1;
   cout<<"Enter C2"<<endl;
   cin>>c2;
   cout<<"C1:"<<c1;
   cout<<"C2:"<<c2;
   cout<<"MD(C1) : " <<c1.metro_dianusmatos()<<endl;
   cout<<"EG(C1,C2) : "<<c1.eswteriko_ginomeno(c2)<<endl;
   cout<<"C1*2=" << c1*2;
   cout<<"C1/2=" << c1/2;
   cout<<"C1+C2=" << c1+c2;
   cout<<"C1-C2=" << c1-c2;


   return 0;
}
