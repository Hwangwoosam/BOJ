#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,L,M;
int result = 0;
vector<pair<int,int>> fish;

int main(){
    cin >> N >> L >> M;
    for(int i = 0; i < M; i++){
        int x,y;
        cin >> x >> y;
        fish.push_back({x,y});
    }
    sort(fish.begin(),fish.end());

    int sumLine = L/2;

    for(int h = 1; h < sumLine; h++){
        int w = sumLine - h;
        if(w > N-1 || h > N-1) continue;

        for(int i = 0; i < M; i++){
            int y = fish[i].first;
            int x = fish[i].second;
            for(int k = 0; k <= w; k++){
                int cnt = 1;

                for(int j = i+1; j < M; j++){
                    int ny = fish[j].first;
                    int nx = fish[j].second;

                    if(ny > y+h) break;
                    if(x-k <= nx && nx <= x-k + w) cnt++;
                }
                result = max(result,cnt);
            }
        }
    }
    cout << result << "\n";

    return 0;
}