#include <iostream>
#include <vector>
#include <set>

using namespace std;

long long oper(long long a){
    return ((a & 1) ? (a << 1) : (a >> 1)) ^ 6;
}


int main(){
    long long x,n;
    set<long long> nums;
    vector<long long> trace;

    cin >> x >> n;
    while(n--){
        x = oper(x);
        if(nums.count(x)) break;
        nums.insert(x);
    }

    if(n < 0) cout << x << "\n";
    else{
        trace.push_back(x);
        long long st = oper(x);

        while(st ^ x){
            trace.push_back(st);
            st = oper(st);
        }

        long long cycLen = trace.size();
        cout << trace[(n+cycLen)%cycLen] << "\n";
    }
    return 0;
}