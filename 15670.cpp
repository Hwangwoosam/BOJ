#include <iostream>
#include <vector>

using namespace std;

int diff[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;

    vector<int> roads(n+1,0);
    for(int i = 1; i <= n; i++){
        cin >> roads[i];
        diff[i] += diff[i-1] + (roads[i-1] > roads[i]);
    }

    while(m--){
        int l,r;
        cin >> l >> r;
        
        int ans = r-l+1 - (diff[r]-diff[l]);
        if(l != 1) ans += (roads[l-1] > roads[r]) + diff[l-1] - diff[1];
        if(r != n) ans += (roads[l] > roads[r+1]) + diff[n] - diff[r+1];

        cout << ans << "\n";
    }


    return 0;
}