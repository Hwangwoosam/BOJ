#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    string inp;
    cin >> inp;

    int inpSize = inp.length();

    long long time = 0;
    for(int i = 0; i < inpSize; i++){
        if(i == n-1){
            time += inp[i] - 'a' + 1;
            break;
        }

        long long cnt = 26;
        for(int j = i+2; j < n; j++)  cnt = cnt*26 + 26;
        

        time += (inp[i] - 'a') * cnt + (inp[i] -'a' +1);
    }

    cout << time << "\n";
    return 0;
}