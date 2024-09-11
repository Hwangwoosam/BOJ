#include <iostream>
#include <map>
#include <vector>

using namespace std; 

int prevSt[1000001];
int nextSt[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;

    vector<int> station(n);

    for(int i = 0; i< n; i++) cin >> station[i];

    int first = *station.begin();
    int last = *(station.end()-1);
    
    for(int i = 0; i < n; i++){
        int prev = (i==0) ? n-1 : i-1;
        int next = (i==n-1) ? 0 : i+1;
        prevSt[station[i]] = station[prev];
        nextSt[station[i]] = station[next];
    }

    for(int i = 0; i < m; i++){
        string cmd;
        int a,b;
        cin >> cmd >> a;

        if(cmd == "BN"){
            cin >> b;
            cout << nextSt[a] << "\n";
            // a --> b --> next[a];
            prevSt[nextSt[a]] = b;
            nextSt[b] = nextSt[a];
            nextSt[a] = b;
            prevSt[b] = a;
        }else if(cmd == "BP"){
            cin >> b;
            cout << prevSt[a] << "\n";
            // prev --> b --> a;
            nextSt[prevSt[a]] = b;
            prevSt[b] = prevSt[a];
            nextSt[b] = a;
            prevSt[a] = b;
        }else if(cmd == "CN"){
            cout << nextSt[a] << "\n";
            // a --> next --> next2
            // a --> next2
            prevSt[nextSt[nextSt[a]]] = a;
            nextSt[a] = nextSt[nextSt[a]];
        }else{
            cout << prevSt[a] << "\n";
            nextSt[prevSt[prevSt[a]]] = a;
            prevSt[a] = prevSt[prevSt[a]];
        }
    }


    return 0 ;
}