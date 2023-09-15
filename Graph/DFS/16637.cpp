#include <iostream>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int n, answer = INT32_MIN;
string str;

int cal(int a, int b, char oper){
    int result = a;

    if(oper == '+'){
        result += b;
    }else if (oper == '*'){
        result *= b;
    }else if (oper == '-'){
        result -= b;
    }

    return result;
}

void dfs(int idx, int cur){
    if(idx > n - 1){
        answer = max(answer, cur);
        return;
    }

    char oper = (idx == 0) ? '+' : str[idx-1];

    if(idx + 2 < n){
        int bracket = cal(str[idx]-'0', str[idx+2]-'0', str[idx+1]);
        dfs(idx+4,cal(cur,bracket,oper));
    }

    dfs(idx+2,cal(cur,str[idx] - '0',oper));
}

int main(){
    cin >> n >> str;

    dfs(0,0);
    cout << answer << "\n";
    return 0;
}