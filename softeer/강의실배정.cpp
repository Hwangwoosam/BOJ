#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;
vector<pair<int,int>> course;

int n;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int start,end;
        cin >> start >> end; 
        course.push_back({end,start});
    }

    sort(course.begin(),course.end());

    int cur = course[0].first;
    int cnt = 1;
    for(int i = 1; i < course.size(); i++){
        if(cur <= course[i].second){
            cur = course[i].first;
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}