#include <iostream>
#include <vector>

int N;

int arr[100001];
std::vector<int> v[100001];
bool visited[100001];

void dfs(int start){
    visited[start] = true;

    for(int i = 0; i < v[start].size(); i++){
        int next = v[start][i];
        if(!visited[next]){
            arr[next] = start;
            dfs(next);
        }
    }
}

int main (){
    std::cin >> N;

    for(int i = 0; i < N-1; i++){
        int from,to;
        std::cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
        visited[i+1] = false;
    }

    dfs(1);

    for(int i = 2; i <= N; i++) std::cout << arr[i] << "\n";
    
    return 0;
}