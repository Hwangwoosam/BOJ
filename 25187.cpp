#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int parent[MAX],ran[MAX],cleanWater[MAX],water[MAX];

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u,int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(ran[u] > ran[v]) swap(u,v);
    parent[u] = v;
    cleanWater[v] += cleanWater[u];
    water[v] += water[u]; 

    if(ran[u] == ran[v]) ran[v]++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;

    for(int i = 1; i <= MAX; i++) {
        parent[i] = i;
        ran[i] = 1;
    }

    for(int i = 1; i <= n; i++){
        int state;
        cin >> state;
        if(state == 1) cleanWater[i]++;
        else water[i]++;
    }
    
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        merge(u,v);
    }

    for(int i = 0; i < q; i++){
        int num;
        cin >> num;

        int root = find(num);
        if(cleanWater[root] > water[root]) cout << "1\n";
        else cout << "0\n";
    }


    return 0;
}