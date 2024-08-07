#include <iostream>

using namespace std;

int main(){
    int n,m,l;
    cin >> n >> m >> l;

    int totalwidth = 0;
    for(int i = 0; i < n; i++){
        int b;
        cin >> b;
        totalwidth += b;
    }

    if(m==totalwidth) cout << "0\n";
    else if(m < totalwidth) cout << "-1\n";
    else if(l <= totalwidth || m-totalwidth >=l) cout << "1\n";
    else cout << "-1\n";

    return 0;
}