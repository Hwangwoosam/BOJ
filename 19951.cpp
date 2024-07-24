#include <iostream>
#include <vector>

using namespace std;

vector<int> soil;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    vector<int> mv (n+1,0);

    for(int i = 0; i < n; i++){
        int h;
        cin >> h;
        soil.push_back(h);
    }

    for(int i = 0; i < m; i++){
        int a,b,k;
        cin >> a >> b >> k;
        mv[a] += k;
        mv[b+1] -= k;
    }

    for(int i = 0; i <= n; i++){
        mv[i+1] += mv[i]; 
    }

    for(int i = 0; i < n; i++){
        soil[i] += mv[i+1];
        cout << soil[i] << " ";
    }
    cout << "\n";
    
    return 0;
}