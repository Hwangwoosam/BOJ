#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

long long modPow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

long long modMul(long long a,long long b){
    return (a*b)%MOD;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
        }
    }

    long long ans = 1;

    long long div = 1;
    for(int i = 0; i < n; i++){
        ans = (ans * (2*n - i)) % MOD;
        ans = (ans*modPow(i+1,MOD-2)) % MOD;
    }

    cout << ans << " " << n*n << "\n";
    return 0;
}