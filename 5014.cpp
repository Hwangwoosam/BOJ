#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;

int Floor[1000000];

int main(){
    ios_base :: sync_with_stdio(false); 
	cin.tie( NULL); 
	cout.tie(NULL);
   
    freopen("test.txt","r",stdin);

    int F,S,G,U,D;

    cin >> F >> S >> G >> U >> D;
    
    int range[2] = {U,-D};
    queue<int> a;
    Floor[S] = 1;
    a.push(S);
    while(!a.empty()){
        int cur = a.front();
        a.pop();
        if(cur == G){
            printf("%d\n",Floor[cur]-1);
            return 0;
        }

        for(int i = 0; i < 2; i++){
            int next = cur + range[i];
            if(next <= 0 || next > F || Floor[next] != 0){
                continue;
            }
            Floor[next] = Floor[cur] + 1;
            a.push(next);
        }
    }

    printf("use the stairs\n");
}