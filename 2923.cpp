#include <iostream>
#include <cstring>

using namespace std;

int a[101],b[101],ca[101],cb[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--){
        int aIdx,bIdx;
        cin >> aIdx >> bIdx;
        a[aIdx]++;
        b[bIdx]++;

        memcpy(ca,a,sizeof(a));
        memcpy(cb,b,sizeof(b));
        
        int pa = 1, pb = 100;
        int ret = 0;
        while(pa < 100 && pb > 0){
            while(ca[pa] == 0 && pa < 100) pa++;
            while(cb[pb] == 0 && pb > 0) pb--;
        
            if(pa == 100 || pb == 0) break;

            ret = max(ret,pa+pb);
            
            if(ca[pa] > cb[pb]){
                ca[pa] -= cb[pb];
                cb[pb] = 0;
            }else{
                cb[pb] -= ca[pa];
                ca[pa] = 0;
            }
        }

        cout << ret << "\n";
    }

    return 0;
}