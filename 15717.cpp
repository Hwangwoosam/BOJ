#include <iostream>

using namespace std;

#define MOD 1000000007

/*
n = 1 : 1
n = 2 : 2
n = 3 : 4
*/


long long getNumber(long long n){
    if(n == 1) return 2;

    long long ret = (getNumber(n/2)%MOD);
    if(n%2 == 0) return (ret*ret)%MOD;
    else return (ret*ret*2)%MOD;
}

int main(){
    long long n;
    cin >> n;
    long long ans = getNumber(n-1);

    cout << ans << "\n";

    return 0;
}