#include <iostream>

using namespace std;

int main(){
    int p1,p2,p3,x1,x2,x3;

    cin >> p1 >> p2 >> p3 >> x1 >> x2 >> x3;

    int end = p1*p2*p3;
    int ans = -1;
    for(int i = 1; i <= end; i++){
        if(i%p1 == x1 && i%p2 == x2 && i%p3 == x3){
            ans = i;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}