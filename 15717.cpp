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
    else if(n == 0) return 1;

    long long ret = (getNumber(n/2)%MOD);
    if(n%2 == 0) return (ret*ret)%MOD;
    else return (ret*ret*2)%MOD;
}

int main(){
    long long n;
    cin >> n;
    n = n != 0 ? n-1 : 0;
    long long ans = getNumber(n);

    cout << ans << "\n";

    return 0;
}