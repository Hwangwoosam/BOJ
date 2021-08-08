#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int arr[100001];

int start,target;

int BFS(){
    queue<int> a;
    a.push(start);
    arr[start] = 0;
    while(!a.empty()){
        int cur = a.front();
        a.pop();
        if(cur == target){
            return arr[cur];
        }
        if(cur + 1 <100001 && arr[cur+1] > arr[cur] + 1){
            arr[cur + 1] = arr[cur] + 1;
            a.push(cur+1);
        }
        if(cur - 1 >= 0 && arr[cur-1] > arr[cur] + 1){
            arr[cur - 1] = arr[cur] + 1;
            a.push(cur - 1);
        }
        if(cur*2 < 100001 && arr[cur*2] > arr[cur]){
            arr[cur*2] = arr[cur];
            a.push(cur*2);
        }
    }
    return -1;
}
int main(){
    ios_base :: sync_with_stdio(false); 
	cin.tie( NULL); 
	cout.tie(NULL);

    // freopen("test.txt","r",stdin);

    cin >> start >> target;
    for(int i = 0; i < 100001; i++){
        arr[i] = INT32_MAX;
    }
    int result = BFS();
    printf("%d\n",result);

    return 0;
}