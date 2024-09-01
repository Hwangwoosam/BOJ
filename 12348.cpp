#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    int digit = to_string(n).size();
    
    int st = n - 9*digit;
    for(int i = st; i <= n; i++){
        long curNum = i;
        long sum = i;

        while(curNum > 0){
            sum += curNum%10;
            curNum /= 10;
        }

        if(sum == n){
            cout << i << "\n";
            return;
        }
    }

    cout << "0\n";

    return 0;
}