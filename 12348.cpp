#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long n;
    cin >> n;

    long digit = to_string(n).size();
    
    long st = n - 9*digit;
    for(long i = st; i < n; i++){
        string curNum = to_string(i);
        long sum = i;
        
        int curNumSize = curNum.size();
        for(int j = 0; j < curNumSize; j++){
            sum += curNum[j]-'0';
        }

        if(sum == n){
            cout << i << "\n";
            return 0;
        }
    }

    cout << "0\n";

    return 0;
}