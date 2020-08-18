#include <iostream>
#include <string>

using namespace std;


bool isPalindrome(string str, int arxi, int telos)
{
    //gia enan xaraktira isxuei, ara true
    if (arxi == telos)
    {
       return true;
    }
    //An o prwtos kai o teleutaios xaraktiras den tairiazoun
    if (str[arxi] != str[telos])
    {
       return false;
    }
    //an tairiazoun, anadromi gia ta upoloipa
    if (arxi < telos+1)
    {
       return isPalindrome(str, arxi+1, telos-1);
    }

    return true;
}

int main()
{
    string str;
    cout<<"Enter the string you want to check"<<endl;
    cin>>str;
    int mhkos = str.length();
    while(mhkos==0){
        cout<<"String can't be empty, try again"<<endl;
        cin>>str;
    }

    if (isPalindrome(str, 0, mhkos-1)) //an einai true h isPalindrome
    {
      cout<<"Palindrome"<<endl;;
    }
    else  //an den einai true h isPalindrome
    {
       cout<<"!Palindrome"<<endl;
    }
    return 0;
}
