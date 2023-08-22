#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int nums[9];
int arr[9];
bool visited[9];

void dfs(int idx,int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }  

    int last = -1;
    
    for(int i = idx; i < n; i++){
        if(last != nums[i]){
            last = nums[i];
            arr[cnt] = nums[i];
            visited[i] = true;
            dfs(i,cnt+1);
            visited[i] = false;
        }
    }


}


int main(){
    cin >> n >> m;


    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums,nums+n);

    dfs(0,0);

    return 0;
}