#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long arr[100001];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr,arr+n);
    
    int cnt = 0;
    long long maxVal = LLONG_MIN;
    int maxCnt = 0;

    for(int i = 0; i < n; i++){
        if(i == 0 || arr[i-1] == arr[i]) cnt++;
        else{
            if(cnt > maxCnt){
                maxCnt = cnt;
                maxVal = arr[i-1];
            }
            cnt = 1;
        }
    }
    if(cnt > maxCnt) maxVal = arr[n-1];
    cout << maxVal << "\n";

    return 0;
}