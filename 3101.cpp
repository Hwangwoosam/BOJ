#include <iostream>

using namespace std;

int main(){
    long n,k;
    cin >> n >> k;

    long x = 0,y = 0;
    
    string cmd;
    cin >> cmd;

    long sum = 1;
    bool half = false; // false: right, true = left;
    long order;
    for(int i = 0; i < k; i++){
        if(cmd[i] == 'D') x++;
        else if(cmd[i] == 'R') y++; 
        else if(cmd[i] == 'U') x--;
        else if(cmd[i] == 'L') y--;

        long line = x+y;
        long base = 0;

        if(line <= n) base = line*(line+1) / 2;
        else{
            base = n*(n+1)/2 + (line-n)*(3*n - line-1)/2;
        }

        order = (line+1) %2 == 0 ? x+1 : y+1;
        if(line+1 > n){
            order -= line + 1 - n;
        }

        sum += base + order;
    }

    cout << sum<< "\n";

    return 0;
}