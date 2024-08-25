#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    long long n,a,b,c,d;
    // num : a, value: b
    // num : c, value: d

    cin >> n >> a >> b >> c >> d;
    long long ans = 1e18;
    // b/a > d/c 한송이 당 가격
    if (b * c > d * a) {
        swap(a, c);
        swap(b, d);
    }

    for(int i = 0; i < a; i++){
        long long left = n - i*c;
        long long cnt = left > 0 ? (left-1)/a+1 : 0;
        ans = min(ans,cnt*b + i*d);
    }

    cout << ans << "\n";
    return 0;
}