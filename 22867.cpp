#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;
vector<pair<string,int>> bus;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        string s,e;
        cin >> s >> e;
        bus.push_back({s,1});
        bus.push_back({e,-1});
    }

    sort(bus.begin(),bus.end());

    int sum = 0;
    int ans = 0;

    for(auto b : bus){
        sum += b.second;
        ans = max(ans,sum);
    }

    cout << ans << "\n";
    return 0;
}