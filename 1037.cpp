#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> divs;
    int answer = 0;
    for(int i = 0; i < n; i++){
        int div;
        cin >> div;
        divs.push_back(div);
    }

    sort(divs.begin(),divs.end());

    if(n == 1){
        answer = divs[0]*divs[0];
    }else{
        answer = divs.front()*divs.back();
    }

    cout << answer << "\n";

    return 0;
}

2 3 4 6 8 12