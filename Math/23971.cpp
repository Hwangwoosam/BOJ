#include<iostream>
#include<cmath>

using namespace std;

double h,w,n,m;

int main(){
    cin >> h >> w >> n >> m;   
    long long result = (long long)ceil(w/(m+1)) * (long long)ceil(h/(n+1));
    cout << result << "\n";

    return 0;
}