#include <iostream>

using namespace std;

#define mod 10007;

int combi[1001][1001];

int main(){
    for(int i = 1; i <= 1000; i++){
        combi[i][0] = 1, combi[i][i] = 1;
        for(int j = 1; j < i; j++){
            combi[i][j] = (combi[i-1][j] + combi[i-1][j-1]) % mod;
        }
    } 
    int n,k;
    cin >> n >> k;
    cout << combi[n][k] << "\n";

    return 0;
}