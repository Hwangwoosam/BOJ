#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int n;
vector<char> result;

int main(){
    string inp;
    
    getline(cin,inp);
    n = stoi(inp);

    for(int i = 0; i < n; i++){
        string inp;
        getline(cin,inp);
        istringstream iss(inp);

        string s,t;

        iss >> s >> t;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == 'x' || s[j] == 'X'){
                if(t[j] > '0' && t[j] < '9'){
                    result.push_back(t[j]);
                }else{
                    result.push_back(toupper(t[j]));
                }
            }
        }
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i];
    }
    cout << "\n";

    return 0;
}