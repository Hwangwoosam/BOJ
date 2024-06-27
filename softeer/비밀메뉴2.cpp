#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int n,m,k;

int map[3001][3001];
int st1[3001],st2[3001];

int main(){
    cin >> n >> m >> k;

    vector<int> s,f;
    for(int i = 0; i < n; i++){
        cin >> st1[i];
    }

    for(int i = 0; i < m; i++){
        cin >> st2[i];
    }

    int maxVal = INT_MIN;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(st1[i-1] == st2[j-1]){
                map[i][j] = map[i-1][j-1] + 1;
                if(maxVal < map[i][j]) maxVal = map[i][j];
            }else{
                map[i][j] = 0;
            }
        }
    }

    if(maxVal == INT_MIN) maxVal = 0;
    cout << maxVal << "\n";
    return 0;
}