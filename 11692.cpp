#include <iostream>
#include <cmath>

using namespace std;

// 1 + 3 + 9 + 27 = 40 -> 3^3
// 1 + 3 + 9 + 27 + 81 = 121 --> 3^4 
// 5^2* 2
//(1+2)(1+5+25) = 
// 1  = 0
// 1 2  = 0
// 1 2 3 = 1
// n= 10 , 1 2 3 4 5 6 7 8 9 10
// 3    5   6   7   10
// 1*3 1*5 2*3 1*7  2*5
// 10 - 3 - 2 = 5;
int main(){
    long long m;
    cin >> m;


    long long ans = m - floor(sqrt(m)) - floor(sqrt(m/2));
    cout << ans << "\n";
    return 0;
}