#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int x[200001];
int y[200001];


int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,q;

    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= n; i++) cin >> y[i];

    vector<double> right(n);
    vector<double> left(n);

    for(int i = 2; i <= n; i++){
        double distToRight = sqrt(pow(abs(x[i]-x[i-1]),2) + pow(abs(y[i] - y[i-1]),2));

        if(y[i] > y[i-1]) distToRight *= 3;
        else if(y[i] == y[i-1]) distToRight *=2;

        right[i] = right[i-1] + distToRight;
    }

    for(int i = n-1; i >= 0; i--){
        double distToLeft = sqrt(pow(abs(x[i]-x[i+1]),2) + pow(abs(y[i] - y[i+1]),2));

        if(y[i] > y[i+1]) distToLeft *= 3;
        else if(y[i] == y[i+1]) distToLeft *=2;

        left[i] = left[i+1] + distToLeft;
    }

    cout << fixed;
    cout.precision(4);

    for(int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        if(a < b) cout << right[b] - right[a] << "\n";
        else cout << left[b] - left[a] << "\n";
    }
 

    return 0; 
}