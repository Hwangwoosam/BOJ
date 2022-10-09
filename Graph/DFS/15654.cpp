#include <iostream>
#include <algorithm>

int n,m;
int numbers[8];
int arr[8];
bool visited[8];

void dfs(int num, int size){
    if(size == m){
        for(int i = 0; i < m; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }else{
        for(int i = 0; i < m; i++){
            if(!visited[i]){
                visited[i] = true;
                arr[i] = numbers[i];
                dfs(i+1,size+1);
                visited[i] = false;
            }
        }
    }
}

int main(){
    std::cin >> n >> m;
    for(int i = 0; i < n; i++){
        std::cin >> numbers[i];
    }
    std::sort(numbers,numbers + m);

    dfs(1,0);

    return 0;
}