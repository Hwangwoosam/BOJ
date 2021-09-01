#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int button[10];

int possible_channel(int channel){
    int channel_cpy = channel;
    if(channel == 0){
        if(button[channel]){
            return 0;
        }else{
            return 1;
        }
    }
    while(channel_cpy > 0){
        int check = channel_cpy%10;
        if(button[check]){
            return 0;
        }
        channel_cpy /= 10;
    }

    return 1;
}

int find_near(int channel){
    int to_channel = abs(channel-100);
    int min = INT32_MAX;
    for(int i = 0; i < 1000000;i++){
        int temp;
        if(possible_channel(i)){
            if(i == 0){
                temp = 1;
            }else{
                temp = floor(log10(i) +1);
            }
            temp += abs(i - channel);
            if(min > temp){
                min = temp;
            }
        }
    }
    if(to_channel < min){
        return to_channel;
    }
    return min;
}

int main(){
    ios_base :: sync_with_stdio(false); 
	cin.tie( NULL); 
	cout.tie(NULL);

    freopen("test.txt","r",stdin);
    
    int n ,m;
    cin >> n >> m;

    int break_number;
    for(int i = 0; i < m; i ++){
        cin >> break_number;
        button[break_number] = 1;
    }
    cout << find_near(n) <<"\n";
    return 0;
}
