#include <iostream>

int n;

int main(){
    std::cin >> n;
    for(int i = 2; i <= n; i++){
        while((n%i) == 0){
            std::cout << i << "\n";
            n /= i;
        }
    }

    return 0;
}