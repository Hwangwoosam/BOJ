#include <iostream>

using namespace std;

int main(){
    int a,b;

    cin >> a >> b;

    int result = a*(100 - b);
    if(result >= 10000){
        cout << "0\n";
    }else{
        cout << "1\n";
    }

    return 0;
}