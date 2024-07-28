#include <iostream>
#include <vector>

using namespace std;

int getOperationCnt(vector<int>& a, vector<int>& b) {
    int n = a.size();
    vector<int> diff(n);
    
    for (int i = 0; i < n; i++) {
        diff[i] = a[i] ^ b[i];
    }
    
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (diff[i] != 0) {
            diff[i+1] ^= diff[i];
            cnt++;
        }
    }
    
    if (diff[n-1] != 0) {
        return -1; 
    }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    cout << getOperationCnt(a, b) << endl;

    return 0;
}