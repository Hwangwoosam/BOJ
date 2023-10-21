#include <iostream>
#include <algorithm>

using namespace std;

int n,d,k,c;
int arr[30000];
int rawfish[3001];

int main(){
    cin >> n >> d >> k >> c;
    int result = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int left = 0, right = k-1;
    for(int i = 0; i < k; i++){
        rawfish[arr[i]]++;
        if(rawfish[arr[i]] == 1) cnt++;
    }

    rawfish[c]++;
    if(rawfish[c] == 1) cnt++;

    while(left<n){
        result = max(result,cnt);
        if(--rawfish[arr[left++]] == 0) cnt--;
        right = (right+1)%n;
        if(++rawfish[arr[right]] == 1) cnt ++;
    }

    cout << result << "\n";
    return 0;
}