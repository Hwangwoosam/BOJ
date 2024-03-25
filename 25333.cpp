#include <iostream>

using namespace std;

int getGCD(int a,int b){
    if(a < b){
        int tmp = b;
        b = a;
        a = tmp;
    }

    while(b > 0){
        int r = a % b;
        a = b;
        b = r; 
    }

    return a;
}
// <-- : A , --> : B, range = X
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t ; i++){
        int a,b,x;
        cin >> a >> b >> x;
        int answer = x/getGCD(a,b);
        cout << answer << "\n";
    }

    return 0;
}