#include <iostream>
#include <vector>

using namespace std;

#define max_vaule  INT32_MAX/2

int dist[101][101];
vector<int> v;
int n,m,r;
int answer = 0;

int main(){
    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j) dist[i][j] = max_vaule;
        }
    }

    for(int i = 0; i < n; i++){
        int cnt_item;
        cin >> cnt_item;
        v.push_back(cnt_item);
    }

    for(int i = 0; i < r; i++){
        int a,b,l;
        cin >> a >> b >> l;
        dist[a][b] = l;
        dist[b][a] = l;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt = v[i-1];
        for(int j = 1; j <=n; j++){
            if(i != j && dist[i][j] <= m){
                cnt += v[j-1];
            }
        }
        answer = max(answer,cnt);
    }
    cout << answer << "\n";
    return 0;
}