#include <iostream>

using namespace std;

int n;

int main(){
    cin >> n;

    bool check = false;

    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        if(num % 2 != i % 2) {
            check = true;
            break;
        }
    }

    if(check){
        cout << "NO\n";
    }else{
        cout << "YES\n";
    }

    return 0;
}