#include <iostream>

using namespace std;

int n,m,k;
int r,c;
int note[40][40];
int sticker[10][10];

bool pastable(int x,int y){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(note[x+i][y+j] == 1 && sticker[i][j] == 1) return false;
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(sticker[i][j] == 1){
                note[x+i][y+j] = 1;
            }
        }
    }

    return true;
}

void rotate(){
    int tmp[10][10];
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            tmp[i][j] = sticker[i][j];
        }
    }

    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            sticker[i][j] = tmp[r-1-j][i];
        }
    }

    swap(r,c);
}

int main(){
    cin >> n >> m >> k;

    while(k--){
        cin >> r >> c;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> sticker[i][j];
            }
        }

        for(int rot = 0; rot < 4; rot++){
            bool is_pastable = false;
            for(int i = 0; i <= n-r; i++){
                if(is_pastable) break;
                for(int j = 0; j <= m-c; j++){
                    if(pastable(i,j)){
                        is_pastable = true;
                        break;
                    }
                }
            }
            if(is_pastable) break;
            rotate();
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cnt += note[i][j];
        }
    }
    cout << cnt << "\n";
    return 0;
}