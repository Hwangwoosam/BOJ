#include <iostream>
#include <vector>

using namespace std;

int n,m;
int map[64][64];
vector<pair<int,int>> cctvs;

int main(){
    cin >> n >> m ;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                cctvs.push_back({i,j});
            }
        }
    }
}