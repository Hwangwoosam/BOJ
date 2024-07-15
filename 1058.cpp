#include <iostream>
#include <climits>

using namespace std;

int userGraph[51][51];
int dist[51][51];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = 100000;
        }
    }

    for(int i = 0; i < n; i++){
        string inp;
        cin >> inp;

        for(int j = 0; j < n; j++){
            if(inp[j] == 'Y'){
                userGraph[i][j] = 1;
                dist[i][j] = 1;
            }else{
                userGraph[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int ans =  0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(dist[i][j] <= 2) cnt++;
        }

        if(ans < cnt) ans = cnt;
    }

    cout << ans << "\n";
    return 0;
}