#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main(){
    int rh,sh,rv,sv;
    int n;

    cin >> rh >> rv >> sh >> sv;

    cin >> n;


    int minPrice = INT_MAX;
    for(int i = 0; i < n ; i++){
        int rhi,rvi,shi,svi,pi;
        cin >> rhi >> rvi >> shi >> svi >> pi;

        int w = max(ceil((double)rh/rhi),ceil((double)sh/shi));
        int h = max(ceil((double)rv/rvi),ceil((double)sv/svi));
        minPrice = min(minPrice, w*h*pi);

        w = max(ceil((double)rh/rvi),ceil((double)sh/svi));
        h = max(ceil((double)rv/rhi),ceil((double)sv/shi));
        minPrice = min(minPrice, w*h*pi);
    }


    cout << minPrice << "\n";
    return 0;
}