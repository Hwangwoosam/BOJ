#include <iostream>
#include <vector>

#define Mod 1000000007
typedef std::vector<std::vector<long long>> Matrix;


Matrix operator *(Matrix& a,Matrix& b){
    Matrix tmp(2, std::vector<long long>(2));
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                tmp[i][j] += a[i][k] * b[k][j];
            }
            tmp[i][j] %= Mod;
        }
    }

    return tmp;
}


long long N;

int main(){
    std::cin >> N;
    
    Matrix init = {{1,1},{1,0}};
    Matrix result = {{1,0},{0,1}};

    while(N > 0){
        if(N%2 == 1){
            result = result * init;
        }

        init = init*init;
        N /= 2;
    }

    std::cout << result[0][1] << "\n";
    return 0;
}