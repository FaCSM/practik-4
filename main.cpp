#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

void remove_spaces(string &str) {
    str.erase(
            unique_copy(str.begin(), str.end(), str.begin(), [](char c1, char c2) { return c1 == ' ' && c2 == ' '; }),
            str.end());
}
void remove_symbols(string &str) {
    int symbols[10] = {33,34,45,40,41,58,59,44,46,63};
    for(int i=0;i<10;i++){
        str.erase(
                unique_copy(str.begin(), str.end(), str.begin(),
                            [&symbols, &i](char c1, char c2) { return c1 == (char) symbols[i] && c2 == (char) symbols[i]; }),
                str.end());
    }
}
void RegCheck(string &str){
    str[0] = char((int)str[0]-32);
    for(int i =1;i < str.length();i++){
        if((int)str[i-1] != 32 && (int)str[i]>= 65 && (int)str[i]<=90){
            str[i] = char((int)str[i]+32);
        }
    }
    
}
void ReversOut(string &str){
    int a;
    for(int i=str.length();i>=0;i--){
        if(str[i] == ' '){
            for(int k=i + 1;k<=(i+a);k++){
                cout << str[k];
            }
            a=0;
        }
        a++;
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') break;
        cout << str[i];
    }
    cout<<endl;
}
void ColumnOut(string &str){
    for(int i = 0;i<str.length();i++){
        if((int)str[i]==32) {
            cout << endl;
            i++;
        }else{
            cout<<str[i];
        }

    }
}
int main() {
    string BaseString;
    getline(cin,BaseString,'\n');
    remove_spaces(BaseString);
    cout<<"Without spaces: "<< BaseString<<endl;
    remove_symbols(BaseString);
    cout<<"Without symbols: "<< BaseString<<endl;
    RegCheck(BaseString);
    cout<<"Register normalized: "<< BaseString<<endl;
    cout<<"Reversed fraze: ";
    ReversOut(BaseString);
    cout<<"Column out: \n";
    ColumnOut(BaseString);
}