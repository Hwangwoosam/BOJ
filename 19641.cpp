#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v;
pair<int,int> ans[100001];

int getField(int idx, int prev, int end){
    int subSum = 0;
    int curSize = v[idx].size();
    // cout << "idx: " << idx << "\n";
    // cout << "prev: " << prev << "\n";
    for(int i = 0; i < curSize; i++){
        if(v[idx][i] == prev) continue;
        // cout << v[idx][i] << "\n";
        // cout << "v[i] :" << v[idx][i] << "\n";
        subSum += getField(v[idx][i],idx,end + subSum*2 +1);
    }
    // cout << idx << "  " << end+1 << " " << end+1 + subSum*2 +1 << "\n"; 
    ans[idx] = {end+1, end+1 + subSum*2 +1};

    return subSum+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    v.resize(n+1);

    for(int i = 0 ; i < n; i++){
        int idx;
        cin >> idx;

        while(1){
            int to;
            cin >> to;

            if(to == -1) break;
            v[idx].push_back(to);
        }
    }

    for(int i = 1; i <= n; i++){
        sort(v[i].begin(),v[i].end());
        // cout << i << ": ";
        // for(int j = 0; j < v[i].size(); j++){
        //     cout << v[i][j] << " ";
        // }
        // cout << "\n";
    }

    int root;
    cin >> root;
    getField(root,0,0);

    for(int i = 1; i <= n; i++){
        cout << i << " " << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
}