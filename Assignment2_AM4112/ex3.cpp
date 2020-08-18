#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main(int argc,char* argv[])
{
    ifstream file1,file2;
    string word1,word2,filename;
    vector <string> vector;
    file1.open(argv[1]);  //anoigoume to file me to onoma tou prwtou argument
    while (file1 >> word1)  //pairnoume mia mia leksi ap to file
    {
        vector.push_back(word1+" ");  //apothikeuoume sto vector
    }
    file1.close();
    file2.open(argv[2]);  //anoigoume to file me to onoma tou deuterou argument
    while (file2 >> word2)  //pairnoume mia mia leksi ap to file
    {
        vector.push_back(word2+" ");  //apothikeuoume sto vector
    }

    file2.close();
    sort(vector.begin(), vector.end());  //kaloume surnartisi sort gia na taksinomisei to vector

    ofstream newFile;
    newFile.open("output.txt");
    for(int i=0; i<vector.size(); i++)newFile<<vector[i];  //vazoume ena ena sto file ta periexomena tou vector
    newFile.close();

    return 0;
}
