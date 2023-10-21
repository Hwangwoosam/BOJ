#include <iostream>

using namespace std;

int n,m,h;
int minValue = 9999;
bool visitied[31][11];

bool ladderCheck(){
    for(int i = 1; i <= n; i++){
        int pos = i;
        for(int j = 1; j <= h; j++){
            if(visitied[j][pos]){
                pos++;
            }else if(visitied[j][pos-1]){
                pos--;
            }
        }

        if(pos != i) return false;
    }

    return true;
}

void selectLine(int idx, int cnt){
    if(cnt > 3) return;
    if(ladderCheck() && (minValue > cnt)) minValue = cnt;

    for(int i = idx; i <= h; i++){
        for(int j = 1; j < n; j++){
            if(visitied[i][j] || visitied[i][j-1] || visitied[i][j+1]) continue;

            visitied[i][j] = true;
            selectLine(i,cnt+1);
            visitied[i][j] = false;
        } 
    }  

}

int main(){
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        visitied[a][b] = true;
    }

    selectLine(1,0);
    if(minValue == 9999){
        cout << "-1\n";
    }else{
        cout << minValue << "\n";
    }

    return 0;
}