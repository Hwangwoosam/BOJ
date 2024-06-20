#include <iostream>

using namespace std;

#define MOD 1000000007

long long k,p,n;

long long calc(long long cnt){
    if(cnt == 1) return p;

    long long result = calc(cnt/2);
    result = result*result % MOD;

    if(cnt%2 == 1){
        result = (result*p) % MOD;
    }

    return result;
}

int main(){
    cin >> k >> p >> n;
    long long answer = (calc(10*n) * k) % MOD;

    cout << answer << "\n";

    return 0;
}