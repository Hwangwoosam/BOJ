#include <iostream>

using namespace std;

long long n;

// 2 1
// 3 2
// 4 2
// 5 3
// 6 3
// 7 4
// 8 4
int main(){
    cin >> n; 
    
    if(n == 1) cout << "0\n";
    else{
        long long ans = n+1 >> 1;
        cout << ans << "\n";
    }
    return 0;
}