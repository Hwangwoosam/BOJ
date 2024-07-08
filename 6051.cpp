#include <iostream>
#include <vector>

using namespace std;

// a s t
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int>> st(n+1, {-1,0});

    int curIdx = 0;
    for(int i = 1; i <= n; i++){
        char c;
        int val;
        cin >> c;

        if(c == 'a'){
            cin >> val;
            st[i] = {val,curIdx}; // val 및 이전 Idx 저장
            curIdx = i;
        }else if(c == 's'){
            st[i] = {st[curIdx].first,curIdx}; // 이전 val 및 이전 idx 저장
            curIdx = st[curIdx].second;
        }else if(c == 't'){
            cin >> val;
            st[i] = {st[curIdx].first,curIdx};
            curIdx = st[val].second; 
        }

        cout << st[curIdx].first << "\n";
    }


    return 0;
}
