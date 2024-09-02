#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

set<string> s;
int alp[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        string inp;
        cin >> inp;

        memset(alp,0,sizeof(alp));
        s.clear();

        int inpSize = inp.length();
       
        for(int i = 0; i < inpSize; i++) alp[inp[i]-'a']++;
        vector<int> combi(inpSize,0);

        int cIdx = 0;
        for(int i = 0; i < 26; i++){
            if(alp[i] == 0) continue;

            while(alp[i] > 0){
                combi[cIdx] = i;
                alp[i]--;
                cIdx++;
            }
        }
    

        // 최대 10^12 
        do{
            string ret = "";
            for(int i = 0; i < inpSize; i++) ret += combi[i] + 'a';
            s.insert(ret);
        }while(next_permutation(combi.begin(),combi.end()));

        for(auto word : s){
            cout << word << "\n";
        }
    }

    return 0;
}