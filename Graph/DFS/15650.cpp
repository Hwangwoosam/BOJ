#include <iostream>

int n,m ; 
int arr[8];

void dfs(int num, int size){
    if(size == m){
        for(int i = 0; i < m; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }else{
        for(int i = num; i <= n; i++){
            arr[size] = i;
            dfs(i+1,size+1);
        }
    }

}

int main(){
    std::cin >> n >> m;
    dfs(1,0);


    return 0;
}