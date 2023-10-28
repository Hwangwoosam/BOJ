#include <iostream>
#include <algorithm>

#define MAX 2001

using namespace std;

int n,m;

// 출력값 = 저장값 + 가중치
// 저장값 = 최대 입력값

// 가중치
int d[MAX][MAX];
//입력 값
int print[MAX][MAX];
//저장 값
int store[MAX][MAX];

int ret;
// inp[i][j] = [i-1] <= j-b, b < j인 모든 좌표 (a,b) 출력 값

int main(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        string inp;
        cin >> inp;
        for(int j = 0; j < inp.size(); j++){
            d[i][j+1] = inp[j] - '0';
        }
    }

    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= m; i++){
            for(int k = -1; k <=1; k++){
                store[i][j] = max(store[i][j],print[i+k][j-1]);
                // cout << store[i][j] << "\n";
            }

            print[i][j] = store[i][j] + d[i][j];
            ret = max(ret,store[i][j]);
        }
    }

    cout << ret << "\n";
    return 0;
}