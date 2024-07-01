#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

vector<vector<int>> color;
vector<vector<int>> mix;
bool visited[31];
int org[3];
int n;
int answer = INT_MAX;

void checkDiff(int cur){
    vector<int>tmp(n,0);
    
    for(int i = 0; i < cur; i++){
        tmp[0] += mix[i][0];
        tmp[1] += mix[i][1];
        tmp[2] += mix[i][2];
    }

    int dif = 0;
    for(int i = 0; i < 3; i++){
        dif += abs((tmp[i]/cur) - org[i]);
    }

    if(answer > dif) answer = dif;
}

void mixColor(int cur,int start){
    if(cur >= 2) checkDiff(cur);
    if(cur == 7) return;

    for(int i = start + 1; i < n ; i++){
        if(visited[i]) continue;

        visited[i] = true;
        mix[cur] = color[i];
        mixColor(cur+1,i);
        visited[i] = false;
    }

}

int gR,gG,gB;
int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int r,g,b;
        cin >> r >> g >> b;
        color.push_back(vector<int>{r,g,b});
    }

    cin >> org[0] >> org[1] >> org[2];
    
    mix.resize(n);
    mixColor(0,-1);
    cout << answer << "\n";
    return 0;
}