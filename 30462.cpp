#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    vector<long long> v(n);
    vector<long long> ans(n);
    deque<pair<long long,long long>> dq;
    set<long long> s;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        s.insert(i+1);
    }

    if(v[n-1] != n+1){
        cout << "No\n";
        return 0;
    }

    long long cur = 1;
    for(int i = 0; i < n; i++){
        if(v[i] != cur){
            dq.push_back({i,cur});
            s.erase(cur);
            cur = v[i];
        }
    }

    bool check = true;
    long long curIdx = 0;
    while (!dq.empty())
    {
        long long idx = dq.front().first;
        long long val = dq.front().second;
        dq.pop_front();

        for(; curIdx < idx; curIdx++){
            auto itr = s.begin();
            ans[curIdx] = *itr;
            s.erase(itr);
        }

        if(!s.empty()){
            auto itr = s.begin();
            if(*itr < v[idx]){
                check = false;
                break;
            }
        }

        ans[curIdx++] = val;
    }
    
    if(!check){
        cout << "No\n";
    }else{
        cout << "Yes\n";
        for(auto itr : ans ){
            cout << itr << " ";
        }
    }
    cout << "\n";

    return 0;
}