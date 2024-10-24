#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <set>

using namespace std;

stack<int> st;
bool check[201];
vector<pair<int,int>> bracket;
set<string> ans;

int main(){
    string inp;
    cin >> inp;

    int inpSize = inp.length();
    for(int i = 0; i < inpSize; i++){
        if(inp[i] == '(') st.push(i);
        else if(inp[i] == ')'){
            bracket.push_back({st.top(),i});
            st.pop();
        }
    }

    int bracketSize = bracket.size();
    vector<int> zeros(2*bracketSize,0);
    fill_n(zeros.begin(),bracketSize,1);
    sort(zeros.begin(),zeros.end());
    
    do{
        memset(check,0,sizeof(check));
        string str = "";
        for(int i = 0; i < bracketSize; i++){
            if(zeros[i]){
                check[bracket[i].first] = true;
                check[bracket[i].second] = true;
            }
        }

        for(int i = 0; i < inpSize; i++){
            if(check[i]) continue;
            str += inp[i];
        }

        ans.insert(str);
        // cout << "\n";

    }while(next_permutation(zeros.begin(),zeros.end()));

    for(auto elem: ans){
        if(elem == inp) continue;
        cout << elem << "\n";
    }

    return 0;
}