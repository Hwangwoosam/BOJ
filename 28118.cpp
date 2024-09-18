#include <iostream>
#include <cstring>

using namespace std;

int n,m;
int ranks[41];

int find(int x){
    if(ranks[x] < 0) return x;
    return ranks[x] = find(ranks[x]);
}

void getUnion(int x,int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(x < y){
        ranks[x] += ranks[y];
        ranks[y] = x;
    }else{
        ranks[y] += ranks[x];
        ranks[x] = y;
    }
}

int main(){
    memset(ranks,-1,sizeof(ranks));
    cin >> n >> m;

    for(int i =0; i < m; i++){
        int a,b;
        cin >> a >> b;

        getUnion(a,b);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(ranks[i] < 0) ans++;
    }

    cout << ans - 1 << "\n";

    return 0;
}