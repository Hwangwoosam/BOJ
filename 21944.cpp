#include <iostream>
#include <set>

using namespace std;

set<pair<int,int>> algorithm[101]; //G : {난이도,문제번호} recommend G x
set<int> level[101]; // 난이도 : 문제번호 recommend2 x /
pair<int,int> problem[100001];

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int p,l,g;
        cin >> p >> l >> g;
        algorithm[g].insert({l,p});
        level[l].insert(p);
        problem[p] = {l,g};
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string cmd;
        cin >> cmd;

        if(cmd == "recommend"){
            int g,x;
            cin >> g >> x;
            if(x == 1){
                auto p = prev(algorithm[g].end());
                cout << p->second << "\n";
            }else if(x == -1){
                auto p = algorithm[g].begin();
                cout << p->second << "\n";
            }
        }else if(cmd == "recommend2"){
            int x;
            cin >> x;
            if(x == 1){
                for(int i = 100; i >=1 ; i--){
                    if(level[i].empty()) continue;
                    cout << *prev(level[i].end()) << "\n";
                    break;
                }
            }else if(x == -1){
                for(int i = 1; i <= 100; i++){
                    if(level[i].empty()) continue;
                    cout << *level[i].begin() << "\n";
                    break;
                }
            }
        }else if(cmd == "recommend3"){
            int x,l;
            cin >> x >> l;

            int res = -1;
            if(x == 1){
                for(int i = l;  i <= 100; i++){
                    if(level[i].empty()) continue;
                    res = *level[i].begin();
                    break;
                }
            }else if(x == -1){
                for(int i = l-1; i >=1; i--){
                    if(level[i].empty()) continue;
                    res = *prev(level[i].end());
                    break;
                }
            }
            cout << res << "\n";
        }else if(cmd == "add"){
            int p,l,g;
            cin >> p >> l >> g;
            algorithm[g].insert({l,p});
            level[l].insert(p);
            problem[p] = {l,g};
        }else if(cmd == "solved"){
            int p;
            cin >> p;
            int l = problem[p].first;
            int g = problem[p].second;
            algorithm[g].erase({l,p});
            level[l].erase(p);
        }
    }

    return 0;
}