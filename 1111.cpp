#include <iostream>

using namespace std;

int n;
int num[50];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    if(n == 1){
        cout << "A\n";
    }else if(n == 2){
        if(num[0] == num[1]){
            cout << num[1] << "\n";
        }else{
            cout << "A\n";
        }
    }else{
        int a = 0;

        if(num[1] - num[0] != 0){
            a = (num[2] - num[1]) / (num[1] - num[0]) ;
        }

        int b = num[1]-num[0]*a;

        for(int i = 1; i < n; i++){
            if(num[i] != num[i-1]*a + b){
                cout << "B\n";
                return 0;
            }
        }

        cout << num[n-1] * a + b << "\n";
    }


    return 0;
}