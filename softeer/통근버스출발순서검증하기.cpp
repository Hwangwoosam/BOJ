#include <iostream>
#include <cstring>

using namespace std;

int n;
int bus[5001];
int arr[5001][5001];
long long answer = 0;

// i < j < k
// ak < ai < aj;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> bus[i];
    }
    //        j ------------ n-1 중 번호가 X보다 작은 개수 즉 ak 찾기
    for(int j = n-2; j >= 0; j--){  
        for(int x = 1; x  <= n; x++){ 
            if(bus[j+1] < x){
                arr[x][j] = arr[x][j+1] + 1;
            }else{
                arr[x][j] = arr[x][j+1];
            }
        }
    }

    // i < j && ai < aj 케이스 찾기
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            if(bus[i] < bus[j]){
                answer += arr[bus[i]][j];
            }
        }
    }

    cout << answer << "\n";
    return 0;
}