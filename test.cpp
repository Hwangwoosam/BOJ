#include <iostream>

int main(){
    int num;
    int cnt = 0;
    std::cin >> num;
    if(num < 100){
        cnt = num;
    }else{
        cnt = 99;
    }
    
    for(int i = 100; i <= num; i++){
        int h,t,o;
        h = i / 100;
        t = (i/10)%10;
        o = i % 10;
        if((h-t) == (t-o)){
            cnt++;
        }
    }
    
    std::cout << cnt << "\n";
    return 0;
}