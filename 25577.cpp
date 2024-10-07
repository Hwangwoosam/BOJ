#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> sorted(n);
    unordered_map<int,int> idx;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sorted[i] = arr[i];
        idx[arr[i]] = i;
    }

    sort(sorted.begin(),sorted.end());
    int ans = 0;

    for(int i = 0; i < n; i++){
        if(sorted[i] == arr[i]) continue;
        int j = idx[sorted[i]];
        idx[sorted[i]] = i;
        idx[arr[i]] = j;

        swap(arr[i],arr[j]);
        ans++;
    }
    cout << ans << "\n";

    return 0;
}