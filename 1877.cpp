#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<int, int> primeFactorizationSmall(int m) {
    map<int, int> factorization;
    
    for (int i = 2; i * i <= m; i++) {
        while (m % i == 0) {
            factorization[i]++;
            m /= i;
        }
    }
    if (m > 1) {
        factorization[m]++;
    }
    return factorization;
}

int main() {
    int m;
    cin >> m;
    
    int nMax, nMin, mMax, mMin;
    
    // n 값 계산
    if (m <= 3) {
        nMax = nMin = 1;
    } else {
        int q = m / 3;
        int r = m % 3;
        nMin = q + (r <= 1 ? 0 : 1);
        nMax = q + (r == 0 ? 0 : 1);
    }
    
    // m 값 계산
    if (m == 1) {
        mMax = mMin = 1;
    } else {
        map<int, int> factorization = primeFactorizationSmall(m);
        mMax = 0;
        
        for (const auto& pair : factorization) {
            mMax += pair.second;
        }
        
        mMin = mMax;
        for (const auto& pair : factorization) {
            if(pair.first == 2){
                mMin -= pair.second / 2;
            }
        }
    }
    
    cout << nMax << " " << nMin << " " << mMax << " " << mMin << endl;
    
    return 0;
}