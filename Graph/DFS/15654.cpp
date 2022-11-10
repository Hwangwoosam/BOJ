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
        //i 는 개수
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                visited[i] = true;
                arr[size] = numbers[i-1];
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
    std::sort(numbers,numbers + n);

    dfs(1,0);

    return 0;
}