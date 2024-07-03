#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n,m;

    vector<int> material;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        material.push_back(num);
    }

    sort(material.begin(),material.end());

    int st = 0,end = n-1;
    int cnt = 0;
    while(st < end){
        int sum = material[st] + material[end];

        if(sum < m) st++;
        else if(sum > m) end--;
        else{
            st++;
            end--;
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}