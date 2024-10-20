#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,int>> poster;
vector<int> order;
int wall[200001];

vector<int> ans;
//개수 : 10^4

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int cnt  = 0;
    for(int i = 0; i < n; i++){
        int l,r;
        cin >> l >> r;
        poster.push_back({l,r});
        order.push_back(l);
        order.push_back(r);  
    }

    sort(order.begin(),order.end());
    order.erase(unique(order.begin(),order.end()),order.end());

    for(int i = 0; i < n; i++){
        int l = lower_bound(order.begin(),order.end(),poster[i].first) - order.begin();
        int r = lower_bound(order.begin(),order.end(),poster[i].second) - order.begin();

        for(int j = l; j <= r; j++) wall[j] = i+1;
    }

    for(int i = 0; i < 20000; i++){
        if(wall[i] > 0) ans.push_back(wall[i]);
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    cout << ans.size() << "\n";
    return 0;
}