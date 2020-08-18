#include <iostream>

using namespace std;

int main()
{


    float posoPouDiathetei,grammariaPouThelei,numberOfToppings,price=0;
    string geusiPouDialegei,menu,toppings[2],topping;
    int counter=0;

    cout << "How much money do you want to spend?(You need at least 5$)" << endl;
    cin >> posoPouDiathetei;
    if(posoPouDiathetei<5)
    {
        cout<<"You haven't got enough money"<<endl;
        return 0;
    }

    cout << "1.Peanut butter(press b)\n2.Greek yogurt(press g)\n3.Chocolate(press c)\n4.Apple(press a)\nYou can choose only one\n";
    cin>>geusiPouDialegei;    //dialegoume geusi
    while(geusiPouDialegei != "b" && geusiPouDialegei != "g" && geusiPouDialegei != "c" && geusiPouDialegei != "a")  //edw an den uparxei h geush exoume thema
    {
        cout<<"This not an available option"<<endl;
    }

    cout << "How many grams of frozen yogurt do you want, 100g or 200g?" << endl;
    cin >> grammariaPouThelei;
    while(grammariaPouThelei!= 100 && grammariaPouThelei != 200)  //mporei na dialeksei 100g h 200g, alliws exoume thema :p
    {
        cout<<"This was not too funny, you know. Try once more"<<endl;
        cin >> grammariaPouThelei;
    }

    if(grammariaPouThelei == 100)price = 5;
    if(grammariaPouThelei == 200) price = 7.5;
    if(posoPouDiathetei < price){ //an ta xrhmata pou exei den ftanoun kovetai to programma, h idia if xrhsimopoieitai se oles tis antistoixes periptwseis
        cout<<"You have not enough money, compile again."<<endl;
        return 0;
    }
    cout<<"MENU\n1.Add topping-2$ each (type topping)\n2.Product status (type status)\n3.End your purchase (type end)"<<endl;  //gia to prwto input
    cin >> menu;

    while(menu!="end") { //otan dwsei input end spaei h while kai vgainei ap to menu
        if(menu=="topping"){
            cout << "You can either choose 1 or 2 toppings\nHow many toppings do you want?" << endl;
            cin >> numberOfToppings;
            if(numberOfToppings == 1 && counter ==0){  //prwti fora pou kanei add ena topping
                cout << "Choose topping:\n1.Brownies\n2.Fruits\n3.Nuts\n4.Cookies" << endl;
                price+=2;
                if(posoPouDiathetei < price){
                    cout<<"You have not enough money, compile again."<<endl;
                    return 0;
                }
                cin >> topping;
                toppings[0] = topping;
                counter++;
                cout<<"MENU\n1.Add topping-2$ each (type topping)\n2.Product status (type status)\n3.End your purchase (type end)"<<endl;
                cin >> menu;
            }else if(numberOfToppings == 1 && counter ==1){   //deuteri fora pou kanei add ena topping,pou einai tautoxrona kai h teleutaia
                cout << "Choose topping:\n1.Brownies\n2.Fruits\n3.Nuts\n4.Cookies" << endl;
                price+=2;
                if(posoPouDiathetei < price){
                    cout<<"You have not enough money, compile again."<<endl;
                    return 0;
                }
                cin >> topping;
                toppings[1] = topping;
                counter=3;
                cout<<"MENU\n1.Add topping-2$ each (type topping)\n2.Product status (type status)\n3.End your purchase (type end)"<<endl;
                cin >> menu;
            }else if(numberOfToppings == 2 && counter == 0){  //prwti fora pou kanei add 2 toppings, pou einai tautoxrona kai h teleutaia
                cout << "Choose topping:\n1.Brownies\n2.Fruits\n3.Nuts\n4.Cookies" << endl;
                price+=4;
                if(posoPouDiathetei < price){
                    cout<<"You have not enough money, compile again."<<endl;
                    return 0;
                }
                cin >> topping;
                toppings[0] = topping;
                cin >> topping;
                toppings[1] = topping;
                cout<<"MENU\n1.Add topping-2$ each (type topping)\n2.Product status (type status)\n3.End your purchase (type end)"<<endl;
                cin >> menu;
                counter=3;
            }else if(counter>2){  //elegxos an exoume upervei to epitrepto orio toppings
                cout << "You cannot add more toppings."<<endl;
                cout<<"MENU\n1.Add topping-2$ each (type topping)\n2.Product status (type status)\n3.End your purchase (type end)"<<endl;
                cin >> menu;
            }
        }
       else if (menu == "status") {  //ta prints tou status
            cout << "Taste: " << geusiPouDialegei << endl;
            cout << "Price: " << price <<"$"<<endl;
            cout << "Toppings: " <<toppings[0]<<" "<<toppings[1]<<endl;
            cout<<"MENU\n1.Add topping-2$ each (type topping)\n2.Product status (type status)\n3.End your purchase (type end)"<<endl;
            cin >> menu;
        } else {
            cout << "Not available option, compile again." << endl;
            return 0;
        }
    }
    //ta prints afou pathsei end
    cout << "Taste: " << geusiPouDialegei << endl;
    cout << "Price: " << price <<"$"<<endl;
    cout << "Toppings: " <<toppings[0]<<" "<<toppings[1]<<endl;  //ta toppings einai apothikeumena se ena pinaka gia eukolia
    cout << "Your change: "<< posoPouDiathetei-price <<"$"<<endl;
    cout<<"Thank you."<<endl;

    return 0;
}
