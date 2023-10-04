#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

int n,maxVal = 0;

using namespace std;

void moveBlock(int dir,vector<vector<int>> & map){
    queue<int> q;
    switch (dir)
    {
    //위
    case 0:
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(map[j][i]) {
                    q.push(map[j][i]);
                    map[j][i] = 0;
                }
            }

            int idx = 0;
            while(!q.empty()){
                int num = q.front();
                q.pop();

                if(map[idx][i] == 0){
                    map[idx][i] = num;
                }else if(map[idx][i] == num){
                    map[idx][i] *= 2;
                    idx++;
                }else{
                    idx++;
                    map[idx][i] = num;
                }
            }
        }

        break;
    //아래
    case 1:
        for(int i = 0; i < n;i++){
            for(int j = n-1; j >= 0; j--){
                if(map[j][i]){
                    q.push(map[j][i]);
                    map[j][i] = 0;
                }
            }

            int idx = n-1;
            while(!q.empty()){
                int num = q.front();
                q.pop();

                if(map[idx][i] == 0){
                    map[idx][i] = num;
                }else if(map[idx][i] == num){
                    map[idx][i] *= 2;
                    idx--;
                }else{
                    idx--;
                    map[idx][i] = num;
                }
            }
        }
        break;
    //오른
    case 2:
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(map[i][j]){
                    q.push(map[i][j]);
                    map[i][j] = 0;
                }
            }

            int idx = 0;
            while (!q.empty())
            {
                int num = q.front();
                q.pop();

                if(map[i][idx] == 0){
                    map[i][idx] = num;
                }else if(map[i][idx] == num){
                    map[i][idx] *= 2;
                    idx++;
                }else{
                    idx++;
                    map[i][idx] = num;
                }
            }
        }
        break;
    //왼쪽
    case 3:
        for(int i = 0; i < n; i++){
            for(int j = n-1; j >= 0; j--){
                if(map[i][j]){
                    q.push(map[i][j]);
                    map[i][j] = 0;
                }
            }

            int idx = n-1;
            while (!q.empty())
            {
                int num = q.front();
                q.pop();

                if(map[i][idx] == 0){
                    map[i][idx] = num;
                }else if(map[i][idx] == num){
                    map[i][idx] *= 2;
                    idx--;
                }else{
                    idx--;
                    map[i][idx] = num;
                }
            }
        }
        break;

    default:
        cout << "Error\n";
        break;
    }
}

void bfs(int cnt, vector<vector<int>>& map){
    int prevMap[n][n];

    if(cnt == 5){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                maxVal = max(maxVal,map[i][j]);
            }
        }
        return;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            prevMap[i][j] = map[i][j];
        }
    }

    for(int i = 0; i < 4; i++){
        moveBlock(i,map);
        bfs(cnt+1,map);

        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                map[j][k] = prevMap[j][k];
            }
        }
    }
}

int main(){
    cin >> n;
    vector<vector<int>> map;

    for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j < n; j++){
            int inp;
            cin >> inp;
            row.push_back(inp);
        }
        map.push_back(row);
    }

    bfs(0,map);
    cout << maxVal << "\n";

    return 0;
}