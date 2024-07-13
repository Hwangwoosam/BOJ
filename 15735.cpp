#include <iostream>

using namespace std;

/*  n: 1  normal : 1 , reverse = 0
    n: 2  i = 1, normal : 3 , reverse = 1
    n: 3  normal : 6 , reverse = 3;
*/
long long arr[10001];

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    for(int i =1 ;i < 10001; i++){
        arr[i] = arr[i-1] + i;
    }

    long long ans = 0;
    for(int i = 1; i<= n; i++) ans += arr[i];
    for(int i= n-1; i >0; i-=2) ans += arr[i];

    cout << ans << "\n";
    return 0;
}