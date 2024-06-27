#include <iostream>
#include <vector>

using namespace std;

long long n,k;

vector<int> node[100001];
int childIdx[100001];
int indegree[100001];
long long result[100001];

void findNext(int idx, long long k){
    result[idx] = result[idx] + k;

    int childNum = node[idx].size();

    if(indegree[idx] > 1){
        indegree[idx]--;
        return;
    }

    if(childNum > 0){
        long long nK = result[idx] / childNum;
        long long nleft = result[idx] % childNum;

        for(int i = 0; i < childNum; i++){
            if(nleft > 0){
                findNext(node[idx][i],nK + 1);
                nleft--;
            }else{
                findNext(node[idx][i],nK);
            }
        }
    }
}

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        for(int j = 0; j < p; j++){
            int nextWorker;
            cin >> nextWorker;
            indegree[nextWorker]++;
            node[i].push_back(nextWorker);
        }
    }
    
    findNext(1,k);


    for(int i = 1; i <= n; i++){
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}