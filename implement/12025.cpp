#include <iostream>
#include <string>

using namespace std;

int main(){
    string inp;
    long long k,m = 1;
    cin >> inp >> k;

    int inpSize = inp.length();
    for(int i = 0; i < inpSize; i++){
        if(inp[i] == '1' || inp[i] == '6'){
            inp[i] = '1';
            m *= 2;
        }else if(inp[i] == '2' || inp[i] == '7'){
            inp[i] = '2';
            m *= 2;
        }
    }

    if(k > m || k < 0){
        cout << -1 << "\n";
    }else{
        k -= 1;
        for(int i = inpSize-1; i >= 0; i--){
            if(inp[i] == '1'){
                if(k%2 == 1){
                    inp[i] = '6';
                }
                k /= 2;
            }else if(inp[i] == '2' ){
                if(k%2 == 1){
                    inp[i] = '7';
                }
                k /= 2;
            }
        }
        cout << inp << "\n";
    }

    return 0;
}