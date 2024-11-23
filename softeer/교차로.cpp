#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

// 북서남동  c,b,a,d
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

long answer[200001];
vector<pair<int,int>> cars[4];
int n;

int main(){
    cin >> n;

    cin.ignore(2);

    int prev = -1;
    for(int i = 0; i < n; i++){
        string inp;
        getline(cin,inp);
        istringstream iss(inp);
        int t;
        char dir;
        iss >> t >> dir;

        if(prev == -1) prev = t;
        
        if(dir == 'A'){
            cars[2].push_back({i,t});
        }else if(dir == 'B'){
            cars[1].push_back({i,t});
        }else if(dir == 'C'){
            cars[1].push_back({i,t});
        }else if(dir == 'D'){

        }

        cout << t << " " << dir << "\n";
    }

    return 0;
}