#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int result, nums[10];
bool possible = false;

string word = "helowrd";
unordered_map<char,int> m;

int main(){
    cin >> result;
    for(int i = 0; i < 10; i++) nums[i] = i;

    do{
        for(int i = 0; i < 7; i++) m[word[i]] = nums[i];

        if(m['h'] == 0 || m['w'] == 0) continue;

        int a = m['h']*10000 + m['e']*1000 + m['l']*100 + m['l']*10 + m['o'];
        int b = m['w']*10000 + m['o']*1000 + m['r']*100 + m['l']*10 + m['d'];

        if(a+b == result){
            possible = true;
            cout << "  " << a << "\n";
            cout << "+ " << b << "\n";
            cout << "-------\n";
            for(int i = 0 ; i < 7-to_string(result).size(); i++) cout << " ";
            cout << result << "\n";
            break;
        }
    }while(next_permutation(nums,nums+10));

    if(!possible) cout << "No Answer\n";

    return 0;
}