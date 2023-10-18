#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n; 

bool hatePerson[101][101];
int visited[101];

void BFS(){
    vector<int> a,b;
    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(visited[i] != 0) continue;
        
        visited[i] = 1;
        q.push(i);

        while(!q.empty()){
            int cur = q.front();

            q.pop();

            for(int i = 1; i <= n; i++){

                if(visited[i] != 0) continue;
                
                if(hatePerson[cur][i] == true){
                    visited[i] = visited[cur] * (-1);
                    q.push(i);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(visited[i] == 1){
            a.push_back(i);
        }else if(visited[i] == -1){
            b.push_back(i);
        }
    }

    cout << a.size() << "\n";
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << "\n";

    cout << b.size() << "\n";
    for(int i = 0; i < b.size(); i++){
        cout << b[i] << " ";
    }
    cout << "\n";
}

int main(){
    cin >> n;
    // i 번째 
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;

        for(int j = 0; j < num ; j++){
            int idx;
            cin >> idx;
            hatePerson[i][idx] = true;
            hatePerson[idx][i] = true;
        }
    }

    BFS();

    return 0;
}