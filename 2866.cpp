#include <iostream>
#include <vector>
#include <set> 

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int r,c;
    cin >> r >> c;
    
    vector<string> table(r);

    for(int i = 0; i < r; i++) cin >> table[i];

    set<string> s;
    string str[c];
    for(int i = r-1; i >= 0; i--){
        for(int j = 0; j < c; j++){
            str[j] += table[i][j];
            s.insert(str[j]);
        }

        if(s.size() == c){
            cout << i << "\n";
            break;
        }

        s.clear();
    }    
    return 0;
}