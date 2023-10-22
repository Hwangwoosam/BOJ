#include <iostream>

using namespace std;

bool num[1000001];

int main(){
    long long min,max;
    cin >> min >> max;
    for(long long i = 2; i*i <= max; i++){
        long long n = min / (i*i);
        if(min%(i*i)) n++;

        while(n*i*i <= max){
            num[n*i*i - min] = true;
            n++;
        }
    }

    int cnt = 0;
    for(int i = 0; i <= max - min; i++){
        if(!num[i]) cnt ++;
    }

    cout << cnt << "\n";
    return 0;
}