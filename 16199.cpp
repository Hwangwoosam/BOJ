#include <iostream>

using namespace std;

int uY,uM,uD;
int sY,sM,sD;

int checkAge(){
    if(sY - uY > 0){
        if(sM > uM){
            return sY-uY;
        }else if(sM == uM){
            if(sD >= uD) return sY-uY;
            else return sY-uY-1;
        }else{
            return sY-uY-1;
        }
    }

    return 0;
}

int main(){
    cin >> uY >> uM >> uD;
    cin >> sY >> sM >> sD;

    cout << checkAge() << "\n";
    cout << sY - uY + 1 << "\n";
    cout << sY - uY << "\n";
    return 0;
}