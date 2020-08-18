#include <iostream>

using namespace std;

int power( int vasi,int ekthetis)
{
    if (ekthetis == 1){ //an einai assos o ekthetis epistrefoume th vasi
        return vasi;
    }
    else{
      return (vasi * power(vasi, ekthetis-1)); //alliws anadromi mexri na mpoume stin panw if
    }

}

int main()
{
    //dhlwseis metavlitwn kai inputs
    int vasi,ekthetis;
    cout<<"Enter base"<<endl;
    cin>>vasi;
    cout<<"Enter exponent"<<endl;
    cin>>ekthetis;
    cout<<"Result\n"<<power(vasi,ekthetis)<<endl;
    return 0;
}
