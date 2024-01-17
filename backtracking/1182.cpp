#include <iostream>

using namespace std;

int n,s,answer = 0;
int num[20];
bool check[20];

void func(int cur,int sum){
    if(cur == n){
        if(sum == s) answer++;
        return;
    }
    func(cur+1,sum);
    func(cur+1,sum+num[cur]);
}

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    func(0,0);
    if(s == 0) answer--;
    cout << answer << "\n";

    return 0;
}