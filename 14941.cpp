#include <iostream>
#include <cmath>

using namespace std;

bool prime[100001];
int odd[100001];
int even[100001];

void init(){
    prime[1] = true;
    for(int i = 2; i < sqrt(100001); i++){
        if(prime[i]) continue;
        for(int j = i*i; j <= 100000; j+= i){
            prime[j] = true;
        } 
    }

    bool check = true;
    for(int i = 1; i <= 100000; i++){
        if(!prime[i]){
            if(check){ // 홀수번쨰
                check = false;
                odd[i] = 3*i + odd[i-1];
                even[i] = even[i-1] - i;
            }else{ // 짝수번째
                check = true;
                odd[i] = odd[i-1] - i;
                even[i] = 3*i + even[i-1];
            }
        }else{
            odd[i] = odd[i-1];
            even[i] = even[i-1];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    init();

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int s,e;
        cin >> s >> e;

        int firstPrime = 0;
        for(int i = s; i <= e; i++){
            if(!prime[i]){
                firstPrime = i;
                break;
            }
        }

        if(firstPrime == 0) cout << "0\n";
        else{
            if(odd[firstPrime] - odd[firstPrime - 1] > 0){ // 3*i 일 경우 > 0 
                cout << odd[e] - odd[s-1] << "\n";
            }else{
                cout << even[e] - even[s-1] << "\n";
            }
        }
    }

    return 0;
}