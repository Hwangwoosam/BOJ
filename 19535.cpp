#include <iostream>
#include <vector>

using namespace std;

vector<int> node[300001];
bool visited[300001];
int n;

int dNum,gNum;

void findTree(int cur, int prevDegree){
    visited[cur] = true;
    int degreeSize = node[cur].size();

    if(degreeSize >= 3){
        gNum += degreeSize * (degreeSize-1) * (degreeSize-2) / 6;
    }

    if(degreeSize >= 2){
        if(prevDegree != 0){
            dNum += prevDegree * (degreeSize - 1);
        }
    }

    prevDegree = degreeSize - 1;
    for(int i = 0; i < degreeSize; i++){
        int next = node[cur][i];
        if(visited[next]) continue;

        findTree(next,prevDegree);
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int s,e;
        cin >> s >> e;
        node[s].push_back(e);
        node[e].push_back(s);
    }
    
    findTree(1,0);

    if(dNum > gNum*3){
        cout << "D\n";
    }else if(dNum < gNum*3){
        cout << "G\n";
    }else{
        cout << "DUDUDUNGA\n";
    }

    return 0;
}