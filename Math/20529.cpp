#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int t;

int getDistance(string a,string b){
    int distance = 0;
    for(int i = 0; i < 4; i++){
        if(a[i] != b[i]){
            distance++;
        }
    }
    // cout << a << " " << b << ": " << distance << "\n";
    return distance;
}

int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        vector<string> mbti;
        
        cin >> n;
        for(int j = 0; j < n; j++){
            string inp;
            cin >> inp;
            mbti.push_back(inp);
        }

        if(n > 32){
            cout << "0\n";
            continue;
        }else{
            int result = 100;
            for(int i = 0; i < n; i++){
                for(int j = i+1; j <n; j++){
                    for(int k = j+1; k < n; k++){
                       result = min(result,getDistance(mbti[i],mbti[j])+getDistance(mbti[j],mbti[k]) + getDistance(mbti[i],mbti[k])); 
                    }
                }
            }

            cout << result << "\n";
        }
    }


    return 0;
}