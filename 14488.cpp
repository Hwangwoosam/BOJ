#include <iostream>
#include <cfloat>
#include <vector>

using namespace std;

int main(){

    int n;
    double t;
    cin >> n >> t;

    vector<int> loc(n,0);
    for(int i = 0; i < n; i++) cin >> loc[i];
    
    double minRange = DBL_MIN;
    double maxRange = DBL_MAX;

    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        minRange = max(minRange,v*(-t) + loc[i]);
        maxRange = min(maxRange,v*(t)+loc[i]);
    }

    if(minRange > maxRange + 1e-04) cout << "0\n";
    else cout << "1\n";

    return 0;
}