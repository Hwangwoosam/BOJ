#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int map[50][50];

vector<pair<int,int>> home;
vector<pair<int,int>> chicken;

int main(){
    cin >> n >> m;

    for(int i = 0;i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];

            if(map[i][j] == 1) home.push_back({i,j});
            if(map[i][j] == 2) chicken.push_back({i,j});  
        } 
    }
    vector<int> brute(chicken.size(),1);
    fill(brute.begin(),brute.begin()+chicken.size() - m,0);
    int mn = INT32_MAX;
    do{
        int dist = 0;
        for(auto h: home){
            int tmp = INT32_MAX;
            for(int i = 0; i < chicken.size(); i++){
                if(brute[i] == 0) continue;
                tmp = min(tmp,abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second));
            }
            dist += tmp;
        }
        mn = min(mn,dist);
    }while(next_permutation(brute.begin(),brute.end()));


    cout << mn << "\n";
    return 0;
}