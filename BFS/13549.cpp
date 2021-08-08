#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int arr[100001];

int start,target;
int dir[2] = {1,-1};

int BFS(){
    priority_queue<int> a;
    a.push(start);
    arr[start] = 1;
    while(!a.empty()){
        int cur = a.top();
        if(cur == target){
            return arr[cur] -1;
        }
        a.pop();
        for(int i =0; i < 3; i++){
            if(i == 0){
                int next = 2*cur;
                if(next < 0 || next >100000 || arr[next] != 0 ){
                    continue;
                }
                arr[next] = arr[cur];
                printf("%d \n",next);
                a.push(next);
            }else{
                int next = cur+ dir[i-1];
                if(next < 0 || next >100000 || arr[next] != 0){
                    continue;
                }
                arr[next] = arr[cur] + 1;
                printf("%d \n",next);
                a.push(next);
            }
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
    int result = BFS();
    printf("%d\n",result);

    return 0;
}