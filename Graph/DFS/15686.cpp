#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n,m,answer = 65536;
int map[51][51];
bool selected[13];
vector<pair<int,int>> house_pos;
vector<pair<int,int>> chick_pos;

int getDist(pair<int,int> a, pair<int,int> b){
    return abs(a.first - b.first) + abs(a.second - b.second); 
}

void dfs(int idx ,int m_cnt){
    if(m_cnt == m){
        int dist_sum = 0;
        for(int i = 0; i < house_pos.size(); i++){
            int dist_min = 65536;
            for(int j = 0; j < chick_pos.size(); j++){
                if(selected[j]){
                    dist_min = min(dist_min,getDist(house_pos[i],chick_pos[j]));
                }
            }
            dist_sum += dist_min;
        }
        answer = min(answer,dist_sum);
        return;
    }

    for(int i = idx; i < chick_pos.size(); i++){
        if(!selected[i]){
            selected[i] = true;
            dfs(i,m_cnt+1);
            selected[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
            if (map[i][j] == 1){
                house_pos.push_back({i,j});
            }else if(map[i][j] == 2){
                chick_pos.push_back({i,j});
            }
        }
    }
    dfs(0,0);
    cout << answer << "\n";
    return 0;
}