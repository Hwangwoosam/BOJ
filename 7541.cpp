#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int factor[] = {9,3,7};

int main() {
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++){
        string inp;
        cin >> inp;
        
        int inpSize = inp.size();
        int missingIdx = 0;
        int missFactorIdx = 0;
        int factorIdx = 0;
        int checkSum = 0;
        for(int j = inpSize-1; j >= 0; j--){
            char c = inp[j];
            
            if(c == '?'){
                missingIdx = j;
                missFactorIdx = factorIdx;
            }else{
                checkSum += (c-'0')*factor[factorIdx];
            }
            
            factorIdx = (factorIdx+1)%3;
        }

        for(int j = 0; j < 10; j++){
            if((checkSum + j*factor[missFactorIdx])% 10 == 0){
                inp[missingIdx] = j+'0';
                break;
            }
        }


        cout <<"Scenario #" << i <<": \n";
        cout << inp << "\n\n";
    }
    return 0;
}