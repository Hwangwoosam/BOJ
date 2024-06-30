#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    
    cin >> str;

    int num = 1, idx = 0;

    while(num < 30000){
        string num2str = to_string(num);

        for(int i = 0; i < num2str.length(); i++){
            if(str[idx] == num2str[i]){
                idx++;
            }

            if(idx == str.length()){
                cout << num << "\n";
                return 0;
            }
        }

        num++;
    }

    return 0;
}