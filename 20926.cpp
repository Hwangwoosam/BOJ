#include <iostream>
#include <vector>
#include <string>

using namespace std;

int EscapeIce(vector<string> map, pair<int,int> tera){
    int answer = 0;

     



    return answer;
}

int main(){
    int w,h,result;
    vector<string> map;
    pair<int,int> tera;
    pair<int,int> end;
    cin >> w >> h;
    for(int i = 0; i < h; i++){
        string inp;
        cin >> inp;
        for(int j = 0; j < w; j++){
            if(inp[j] == 'T'){
                tera.first = i;
                tera.second = j;
                inp[j] = '0';
            }else if(inp[j] == 'E'){
                end.first = i;
                end.second = j;
                inp[j] = '0';
            }
        }
        map.push_back(inp);
    }

    result = EscapeIce(map,tera);

    cout << result << "\n";

    return 0;
}