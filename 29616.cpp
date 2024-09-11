#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int gcd(int a, int b){
    while(b != 0)
    {   
        int tmp = b;
        b = a%b;
        a = tmp;
    }

    return a;
}

int getGroupGcd(vector<int> arr){
    int res = arr[0];

    int arrSize = arr.size();
    for(int i = 1; i < arrSize; i++) res = gcd(res,arr[i]);

    return res;
}


int main(){
    int n,p;
    cin >> n >> p;
    vector<int> past(n);
    vector<int> cur(n);

    for(int i = 0; i < n; i++) cin >> past[i];
    for(int i = 0; i < n; i++) cin >> cur[i];

    int pastGcd = getGroupGcd(past);
    int curGcd = getGroupGcd(cur);

    long long beforeRatio = 0;
    long long curRatio = 0;
    for(int i = 0; i < n; i++){
        past[i] /= pastGcd;
        cur[i] /= curGcd;
        beforeRatio += past[i];
    }


    long long maxVal = 0;
    for(int i = 0; i < n; i++){
        long long r = (long long)(ceil((double)past[i]/cur[i]));
        maxVal = max(maxVal,r);
    }

    for(int i = 0; i < n; i++) curRatio += cur[i]*maxVal;

    cout << beforeRatio << " " << curRatio << "\n";

    return 0;
}