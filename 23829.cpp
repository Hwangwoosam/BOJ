#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long sum[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,q;
    cin >> n >> q;

    vector<int> tree(n);
    for(int i = 0 ; i < n; i++){
        cin >> tree[i];
    }

    sort(tree.begin(),tree.end());

    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + tree[i-1];
    }

    for(int i = 0; i < q; i++){
        long long p;
        cin >> p;

        int lowerIdx = lower_bound(tree.begin(),tree.end(),p) - tree.begin();
        long long small = p*lowerIdx - sum[lowerIdx];
        long long big = sum[n] - sum[lowerIdx] - (p*(n-lowerIdx));
        cout << small + big << "\n";
    }
    
    return 0;
}