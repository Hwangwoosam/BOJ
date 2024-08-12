#include <iostream>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

vector<pair<int,pair<int,int>>> house;

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int x,y,z;
        cin >> x >> y >> z;
        house.push_back({x,{y,z}});
    }

    int ans = INT_MAX;
    for(int i = 0 ; i < n; i++){
        int cx = house[i].first;
        int cy = house[i].second.first;
        int cz = house[i].second.second;

        int dist1 = INT_MAX;
        int dist2 = INT_MAX;
        for(int j = 0; j < n; j++){
            if(i == j) continue;

            int nx = house[j].first;
            int ny = house[j].second.first;
            int nz = house[j].second.second;

            int d = abs(cx-nx) + abs(cy-ny) + abs(cz - nz);
            if(d < dist1){
                dist2 = dist1;
                dist1 = d;
            }else if(d < dist2){
                dist2 = d;
            }
        }
        ans = min(ans,dist1+dist2);
    }  

    cout << ans << "\n";
    return 0;
}