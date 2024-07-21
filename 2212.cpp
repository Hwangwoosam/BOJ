    #include <iostream>
    #include <algorithm>
    #include <cmath>
    #include <vector>

    using namespace std;

    vector<int> tower;
    vector<int> diff;

    int main(){
        int n,k;

        cin >> n >> k;
        for(int i = 0; i < n; i++){
            int loc;
            cin >> loc;
            tower.push_back(loc);
        }

        sort(tower.begin(),tower.end());

        for(int i = 1; i < n; i++){
            int tmp = abs(tower[i] - tower[i-1]);
            diff.push_back(tmp);
        }
        sort(diff.begin(),diff.end(),greater<>());

        long long sum = 0;

        for(int i = k-1; i < n-1; i++){
            sum += diff[i];
        }

        cout << sum << "\n";
        return 0;
    }