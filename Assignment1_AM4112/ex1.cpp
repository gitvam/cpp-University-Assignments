#include <iostream>
#include <ctype.h>
using namespace std;
int main() {

    int arithmosMathimatwn;
    float grade,sum,average;

    cout<<"Number of courses."<<endl;
    cin>>arithmosMathimatwn;

    while(arithmosMathimatwn<=0)
    {
        cout<<"This choice was not too clever,\nyou can try again though:"<<endl;
        cin>>arithmosMathimatwn;

    }

    float array[arithmosMathimatwn];

    for(int i=0; i<arithmosMathimatwn; i++)
    {
        cout<<"Course's grade."<<endl;
        cin>>grade;
        while(grade<5 || grade>10)
        {
            cout<<"Impossible grade of a passed course,\nso try again:"<<endl;
            cin>>grade;
        }
        array[i]=grade;
    }

    for(int j=0; j<arithmosMathimatwn; j++)
    {
        sum+=array[j];
    }

    average = sum/arithmosMathimatwn;
    cout<<"You GPA is: "<<average<<endl;

    if(average>=5 && average<7.5)cout<<"Pass"<<endl;
    if(average>=7.5 && average<8.5)cout<<"Pass with Credit"<<endl;
    if(average>=8.5 && average<=10)cout<<"Pass with Distinction"<<endl;

    return 0;
}