#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

//Base class
class Vehicle
{
protected:
    int speed;
    int acceleration;
    string name;
public:
    void setSpeed(int s){
        speed = s;
    }
    void setAcceleration(int a){
        acceleration = a;
    }
    void setName(string n){
        name = n;
    }
     int getSpeed(){
        return speed;
    }
    int getAcceleration(){
        return acceleration;
    }
    string getName(){
        return name;
    }

    void getcharacteristics(){
        cout<<"("<<name<<","<<speed<<","<<acceleration<<")"<<endl;
    }
};

// Sub class inheriting from Base Class(Parent)
class Bike : public Vehicle
{
public:
    void setBike(){
       speed = 50;
    }
    void createBike(string onoma, int epitaxinsi){
        setBike();
        name = onoma;
        acceleration = epitaxinsi;
    }

    void getcharacteristics(){
        cout<<"("<<name<<","<<speed<<","<<acceleration<<")"<<endl;
    }
};

// Sub class inheriting from Base Class(Parent)
class Car : public Vehicle
{
protected:
    bool abs;
public:
    void setCar(){
        speed = 25;
    }
    void setAbs(bool a){
        abs = a;
    }
    bool getAbs(){
        return abs;
    }
    void createCar(string onoma, int epitaxinsi,bool a){
        setCar();
        name = onoma;
        acceleration = epitaxinsi;
        abs = a;
    }

    void getcharacteristics(){
        cout<<"("<<name<<","<<speed<<","<<acceleration<<","<<abs<<")"<<endl;
    }
};

// Sub class inheriting from Base Class(Parent)
class Bus : public Vehicle
{
protected:
    int numSeats;
public:
    void setBus(){
        speed = 5;
    }
    void setSeats(int seats){
        numSeats = seats;
    }
    int getnumSeats(){
        return numSeats;
    }
    void createBus(string onoma, int epitaxinsi,int a){
        setBus();
        name = onoma;
        acceleration = epitaxinsi;
        numSeats = a;
    }

    void getcharacteristics(){
        cout<<"("<<name<<","<<speed<<","<<acceleration<<","<<numSeats<<")"<<endl;
    }
};

//main function
int main()
{
    int start_option;
    int i=0,j=0,k=0;  //arxikopoiw tous metrites
    vector<Vehicle>skr;
    while(1) {  //kanw menu
        cout << "1.Create Bike\n2.Create Car\n3.Create Bus\n4.Delete\n5.Print\n6.Quit" << endl;
        cin >> start_option;
        if (start_option == 1) {  //create bike
            Bike obj1,obj2,obj3,obj4;
            string no_need,name;
            int acceleration;
            cout << "Type the command: newbike *name *acceleration" << endl;
            cin>>no_need>>name>>acceleration;
            if(i==0){
                obj1.createBike(name,acceleration);
                skr.push_back(obj1);
                cout<<"Object created"<<endl;
            }else if(i==1){
                obj2.createBike(name,acceleration);
                skr.push_back(obj2);
                cout<<"Object created"<<endl;
            }else if(i==2){
                obj3.createBike(name,acceleration);
                skr.push_back(obj3);
                cout<<"Object created"<<endl;
            }else if(i==3){
                obj4.createBike(name,acceleration);
                skr.push_back(obj4);
                cout<<"Object created"<<endl;
            }else{
                cout<<"Your garage is full."<<endl;
            }
            i++;
        } else if (start_option == 2) {  //create car
            string name,no_need2;
            int acceleration;
            bool abs;
            cout << "Type the command: newcar *name *acceleration *(0 or 1 for abs)" << endl;
            cin >>no_need2>>name >> acceleration >> abs;
            Car obj11,obj22,obj33,obj44;

            if(j==0){
                obj11.createCar(name,acceleration,abs);
                skr.push_back(obj11);
                cout<<"Object created"<<endl;
            }else if(j==1){
                obj22.createCar(name,acceleration,abs);
                skr.push_back(obj22);
                cout<<"Object created"<<endl;
            }else if(j==2){
                obj33.createCar(name,acceleration,abs);
                skr.push_back(obj33);
                cout<<"Object created"<<endl;
            }else if(j==3){
                obj44.createCar(name,acceleration,abs);
                skr.push_back(obj44);
                cout<<"Object created"<<endl;
            }else{
                cout<<"Your garage is full."<<endl;
            }
            j++;
        } else if (start_option == 3) {  //create bus
            string name,no_need;
            int acceleration, num_seats;
            cout << "Type the command: newbus *name *acceleration *num of seats" << endl;
            cin >>no_need>>name >> acceleration >> num_seats;
            Bus obj111,obj222,obj333,obj444;
            if(k==0){
                obj111.createBus(name,acceleration,num_seats);
                skr.push_back(obj111);
                cout<<"Object created"<<endl;
            }else if(k==1){
                obj222.createBus(name,acceleration,num_seats);
                skr.push_back(obj222);
                cout<<"Object created"<<endl;
            }else if(k==2){
                obj333.createBus(name,acceleration,num_seats);
                skr.push_back(obj333);
                cout<<"Object created"<<endl;
            }else if(k==3){
                obj444.createBus(name,acceleration,num_seats);
                skr.push_back(obj444);
                cout<<"Object created"<<endl;
            }else{
                cout<<"Your garage is full."<<endl;
            }
            k++;
        } else if (start_option == 4) {  //delete vehicle
            cout << "Type the command: delete *name" << endl;
            string name,noneed;
            cin>>noneed>>name;
            for(int lol=0; lol<skr.size(); lol++){
                if(skr.at(lol).getName()==name){
                    //an to vrei diagrafw auto pou prepei
                    skr.erase(skr.begin()+(lol-1));
                    cout<<"Object deleted"<<endl;
                }
            }
        } else if (start_option == 5) { //print vehicles
            cout<<"Type print"<<endl;
            string pipa;
            cin>>pipa;
            if(pipa=="print") {
                for (int v = 0; v < skr.size(); v++) {
                    //tupwnw ta basic xaraktiristika giati eklaige o compiler
                    //opote protimisa ap to na kanw 3 vectors
                    //kai na trexw auta me tis get/cs pou exw panw
                    //na trexw mono to geniko kai na tupwnw ta basics
                    //mias kai den dieukrinizetai stin ekfwnisi poia thelei
                    skr.at(v).getcharacteristics();
                }
            }else{
                cout<<"Not funny"<<endl;
            }
        } else if (start_option == 6) { //quit option
            return 0;
        } else {  //option not found
            cout << "Not available option,try again" << endl;
        }
    }

}
