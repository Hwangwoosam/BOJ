#include <iostream>

using namespace std;

int n,m;

int map[1001][1001];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
    cin >> n >> m;

    int zeros = 0, ones = 0;
    for(int i = 0 ; i < n; i ++){
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 0) zeros++;
            else ones++;
        }
    }

    if(zeros % 2 == 1 || ones % 2 == 1) {
        cout << "-1\n";
        return 0;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];

                if( nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(map[i][j] == map[nx][ny]){
                    cout << "1\n";
                    return 0;
                }
            }
        }
    }

    cout << "-1\n";
    return 0;
}