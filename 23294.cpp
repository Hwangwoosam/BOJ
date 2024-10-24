#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

deque<int> backward;
deque<int> forehead;
vector<int> mem;

int removeAll(int curCacheSize){
    int ret = curCacheSize;
    while(!forehead.empty()){
        int idx = forehead.back();
        ret -= mem[idx];
        forehead.pop_back();
    }
    return ret;
}

int main(){
    int n,q,c;

    cin >> n >> q >> c;

    mem.resize(n+1,0);
    for(int i = 1; i <= n; i++) cin >> mem[i];
    
    int curPage = -1;
    int curCacheSize = 0;
    for(int i = 0; i < q; i++){
        string cmd;
        cin >> cmd;
        // cout << "commands: " << cmd << "\n";
        if(cmd == "B"){
            if(!backward.empty()){
                forehead.push_back(curPage);
                curPage = backward.back();
                backward.pop_back();
            }
        }else if(cmd == "F"){
            if(!forehead.empty()){
                backward.push_back(curPage);
                curPage = forehead.back();
                forehead.pop_back();
            }
        }else if(cmd == "A"){
            int nextPage;
            cin >> nextPage;

            if(!forehead.empty()) curCacheSize = removeAll(curCacheSize);
            if(curPage != -1) backward.push_back(curPage);
            
            curPage = nextPage;
            curCacheSize += mem[curPage];

            while(curCacheSize > c){
                int oldIdx = backward.front();
                backward.pop_front();
                curCacheSize -= mem[oldIdx];
            }  
        }else if(cmd == "C"){
            for(auto it = backward.begin(); it != backward.end(); it++) curCacheSize -= mem[*it];

            backward.erase(unique(backward.begin(),backward.end()),backward.end());
            for(auto it = backward.begin(); it != backward.end(); it++ ) curCacheSize += mem[*it];
        }
    }

    cout << curPage << "\n";
    if(!backward.empty()){
        while(!backward.empty()){
            cout << backward.back() << " ";
            backward.pop_back();
        }
        cout << "\n";
    }else{
        cout << "-1\n";
    }

    if(!forehead.empty()){
        while(!forehead.empty()){
            cout << forehead.back() << " ";
            forehead.pop_back();
        }
        cout << "\n";
    }else{
        cout << "-1\n";
    }

    return 0;
}