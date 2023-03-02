#include <iostream>
using namespace std;
int main() {
    double num;
    cin>>num;
    string binary = "0.";
    int count = 32;
    while(count--){
        num*=2;
        if(num>=1){
            num-=1;
            binary += '1';
        }else
            binary += '0';
        if(num==0)
            break;
    }
    if(num!=0)
        cout<<"error";
    else
        cout<<binary;
}
