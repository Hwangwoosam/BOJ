#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main(){
    int m,n;
    cin >> m >> n;

    vector<int> x(m-1,0);
    vector<int> y(n-1,0);

    for(int i = 0; i < m-1; i++) cin >> x[i];
    for(int i = 0; i < n-1; i++) cin >> y[i];
    sort(x.begin(),x.end(),greater<>());
    sort(y.begin(),y.end(),greater<>());

    int xNum = 1, yNum = 1;
    int xIdx = 0, yIdx = 0;
    int ans = 0;
    while (1)
    {   
        if(x[xIdx] > y[yIdx]){
            ans += x[xIdx]*yNum;
            xIdx++;
            xNum++;
        }else{
            ans += y[yIdx]*xNum;
            yIdx++;
            yNum++;
        }

        if(xIdx == m-1 || yIdx == n-1) break;
    }

    while(xIdx < m-1){
        ans += yNum*x[xIdx];
        xIdx++;
        xNum++;
    }

    while(yIdx <n-1){
        ans += xNum*y[yIdx];
        yIdx++;
        yNum++;
    }

    cout << ans << "\n";
    return 0;
}