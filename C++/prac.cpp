#include <iostream>
#include <string>
using namespace std;

int main(){
    char ch[100];
    string a = "I wanna go to bed";
    strcpy(ch,a.c_str());

    cout<<ch<<endl;
}