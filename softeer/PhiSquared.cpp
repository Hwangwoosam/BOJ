#include <iostream>
#include <stack>
#include <deque>

using namespace std;

int n;
deque<pair<long long,long long>> dq[2];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        long long val;
        cin >> val;
        dq[1].push_back({i+1,val});
    }

    while(1){
        pair<long long,long long> pre,cur,next;

        if(dq[1].empty()) dq[1].swap(dq[0]);
        if(dq[1].size() + dq[0].size() == 1) break;

        if(!dq[0].empty()) pre = dq[0].back();
        else pre = {0,0};

        cur = dq[1].front();
        dq[1].pop_front();

        if(!dq[1].empty()) next = dq[1].front();
        else next = {0,0};

        if(pre.second != 0 && next.second != 0 && pre.second <= cur.second && next.second <= cur.second){
            dq[0].pop_back();
            dq[1].pop_front();
            dq[0].push_back({cur.first,pre.second + cur.second + next.second});
            continue;
        }

        if(pre.second != 0 && pre.second <= cur.second){
            dq[0].pop_back();
            dq[0].push_back({cur.first,pre.second + cur.second});
            continue;
        }

        if(next.second != 0 && next.second <= cur.second){
            dq[1].pop_front();
            dq[0].push_back({cur.first,cur.second + next.second});
            continue;
        }

        dq[0].push_back(cur);
    }

    cout << dq[1].front().second << "\n" << dq[1].front().first << "\n";
    return 0;
}