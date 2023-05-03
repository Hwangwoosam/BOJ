#include <iostream>

int n;
int arr[1001];

// 0 : increase , 1: decrease
int ans[2][1001];

int main(){
    std::cin >> n;
    
    for(int i = 1; i <= n; i++){
        std::cin >> arr[i];
    }
     
    for(int i = 1; i <= n; i++){
        ans[0][i] = 1;

        for(int j = 1; j <= i; j++){
            if(arr[i] > arr[j]){
                ans[0][i] = std::max(ans[0][i],ans[0][j]+1);
            }
        }
    }

    for(int i = n; i >=1; i--){
        ans[1][i] = 1;
        
        for(int j = n; j >= i; j--){
            if(arr[i] > arr[j]){
                ans[1][i] = std::max(ans[1][i],ans[1][j]+1);
            }
        }
    }

    int result = 0;
    for(int i = 1; i <=n;i++){

        result = std::max(result,ans[0][i] + ans[1][i] - 1);
    }

    std::cout << result << "\n";


    return 0;
}