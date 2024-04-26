#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n,k;

    while(!cin.eof() && cin >> n >> k){
        long long res = 1;

        for(int i = 2; i*i <= k; i++){
            int primeK = 0;
            while(k % i == 0){
                k /= i;
                primeK++;
            }

            int primeN = 0;
            
            if(primeK > 0){
                for(int j = i; j <= n; j *= i){
                    primeN += n/j;
                }
            }

            res *= pow(i, min(primeK, primeN));
            if(k < i) break;
        }
    
        if(k > 1 && k < n) res *= k;

        cout << res << "\n";
    }
    

    return 0;
}