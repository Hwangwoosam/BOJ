#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> ans;

int main(){
    string inp;
    getline(cin,inp);
    stringstream ss(inp);
    
    string a,b;
    ss >> a >> b;

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    int aLen = a.length();
    int bLen = b.length();
    int aIdx = 0, bIdx = 0;
    int carry = 0;
    while(aIdx < aLen || bIdx < bLen){

        if(bIdx >= bLen){
            // cout << "1\n";
            while (aIdx < aLen)
            {   
                int sum = a[aIdx] - '0' + carry;
                carry = sum/10;
                sum = sum%10;
                ans.push_back(sum);
                aIdx++;
            }
            break;
        }else if(aIdx >= aLen){
            // cout << "1\n";
            while (bIdx < bLen)
            {   
                int sum = b[bIdx] - '0' + carry;
                carry = sum/10;
                sum = sum%10;
                ans.push_back(sum);
                bIdx++;
            }
            break;
        }


        int aNum = a[aIdx] - '0';
        int bNum = b[bIdx] - '0';

        int sum = aNum + bNum + carry;

        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    
        aIdx++;
        bIdx++;
    }

    if(carry != 0) ans.push_back(carry);

    int vLen = ans.size()-1;
    for(int i = vLen; i >= 0; i--){
        cout << ans[i];
    }
    cout << "\n";

    return 0;
}