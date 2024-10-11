#include <iostream>
#include <climits>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;

    if(c*b > a*d){
        swap(a,c);
        swap(b,d);
    }

    long long ans = LONG_MAX;
    long long cCnt = a;
    while(cCnt--){
        long long aCnt = (n-cCnt*c)/a; 
        if(aCnt < 0) continue;
        aCnt = (n-cCnt*c)%a > 0 ? aCnt+1 : aCnt;
        long long curPrice = aCnt*b + cCnt*d;

        ans = min(ans, curPrice);
    }
    cout << ans << "\n";

    return 0;
}