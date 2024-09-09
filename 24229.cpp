#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> board;

    for(int i = 0; i < n; i++){
        int l,r;
        cin >> l >> r;
        board.push_back({l,r});
    }

    sort(board.begin(),board.end());

    int s = board[0].first;
    int e = board[0].second;

    vector<pair<int,int>> v;

    for(int i = 1 ; i < n; i++){
        if(e >= board[i].first) e = max(e,board[i].second);
        else{
            v.push_back({s,e});
            s = board[i].first;
            e = board[i].second;
        }
    }

    v.push_back({s,e});
    int vSize = v.size();

    int val = 0,idx = 0;
    for(int i = 0; i < vSize; i++){
        if(val >= v[i].first){
            idx = i;
            val = max(val,v[i].second + (v[i].second - v[i].first));
        }
    }

    cout << v[idx].second << "\n";
    return 0;
}