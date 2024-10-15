#include <iostream>
#include <climits>
#include <vector>

using namespace std;

long long sum[100001];

int main(){
    int n,k;
    cin >> n >> k;

    vector<int> nums;

    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        nums.push_back(num);
        sum[i] = sum[i-1] + num;
    }    

    int st = 0;
    int ans = INT_MIN;
    while(st+k <= n){
        long long val = sum[st+k] - sum[st];
        if(ans < val) ans = val;
        // cout << ans << "\n";
        st++;
    }

    cout << ans << "\n";
    return 0;
}