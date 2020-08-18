#include "std_lib_facilities.h"
#include <iostream>
#include <fstream>

class rMembers{
protected:
  string name;
  int am;
public:

  void setname(string s){
    name = s;
  }
  void setam(int a){
    am = a;
  }
  string getname(){
    return name;
  }
  int getam(){
    return am;
  }
};

int main() {
    ifstream file1;
    ofstream file2;
    string word;
    rMembers obj[50];
    int noumero,cnt=0;
    file1.open("RegisteredMembers.txt");
    file2.open("votes.txt");
    vector<int> num;
    vector<string> member;
    while (file1 >> word >> noumero)
    {
        member.push_back(word);
        num.push_back(noumero);
        cnt++;

    }

    for(int i=0; i<num.size(); i++){
      obj[i].setname(member[i]);
      obj[i].setam(num[i]);
      cout << obj[i].getam() << endl;
    }
  
    file1.close();

    cout << "Input am" << endl;
    char choice;
    int times=0,inam;
    cin >> inam;

    while(inam != 0){
    for(int j=0; j<50; j++){
      if(num[j] == inam ){
        while(times<3 && choice != '0'){
          cout<< "Α: The blue pepper\nB: Picasso’s Birth\nC: Lost in Vegas\nD: The Berlin Booth\nE: Queen Paradise\nF: Geneva Adventures"<<endl;
          cin >> choice;
          if(choice!='A'&&choice!='B'&&choice!='C'&&choice!='D'&&choice!='E'&&choice!='F'){
            cout<< "Α: The blue pepper\nB: Picasso’s Birth\nC: Lost in Vegas\nD: The Berlin Booth\nE: Queen Paradise\nF: Geneva Adventures"<<endl;
            cin >> choice;
          }
          file2<<choice;
          file2<<"\n";
          times++;
        }

      }
    }
    cout << "Input am" << endl;
    cin>>inam;
  }
  file2.close();
    return 0;
}
