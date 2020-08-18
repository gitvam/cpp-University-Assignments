#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    float healthCharacter,armorCharacter,damageCharacter,criticalChanceCharacter,healthBoss,armorBoss,damageBoss,criticalChanceBoss;
    float criticalDamageChar,criticalDamageBoss,telikodamageChar,telikodamageBoss;
    string menu;
    int random1,random2;

    //ta apaitoumena inputs me tous katallhlous periorismous

    cout  << "healthCharacter"<<endl;
    cin >>healthCharacter;
    while(healthCharacter<=0){
      cout<<"This cant be <=0, input new value"<<endl;
      cin>>healthCharacter;
    }

    cout  << "armorCharacter"<<endl;
    cin >>armorCharacter;
    while(armorCharacter>50 || armorCharacter<=0){
      cout<<"This cant be >50, input new value"<<endl;
      cin>>armorCharacter;
    }

    cout  << "damageCharacter"<<endl;
    cin >>damageCharacter;
    while(damageCharacter<=0){
      cout<<"This cant be <=0, input new value"<<endl;
      cin>>damageCharacter;
    }

    cout  << "criticalChanceCharacter"<<endl;
    cin >>criticalChanceCharacter;
    while(criticalChanceCharacter>50 || criticalChanceCharacter <=0){
      cout<<"This cant be >50 or <=0, input new value"<<endl;
      cin>>criticalChanceCharacter;
    }

    cout  << "healthBoss"<<endl;
    cin >>healthBoss;
    while(healthBoss<=0){
      cout<<"This cant be <=0, input new value"<<endl;
      cin>>healthBoss;
    }

    cout  << "armorBoss"<<endl;
    cin >>armorBoss;
    while(armorBoss>50 || armorBoss<=0){
      cout<<"This cant be >50 or <=0, input new value"<<endl;
      cin>>armorBoss;
    }

    cout  << "damageBoss"<<endl;
    cin >>damageBoss;
    while(damageBoss<=0){
      cout<<"This cant be <=0, input new value"<<endl;
      cin>>damageBoss;
    }

    cout  << "criticalChanceBoss"<<endl;
    cin >>criticalChanceBoss;
    while(criticalChanceBoss>50 || criticalChanceBoss<=0){
      cout<<"This cant be >50 or <=0, input new value"<<endl;
      cin>>criticalChanceBoss;
    }


    random1 =(rand() %100)+1 ; //random apo 1-100
    random2 =(rand() %100)+1 ;
    criticalDamageChar = damageCharacter * 1.2;  //o tupos pou dinetai gia to critdmg tou kathena
    criticalDamageBoss = damageBoss * 1.2;

    cout<<"Menu\n1.Next round(type next)\n2.Display stats(type stats)"<<endl;
    cin >> menu;

    while(healthCharacter >= 0 && healthBoss >= 0) { //oso den einai nekroi

        if (menu == "next") {
            if(criticalChanceCharacter >= random1){         //edw exoume critical gia character
                telikodamageChar = criticalDamageChar * (1-(armorBoss/100));
                healthBoss = healthBoss - telikodamageChar;

            }else{                                          //edw den exoume critical gia character
                telikodamageChar = damageCharacter * (1-(armorBoss/100));
                healthBoss = healthBoss - telikodamageChar;
            }
            if(criticalChanceBoss >= random2){              //exoume critical gia boss
                telikodamageBoss = criticalDamageBoss * (1-(armorCharacter/100));
                healthCharacter = healthCharacter - telikodamageBoss;
            }else{                                          //den exoume critical gia boss
                telikodamageBoss = damageBoss * (1-(armorCharacter/100));
                healthCharacter = healthCharacter - telikodamageBoss;
            }

            cout<<"Menu\n1.Next round(type next)\n2.Display stats(type stats)"<<endl;
            cin >> menu;
        } else if (menu == "stats") {  //ta prints twn stats
            cout<<"Boss Health: "<< healthBoss <<endl;
            cout<<"Character Health: "<< healthCharacter <<endl;
            cout<<"Boss armor: "<< armorBoss <<endl;
            cout<<"Character armor: "<< armorCharacter <<endl;
            cout<<"Boss critical chance: "<< criticalChanceBoss<< "%" <<endl;
            cout<<"Character critical chance: "<< criticalChanceCharacter<< "%" <<endl;
            cout<<"Boss final damage: "<< telikodamageBoss <<endl;
            cout<<"Character final damage: "<< telikodamageChar <<endl;
            cout<<"Menu\n1.Next round(type next)\n2.Display stats(type stats)"<<endl;
            cin >> menu;
        } else {
            cout << "Option not available" << endl;
            cout<<"Menu\n1.Next round(type next)\n2.Display stats(type stats)"<<endl;
            cin >> menu;
        }
    }

    //elegxoi gia to poios h poioi pethanan
    if(healthCharacter <= 0 && healthCharacter <= 0 )cout<<"They both died"<<endl;
    else if(healthBoss <= 0 && healthCharacter>0 )cout<<"Boss died"<<endl;
    else if(healthCharacter <= 0 && healthBoss>0 )cout<<"Character died"<<endl;

    return 0;
}
