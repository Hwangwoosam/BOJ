#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

vector<pair<int,int>> bar;

int main(){
    int n;
    cin >> n;
    bar.resize(n,{0,0});

    for(int i = 0; i < n; i++){
        int l,h;
        cin >> l >> h;
        bar[i] = {l,h};
    }

    sort(bar.begin(),bar.end());

    int maxHeight = 0;
    int maxIdx = 0;    
    for(int i = 0; i < n; i++){
        if(maxHeight < bar[i].second){
            maxHeight = bar[i].second;
            maxIdx = i;
        }    
    }
    // cout << maxIdx << "\n";
    int curHeight = bar[0].second;
    int curStart = bar[0].first;
    int ans = 0;
    for(int i = 1; i <= maxIdx; i++){
        if(curHeight < bar[i].second){
            ans += curHeight*(bar[i].first - curStart);

            curHeight = bar[i].second;
            curStart = bar[i].first;
        }
    }

    curHeight = bar[n-1].second;
    curStart = bar[n-1].first;
    for(int i = n-2; i >= maxIdx; i--){
        if(curHeight <= bar[i].second){
            ans += curHeight*(curStart - bar[i].first);

            curHeight = bar[i].second;
            curStart = bar[i].first;
        }
    }
    ans+= maxHeight;
    cout << ans << "\n";

    return 0;
}