// 1050 String Subtraction
#include<iostream>
#include<vector>
#include<string>
using namespace std;

string ign, s;
bool involved[256];

int main(){
    getline(cin, s);
    getline(cin, ign);
    for (char c: ign)
        involved[c] = true;
    for (char c:s)
        if (!involved[c])
            cout << c;
}