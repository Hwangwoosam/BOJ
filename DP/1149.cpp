#include <iostream>
#include <algorithm>

using namespace std;

int R[1001],G[1001],B[1001];
int d[1001][3];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> R[i] >> G[i] >> B[i];
    }
    d[0][0] = R[0];
    d[0][1] = G[0];
    d[0][2] = B[0];

    for(int i = 1; i < n; i++){
        d[i][0] = min(d[i-1][1],d[i-1][2]) + R[i];
        d[i][1] = min(d[i-1][0],d[i-1][2]) + G[i];
        d[i][2] = min(d[i-1][0],d[i-1][1]) + B[i];
    }

    cout << *min_element(d[n-1],d[n-1]+3) << "\n";


    return 0;
}