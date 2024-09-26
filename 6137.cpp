#include <iostream>

using namespace std;

int getPriority(int left,int right, string s){
    while(left <= right){
        if(s[left] < s[right]) return -1;
        else if(s[left] > s[right]) return 1;
        left++;
        right--;
    }

    return 0;
}

int main(){
    int n;
    cin >> n;
    string s(n,'.');

    for(int i = 0; i < n; i++) cin >> s[i];
    
    int front = 0, back = n-1;
    int cnt = 0;
    while(cnt < n){
        int status = getPriority(front,back,s);    
        if(status == -1){
            cout << s[front++];
            cnt++;
        }else if(status == 1){
            cout << s[back--];
            cnt++;
        }else{
            cout << s[front++];
            cnt++;
        }

        if(cnt % 80 == 0 && cnt > 0) cout << "\n";
    }
}