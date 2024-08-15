#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,pair<int,int>>> bus;

bool cmp (pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
    if(a.second.first == b.second.first) return a.second.second < b.second.second;
    
    return a.second.first < b.second.first;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int s,e,c;
        cin >> s >> e >> c;
        bus.push_back({c,{s,e}});
    }

    sort(bus.begin(),bus.end(),cmp);

    vector<pair<int,pair<int,int>>> ans;

    int s = bus[0].second.first;
    int e = bus[0].second.second;
    int c = bus[0].first;
    for(int i = 1 ; i < n; i++){
        int ns = bus[i].second.first;
        int ne = bus[i].second.second;
        int nc = bus[i].first;

        if(e < ns){
            ans.push_back({c,{s,e}});
            s = ns;
            e  = ne;
            c = nc;
            continue;
        }

        e = max(e,ne);
        c = min(c,nc);
    }

    ans.push_back({c,{s,e}});
    int ansSize = ans.size();
    cout << ansSize << "\n";
    for(int i = 0 ; i < ansSize; i++){
        cout << ans[i].second.first << " " << ans[i].second.second << " "<< ans[i].first << "\n";
    }

    return 0;
}