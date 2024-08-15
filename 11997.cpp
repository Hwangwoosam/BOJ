#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int x[1001],y[1001];
int sum[1001][1001],mat[1001][1001];

vector<int> px,py;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        px.push_back(x[i]);
        py.push_back(y[i]);
    }

    sort(px.begin(),px.end());
    sort(py.begin(),py.end());
    px.erase(unique(px.begin(),px.end()),px.end());
    py.erase(unique(py.begin(),py.end()),py.end());

    for(int i = 0; i < n; i++){
        x[i] = lower_bound(px.begin(),px.end(),x[i]) - px.begin();
        y[i] = lower_bound(py.begin(),py.end(),y[i]) - py.begin();
        mat[x[i]][y[i]]++;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) sum[i][j] = mat[i][j];
            else if(i == 0) sum[i][j] = sum[i][j-1] + mat[i][j];
            else if(j == 0) sum[i][j] = sum[i-1][j] + mat[i][j];
            else sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mat[i][j];
        }
    }
    int ans = n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int upperPart = max(sum[i][j], sum[i][n-1]-sum[i][j]);
            int lowerPart = max(sum[n-1][j]-sum[i][j], sum[n-1][n-1]-sum[n-1][j] - sum[i][n-1] + sum[i][j]);
            upperPart = max(upperPart,lowerPart);
            ans = min(ans,upperPart);
        }
    }

    cout << ans << "\n";

    return 0;
}