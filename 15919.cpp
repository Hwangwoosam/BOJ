#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int dp[1001];
vector<pair<int,int>> date;

int findEmptyLen(int cur){
    if(cur == m) return 0;
    int &ret = dp[cur];
    if(ret != -1) return ret;

    ret = 1001;
    for(int i = cur + 1; i < m; i++){
        if(date[i].first <= date[cur].second) continue;
        ret = min(ret,max(date[i].first - date[cur].second -1, findEmptyLen(i)));
    }

    ret = min(ret,n-date[cur].second);
    return ret;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int st,end;
        cin >> st >> end;
        date.push_back({st,end});
    }

    sort(date.begin(),date.end());
    memset(dp,-1,sizeof(dp));

    int ans = 1000;

    for(int i = 0; i < m; i++){
        ans = min(ans,max(date[i].first-1,findEmptyLen(i)));
    }
    cout << ans << "\n";
    return 0;
}