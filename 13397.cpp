#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

int ans = 1e5;
int n,m;

bool check(int val){
    int cnt = 1;
    int minVal = nums[0],maxVal = nums[0];
    for(int i = 1; i < n; i++){
        minVal = min(minVal,nums[i]);
        maxVal = max(maxVal,nums[i]);

        int diff = maxVal - minVal;
        if(diff <= val) continue;
        cnt ++;

        minVal = nums[i];
        maxVal = nums[i];   
    }
    
    return cnt <= m;
}

void binarySearch(){
    int left = 0;
    int right = 10001;

    while(left <= right){
        int mid = (left + right)/2;
        if(check(mid)) {
            if(ans > mid) ans = mid;
            right = mid-1;
        }else left = mid+1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    nums.resize(n,0);
    for(int i = 0; i < n; i++) cin >> nums[i];
    binarySearch();
    cout << ans << "\n";

    return 0;
}