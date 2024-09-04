#include <iostream>
#include <vector>

using namespace std;

long long sum[100000];
long long diff[100000];

int main(){
    int n;
    cin >> n;

    vector<int> nums(n,0);
    vector<long long> ans;
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    sum[0] = nums[0];
    diff[0] = nums[0];

    for(int i = 1; i < n; i++){
        sum[i] = sum[i-1] + nums[i];
        diff[i] = diff[i-1] + (2*i + 1)*nums[i];
    }

    //n^2
    ans.push_back(nums[0]);
    for(int i = 1;  i < n; i++){
        ans.push_back(ans[i-1] + 2*(i+1)*sum[i] - diff[i]);
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}