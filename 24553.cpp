#include <iostream>
#include <vector>

using namespace std;

bool isPelindrome(long n){
    vector<long long> v;
    long long t = n;
    while(t > 0){
        // cout << t << "\n";
        v.push_back(t%10);
        t = t/10;
    }

    int vSize = v.size();
    // 0 1 2 3
    // 0 1

    // cout <<"vSize : " << vSize << "\n";
    for (int i = 0; i < vSize; i++) {
        // cout << i << " " << vSize-1-i << "\n";
        // cout << v[i] << " " << v[vSize-1-i] << "\n";
		if (v[i] != v[vSize - 1 - i])
			return false;
	}

    return true;
}

void playGame(long long n){
    if(isPelindrome(n)){
        cout << "0\n";
    }else if(n%10 == 0){
        cout << "1\n";
    }else{
        cout << "0\n";
    }
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t ; i++){
        long long n;
        cin >> n;
        playGame(n);
    } 

    return 0;
}