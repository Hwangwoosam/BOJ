#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);

    long long sx,sy,ex,ey;
    int n;
    cin >> n;
    cin >> sx >> sy >> ex >> ey;

    long long val = LONG_MAX;
    long long ans = 0;

    for(long long i = 1; i <= n; i++){
        int m;
        cin >> m;
        long long distSum = 0;
        long long prevX = sx;
        long long prevY = sy;

        for(int j = 0; j < m; j++){
            long long x,y;
            cin >> x >> y;
            distSum += abs(prevX-x) + abs(prevY-y);
            prevX = x;
            prevY = y;
        }
        distSum += abs(ex-prevX) + abs(ey-prevY);
        
        if(val >= distSum){
            val = distSum;
            ans = i;
        }
    }

    cout << ans;
    return 0;
}