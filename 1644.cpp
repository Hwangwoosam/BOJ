#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool arr[4000000];

int main(){
    int n;
    cin >> n;

    vector<int> prime;

    for(int i = 2; i <= 4000000; i++){
        if(arr[i]) continue;
        prime.push_back(i);
        arr[i] = true;

        for(int j = 2*i ; j <= n; j += i){
            arr[j] = true;
        }
    }

    int st = 0, end = 0;
    long long sum = prime[st];
    int ans = 0;
    int pSize = prime.size();
    while(st <= pSize-1 && end <= pSize-1 ){
        // cout << st << " " << end << " = " << sum << "\n"; 
        if(sum < n){
            end++;
            sum += prime[end];
        }else if(sum == n){
            ans++;
            end++;
            sum += prime[end];
        }else{
            sum -= prime[st];
            st++;
        }
    }

    cout << ans << "\n";
    return 0;
}