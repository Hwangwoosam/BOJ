#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int,int>> relations[10001];
bool visited[10001];
int n,m,sum = 0, cnt = 0;

int prim(){
    priority_queue<pair<int,int>> pq;
    visited[1] = true;
    for(pair<int,int> elem : relations[1]) pq.push(elem);
    
    int cost = 0;
    while(!pq.empty()){
        int weight = pq.top().first;
        int nextNode = pq.top().second;
        pq.pop();

        if(!visited[nextNode]){
            visited[nextNode] = true;
            cost += weight;
            
            for(pair<int,int> elem : relations[nextNode]){
                if(!visited[elem.second]) pq.push(elem);
            }
        }
    }

    return cost - cnt*10000;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        sum += c;
        if(d == 1){
            c += 10000;
            cnt++;
        }

        relations[a].push_back({c,b});
        relations[b].push_back({c,a});
    }
    
    cout << sum - prim() << "\n";
    return 0;
}