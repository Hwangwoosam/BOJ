#include <iostream>
#include <math.h>
int n,m;
int min = 0;
int sum = 0;

int main(){
    std::cin >> m >> n;

    for(int i = m; i <= n; i++){
        bool check = false;
        if(i == 1){
            continue;
        }

        for(int j = 2; j <= sqrt(i); j++){
            if((i % j)  == 0){
                check = true;
                break;
            }
        }

        if(!check){
            if(min == 0){
                min = i;
            }
            sum += i;
        }
    }

    if(sum == 0 || min == 0){
        std::cout << "-1\n";
    }else{
        std::cout << sum << "\n" << min << "\n";
    }

    return 0;
}