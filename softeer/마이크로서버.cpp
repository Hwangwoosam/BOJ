#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int t,n;

int main(){
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n;

        int result = 0;
        vector<int> service(n);
        
        for(int j = 0; j < n; j++) cin >> service[j];
        sort(service.begin(),service.end());

        int cnt = 0;
        for(int j = 0; j < j; j++){
            if(service[j] != 300) break;
            cnt++;
        }

        int start = cnt;
        int end = n-1;
        while(start <= end){
            if(service[end] > 600){ //600 이상 처리
                result ++;
                end--;
            }
            else if(service[end] == 600){
                if(cnt > 0){
                    result ++;
                    end--;
                    cnt--;
                }else{
                    result++;
                    end--;
                }
            }
            else if(start != end){
                if(service[start] + service[end] <= 900){
                    result++;
                    end--;
                    start++;
                }
                else if(cnt > 0){
                    result++;
                    end--;
                    cnt--;
                }else{
                    result++;
                    end--;
                }
            }
            else if(start == end){
                if(cnt > 0){
                    result++;
                    end--;
                    cnt--;
                }else{
                    result++;
                    end--;
                }
            }
        }
        result += (cnt/3);
        if(cnt % 3 != 0) result++;
        cout << result << "\n";
    }


    return 0;
}