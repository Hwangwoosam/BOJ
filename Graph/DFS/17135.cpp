#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,d,answer;
int map[16][16];
int originMap[16][16];
vector<int> archer;

void initMap(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            map[i][j] = originMap[i][j];
        }
    }
}

int attack(){
    int result = 0;

    int archerRow = n;
    while (archerRow > 1)
    {   
        vector<pair<int,int>> enemy;
        for(int i = 0; i < 3; i++){
            
        }

        
        archerRow--;
    }
    
}

void selectArcher(int n, int i){
    if(n == 3){
        initMap();
        answer = max(answer,attack());
        return;
    }

    for(int j = i; j < m; j++){
        archer.push_back(j);
        selectArcher(n+1,j);
        archer.pop_back();
    }
}

int main(){
    cin >> n >> m >> d;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            originMap[i][j] = map[i][j];
        }
    }
    
    return 0;
}