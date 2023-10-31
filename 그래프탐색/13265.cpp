#include <iostream>
#include <vector>

using namespace std;

int t;
bool isPossible;
vector<int> circle;
vector<vector<int>> line;

void dfs(int idx){
    for(auto i : line[idx]){
        if(!circle[i]){
            circle[i] = 3 - circle[idx];
            dfs(i);
        }

        if(circle[idx] == circle[i]){
            isPossible = false;
        }
    }
}

int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        int n,m;
        cin >> n >> m;
        circle = vector<int>(n+1);
        line = vector<vector<int>>(n+1);
        for(int j = 0; j < m; j++){
            int from,to;
            cin >> from >> to;
            line[from].push_back(to);
            line[to].push_back(from);
        }
        
        isPossible = true;
        
        for(int j = 1; j <= n; j++){
            if(!circle[j]) {
                circle[j] = 1;
                dfs(j);
            }
        }

        if(isPossible){
            cout << "possible\n";
        }else{
            cout << "impossible\n";
        }
    }

    return 0;
}