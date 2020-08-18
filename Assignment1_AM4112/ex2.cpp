#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    vector<int> vector;
    int insert,erase,counter=0;
    std::vector<int>::iterator iterator;
    string option;
    cout<<"1.Insert to vector.(insert)\n2.Delete from vector.(delete)\n3.Display vector.(display)\n4.exit(quit)\n";
    cin >> option; //input ti theloume na kanoume
    while(option!="quit") {  //ginetai to loop oso to input den einai quit
        if (option == "insert") {
            cout << "Insert to vector" << endl;
            cin >> insert;
            vector.push_back(insert);
            cout<<"The vector right now looks like:\n";
            for (auto i = vector.begin(); i != vector.end(); ++i) cout << *i << endl;
        } else if (option == "delete") { //den douleuei h delete
            //vector erase
            cout << "Choose the number you want to erase" << endl;
            cin >> erase;
            //kwdikas gia delete
            iterator = find(vector.begin(), vector.end(), erase);
            if (iterator != vector.end()){
                cout << "Element Found" << endl;
                vector.erase(vector.begin()+distance(vector.begin(),iterator));
            }
            else cout << "Element Not Found" << endl;
            //telos kwdika gia delete
            cout<<"The vector right now looks like:\n";   //tA kAtAlLhLa PrInTs
            for (auto j = vector.begin(); j != vector.end(); ++j) cout << *j << endl;

        } else if (option == "display") {
            //print vector
            for (auto it = vector.begin(); it != vector.end(); ++it) cout << *it << endl;
        }
        cout<<"1.Insert to vector.(insert)\n2.Delete from vector.(delete)\n3.Display vector.(display)\n4.exit(quit)\n";
        cin >> option;
    }
    return 0;
}
