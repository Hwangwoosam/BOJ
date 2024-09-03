#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int a,b,c;
int sum = 0;
bool visited[1501][1501];

int bfs(){
    priority_queue<pair<int,int>> pq;
    pq.push({a,b});
    visited[a][b] = true;

    while(!pq.empty()){
        int ca = pq.top().first;
        int cb = pq.top().second;
        int cc = sum - ca - cb;
        pq.pop();

        // cout << "cur: " << ca << " " << cb << " " << cc <<"\n";
        if(ca == cb && cb == cc) return 1;

        int nx[] = {ca,ca,cb};
        int ny[] = {cb,cc,cc};

        for(int i = 0; i < 3; i++){
            int na = nx[i];
            int nb = ny[i];
            
            // cout << na << " " << nb << "\n";
            if(na > nb){
                na -= nb;
                nb += nb;
                // cout << "check1: " << na << " " << nb << "\n";
            }else if(na < nb){
                nb -= na;
                na += na;
                // cout << "check2: " << na << " " << nb << "\n";
            }else{
                continue;
            }

            int nc = sum - na - nb;
            // cout << "next: " << na << " " << nb << " " << nc << "\n";
            na = min(nc,min(na,nb));
            nb = max(nc,max(na,nb));

            if(visited[na][nb]) continue;
            // cout << "next: " << na << " " << nb << " " << nc << "\n";
            pq.push({na,nb});
            visited[na][nb] = true;
        }

    }


    return 0;
}

int main(){
    cin >> a >> b >> c;

    sum = a+b+c;

    if(sum%3 != 0){
        cout << "0\n";
    }else{
        cout << bfs() << "\n";
    }

    // a,b,sum-(a+b)

    return 0;
}