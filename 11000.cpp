#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        v.push_back({start,end});
    }
    sort(v.begin(),v.end());
    int vSize = v.size();

    pq.push(v[0].second);
    for(int i = 1; i < vSize; i++){
        if(v[i].first >= pq.top()){
            pq.pop();
            pq.push(v[i].second);

        }else{
            pq.push(v[i].second);
        }
    }

    cout << pq.size() << "\n";
}