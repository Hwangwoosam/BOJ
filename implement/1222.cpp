#include <cstdio>
#define MaxVal 2000001

long long int max(long long int a, long long int b){
    return a > b ? a : b;
}

int n;
int school[MaxVal] = {0};

int main(){

    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        int idx;
        scanf("%d",&idx);
        school[idx]++;
    }

    long long int team = 0;
    for(int i = 1; i <= MaxVal; i++){
        long long int cnt = 0;
        for(int j = 1; j*i <= MaxVal; j++){
            cnt += school[i * j];
        }

        if(cnt < 2 ) continue;
        team = max(team, cnt * i);
    }

    printf("%lld\n",team);
    return 0;
}