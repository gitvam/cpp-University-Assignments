#include "std_lib_facilities.h"

class options{
public:
  int psifoi;
  string onoma;
  void setpsifoi(int p){
    psifoi = p;
  }
  void setonoma(string n){
    onoma = n;
  }
  string getname(){
    return onoma;
  }
  int getpsifoi(){
    return psifoi;
  }
};


void bubbleSort(options numArray[]) {

    int n = 6;
    options temp;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < (n - i); j++) {

            if (numArray[j - 1].getpsifoi() < numArray[j].getpsifoi()) {
                temp = numArray[j - 1];
                numArray[j - 1] = numArray[j];
                numArray[j] = temp;
            }

        }
    }
}

int main(){
  ifstream file1;
  file1.open("votes.txt");
  string word;
  int countA=0;
  int countB=0;
  int countC=0;
  int countD=0;
  int countE=0;
  int countF=0;
  while (file1 >> word)
  {
      if(word== "A")countA++;
      else if(word== "B")countB++;
      else if(word == "C")countC++;
      else if(word == "D")countD++;
      else if(word== "E")countE++;
      else if(word== "F")countF++;
  }
 options A,B,C,D,E,F;
 A.setonoma("The blue pepper");
 A.setpsifoi(countA);
 B.setonoma("Picasso’s Birth");
 B.setpsifoi(countB);
 C.setonoma("Lost in Vegas");
 C.setpsifoi(countC);
 D.setonoma("The Berlin Booth");
 D.setpsifoi(countD);
 E.setonoma("Queen Paradise");
 E.setpsifoi(countE);
 F.setonoma("Geneva Adventures");
 F.setpsifoi(countF);

 options ruf[6];
 ruf[0] = A;
 ruf[1] = B;
 ruf[2] = C;
 ruf[3] = D;
 ruf[4] = E;
 ruf[5] = F;
 bubbleSort(ruf);
 for(int i=0; i<6; i++){
   cout << ruf[i].getname()<< ": " << ruf[i].getpsifoi()<<endl;
 }

 return 0;
}
