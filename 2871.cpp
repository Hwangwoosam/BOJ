#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
bool visited[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
 
    string inp;
    cin >> inp;

    for(int i = 0; i < n; i++) pq.push({inp[i]-'a',-i});
    
    string s = "",h = "";

    int idx = n-1;
    while(!pq.empty() && idx >= 0){
        while(visited[idx]){
            idx--;
        }
        s += inp[idx];
        visited[idx] = true;
        idx--;
        while(!pq.empty() && visited[-pq.top().second]){
            pq.pop();
        }

        if(pq.empty()) break;

        h += pq.top().first + 'a';
        visited[-pq.top().second] = true;
        pq.pop();
    }

    if(s <= h) cout << "NE\n";
    else cout << "DA\n";

    cout << h << "\n";
    return 0;
}