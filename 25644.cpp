#include <iostream>
#include <climits>

using namespace std;

int main(){
    int n;

    cin >> n;

    long long minV = LONG_MAX, maxV = LONG_MIN;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        int price;
        cin >> price;

        if(minV > price){
            minV = price;
        }
        else if(minV < price) {
            maxV = price;
            ans = max(ans,maxV - minV);
        }
    }
    
    cout << ans << "\n";
    return 0;
}