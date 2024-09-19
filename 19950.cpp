#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n;
int sx,sy,sz,ex,ey,ez;

int main(){
    cin >> sx >> sy >> sz >> ex >> ey >> ez;
    cin >> n;

    int totalLen = sqrt(pow(ex-sx,2) + pow(ey-sy,2) + pow(ez-sz,2)); 

    vector<int> stick(n,0);
    bool overSumLen = false;
    int sum = 0;

    for(int i = 0; i < n; i++){
        cin >> stick[i];
        sum += stick[i];
    }

    if(totalLen > sum) overSumLen = true;

    sort(stick.begin(),stick.end(),greater<>());

    if(overSumLen) cout << "NO\n";
    else if(totalLen == sum) cout <<"YES\n";
    else{
        int subSum = 0;
        for(int i = 1; i < n; i++) subSum += stick[i];

        if(totalLen >= stick[0] - subSum) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}