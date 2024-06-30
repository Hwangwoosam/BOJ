#include <iostream>
#include <algorithm>

using namespace std;

long long getDec(string str){
    long long ret = 0;

    int strSize = str.length();
    long long mul = 1;
    for(int i = strSize-1; i >= 0; i--){
        if(str[i] == '1'){
            ret += mul;
        }

        mul *= 2;
    }

    return ret;
}

string changeBinary(long long dec){
    string ret = "";
    while(dec){
        ret += dec%2 + '0';
        dec /= 2;
    }

    reverse(ret.begin(),ret.end());
    
    return ret;
}

int main(){
    string b1,b2;
    cin >> b1 >> b2;

    long long mult = getDec(b1) * getDec(b2); 
    cout << changeBinary(mult) << "\n";
    

    return 0;
}
