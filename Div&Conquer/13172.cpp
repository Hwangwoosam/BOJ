#include <iostream>
#include <numeric>

long long MOD = 1000000007;
int m;

long long result;

long long mod(long long a, long long b){
    
    if(b == 1){
        return a;
    }

    if(b%2 == 1){
        return a*mod(a,b-1)%MOD;
    }

    long long p = mod(a,b/2);
    return p*p%MOD;
}

int main(){
    std::cin >> m;

    for(int i = 0; i < m; i++){
        int n,s;
        std::cin >> n >> s;
        long long g = std::gcd(s,n);
        n /= g;
        s /= g;

        result += s*mod(n,MOD-2);
        result %= MOD;
    }
    std::cout << result << "\n";
    return 0;
}