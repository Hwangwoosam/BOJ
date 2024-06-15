#include <iostream>

using namespace std;

int t;

int main(){
    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        
        int plus = n/5;
        int left = n%5;
        while(plus--){
            cout << "++++ ";
        }

        while(left--){
            cout << "|";
        }
        cout << "\n";

    }

    return 0;
}