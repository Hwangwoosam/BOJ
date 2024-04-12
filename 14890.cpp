#include <iostream>
#include <cmath>

using namespace std;

int map[101][101];
int n,l,answer = 0;

bool checkCol(int row){
    bool slope[101] = {0,};
    for(int i = 0; i < n-1; i++){
        if(abs(map[i][row]-map[i+1][row]) > 1) return false;

        if(map[i][row] == map[i+1][row] + 1){
            int curHeight = map[i+1][row];
            for(int j = i+2; j < i+1+l; j++){
                if(j >= n || map[j][row] != curHeight) return false;
            }
            slope[i+l] = true;
        }

        if(map[i][row] == map[i+1][row] - 1){
            int curHeight = map[i][row];
            for(int j = i; j > i-l; j--){
                if(j < 0 || map[j][row] != curHeight || slope[j]) return false;
            }
        }
    }
    
    return true;
}

bool checkRow(int col){
    bool slope[101] = {0,};
    for(int i = 0; i < n-1; i++){
        if(abs(map[col][i]-map[col][i+1]) > 1) return false;

        if(map[col][i] == map[col][i+1] + 1){
            int curHeight = map[col][i+1];
            for(int j = i+2; j < i+1+l; j++){
                if(j >= n || map[col][j] != curHeight) return false;
            }
            
            slope[i+l] = true;
        }

        if(map[col][i] == map[col][i+1] - 1){
            int curHeight = map[col][i];
            for(int j = i; j > i-l; j--){
                if(j < 0 || map[col][j] != curHeight || slope[j]) return false;
            }
        }
    }

    return true;
}

int main(){
    cin >> n >> l;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        if(checkCol(i)) answer++;
        if(checkRow(i)) answer++;
    }

    cout << answer << "\n";
    return 0;
}