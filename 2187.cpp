#include <iostream>
#include <cmath>

using namespace std;

int r[1000], c[1000], s[1000];

int main(){
    int n,a,b;

    cin >> n >> a >> b;

    int ans = 0;
    for(int i = 0; i < n; i++) cin >> r[i] >> c[i] >> s[i];
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(abs(r[i] - r[j]) < a && abs(c[i] - c[j]) < b) ans = max(ans,abs(s[i] - s[j]));
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}