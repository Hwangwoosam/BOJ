#include <iostream>
#include <queue>

using namespace std;

int n,k;
priority_queue<int> pq;

int main(){
    int start = 0;
    cin >> n >> k >> start;

    int prev = start;
    for(int i = 0; i < n-1; i++){
        int time;
        cin >> time;
        pq.push(time-prev-1);
        prev = time;
    }
    
    int ans = prev + 1 - start;
    while(--k){
        ans -= pq.top();
        pq.pop();
    }

    cout << ans << "\n";
    return 0;
}