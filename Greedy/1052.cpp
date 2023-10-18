#include <iostream>

using namespace std;


// n = 1, {1} 1
// n = 2, {2} 1
// n = 3, {2,1} 2
// n = 4, {2,2} -> {4} 1
// n = 5, {2,2,1} -> {4,1} 2
// n = 6, {2,2,2} -> {4,2} 2
// n = 7, {4,2,1} 3
// n = 8, {8} 1
// n = 9, {8,1} 2
int CountWater(int n){
    int cnt = 0;
    while(n > 0){
        if(n%2 == 1) cnt++;

        n /= 2;
    }

    return cnt;
}

void findCnt(int n, int k){
    if(n <= k ){
        cout << 0 << "\n";
    }else{
        int answer = 0;
        while(1){
            int waterCnt = CountWater(n);
            
            if(k >= waterCnt) break;

            n++;
            answer++;
        }

        cout << answer << "\n";
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    findCnt(n,k);

    return 0;
}