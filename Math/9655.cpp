#include <iostream>

int arr[1001];
int n;

using namespace std;;

int main(){
    cin >> n;
    
    if (n%2 == 0){
        cout << "CY\n";
    }else{
        cout << "SK\n";   
    }

    return 0;
}