#include <iostream>
#include <string>
//a~ z
int main(){
    std::string inp;
    int second = 0;

    std::cin >> inp;
    for(int i = 0; i < inp.length(); i++){
        int num = inp[i] - 'A';
        if(num < 15){
            second += num/3 + 3;
        }else if(num >= 15 && num <=18 ){
            second += 8;
        }else if(num > 18 && num <= 21){
            second += 9;
        }else{
            second += 10;
        }
    }

    std::cout << second << "\n";
    return 0;
}