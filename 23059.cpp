#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#define MAX 400001

unordered_map<string,int> str2idx;
unordered_map<int,string> idx2str;
int inDegree[MAX];
vector<int> graph[MAX];
vector<int> ans[MAX];

bool cmp(int a,int b){
    return idx2str[a] < idx2str[b];
}

int main(){
    int n;
    cin >> n;

    int idx = 1;
    for(int i = 1; i <= n; i++){
        string from,to;

        cin >> from >> to;

        if(str2idx.find(from) == str2idx.end()){
            str2idx[from] = idx;
            idx2str[idx++] = from;
        }

        if(str2idx.find(to) == str2idx.end()){
            str2idx[to] = idx;
            idx2str[idx++] = to;
        }

        int fromIdx = str2idx[from];
        int toIdx = str2idx[to];
        graph[fromIdx].push_back(toIdx);
        inDegree[toIdx]++;
    }

    queue<pair<int,int>> q;
    for(int i = 1; i < idx; i++){
        // cout << i << ": " << inDegree[i] << " " << idx2str[i] << "\n";
        if(inDegree[i] == 0){
            q.push({i,0});
            ans[0].push_back(i);
        }
    }

    int cnt = 0;
    while(!q.empty()){
        int cur = q.front().first;
        int level = q.front().second;
        q.pop();
        // cout << "cur: " << cur << " " << idx2str[cur] <<  "\n";
        int connSize = graph[cur].size();
        for(int i = 0; i < connSize; i++){
            int next = graph[cur][i];
            inDegree[next]--;

            // cout << "next : " << next << " " << inDegree[next]  << "\n";
            if(inDegree[next] == 0){
                q.push({next,level+1});
                ans[level+1].push_back(next);
            }
        }
        
        cnt++;
    }   
    // cout << cnt << " " << idx << "\n";
    if(cnt != idx-1) cout << "-1\n";
    else{
        for(int i = 0; i < idx; i++){
            if(!ans[i].size()) break;

            sort(ans[i].begin(),ans[i].end(),cmp);
            for(int j = 0; j < ans[i].size(); j++){
                cout << idx2str[ans[i][j]] << "\n";
            }    
        }
    }
    return 0;
}