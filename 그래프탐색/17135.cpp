#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n,m,d;
int originMap[16][16];
int map[16][16];
int result = 0;

int getDistance(int ax,int ay, int bx, int by){
    return abs(ax-bx) + abs(ay-by);
}

bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    if(a.first == b.first){
        return a.second.second < b.second.second;
    }

    return a.first < b.first;
}

// 궁수의 공격으로 제거할 수 있는 적의 최대 수
int attack(vector<int>& archers){
    int cnt = 0;

    int archerRow = n;
    while(archerRow >= 1){
        vector<pair<int,int>> targets;
        for(auto &archer : archers){
        
            vector<pair<int,pair<int,int>>> enemy;
            for(int i = 0; i < archerRow; i++){
                for(int j = 0; j < m; j++){
                    if(!map[i][j]) continue;
                    int dist = getDistance(i,j,archerRow,archer);
                    if(dist > d) continue;

                    enemy.push_back({dist,{i,j}});
                }
            }
// 4,1 6,1
            if(enemy.empty()) continue;
            sort(enemy.begin(),enemy.end(),cmp);
            targets.push_back({enemy[0].second.first,enemy[0].second.second});
        }

        for(auto &target : targets){
            if(map[target.first][target.second] == 1){
                map[target.first][target.second] = 0;
                cnt ++;
            }
        }

        archerRow--;
    }
    return cnt;
}


void copyMap(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            map[i][j] = originMap[i][j];
        }
    }
}

void archerSelect(int num, int idx, vector<int>&archer){
    if(num == 3){
        copyMap();
        result = max(result,attack(archer));
        return;
    }

    for(int i = idx; i < m; i++){
        archer.push_back(i);
        archerSelect(num+1,i+1,archer);
        archer.pop_back();
    }
}

int main(){
    cin >> n >> m >> d; 

    for(int i = 0; i < n ; i ++){
        for(int j = 0; j < m; j++){
            cin >> originMap[i][j];
        }
    }

    vector<int> archer;
    archerSelect(0,0,archer);
    cout << result << "\n";

    return 0;
}