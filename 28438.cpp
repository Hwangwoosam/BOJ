#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n,m,q;

    cin >> n >> m >> q;

    vector<int> row(n+1,0);
    vector<int> col(m+1,0);

    for(int i = 0; i < q; i++){
        int cmd,a,b;
        cin >> cmd >> a >> b;
        if(cmd == 1){
            row[a] += b;
        }else{
            col[a] += b;
        }
    }

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j <m; j++){
            cout << row[i+1] + col[j+1] << " ";
        }
        cout << "\n";
    }



    return 0;
}