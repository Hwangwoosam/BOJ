#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> weight;
vector<int> relation[100001];

bool isBest(int idx){
    int relSize = relation[idx].size();

    for(int i = 0; i < relSize; i++){
        // cout << weight[idx] << " " << weight[relation[idx][i]] << "\n";
        if(weight[idx] <= weight[relation[idx][i]]){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        weight.push_back(tmp);
    }

    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        relation[from-1].push_back(to-1);
        relation[to-1].push_back(from-1);
    }

    int answer = 0;
    for(int i = 0; i < n; i++){
        if(isBest(i)){
            // cout << "i: " << i << "\n";
            answer++;
        }
    }
    cout << answer << "\n";
    return 0;
}