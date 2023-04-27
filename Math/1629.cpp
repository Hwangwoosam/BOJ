#include <iostream>

int A,B,C;

long long int f(long long int x){
    if(x == 1) return A%C;

    long long int k = f(x/2)%C;

    if(x%2 == 0){
        return k*k%C;
    }else{
        return k*k%C*A%C;
    }
    
}

int main(){
    std::cin >> A >> B >> C;
    // (A * B) % C

    std::cout << f(B) <<"\n";
    return 0;
} 