#include <iostream>

using namespace std;

int answer = 10000;

long long a,b;

void bfs(long long num,int cnt){
    if( num > b) return;

    if(num == b){
        answer = min(answer,cnt);
    }

    bfs(num*2,cnt+1);
    bfs(num*10 +1,cnt+1);
}

int main(){
    cin >> a >> b;

    bfs(a,1);

    if(answer == 10000){
        answer = -1;
    }
    cout << answer << "\n";
    return 0;
}