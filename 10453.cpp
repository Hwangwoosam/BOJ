#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;


    for(int i = 0; i < t; i++){
        string a,b;
        int result = -1;

        cin >> a >> b;
        int aSize = a.size();
        int bSize = b.size();

        if(aSize == bSize){
            int aNum = 0, bNum = 0;
            for(int i = 0; i < aSize; i++){
                if(a[i] =='a') aNum++;
                else bNum++;

                if(b[i] == 'a') aNum--;
                else bNum--;
            }

            if(aNum == 0 && bNum == 0){
                result = 0;

                while(0 <= aSize && 0 <= bSize && aSize <= bSize) {
					if(a[aSize] == b[bSize]) {
						aSize--,bSize--;	
					}
					else {
						while(a[aSize] != b[bSize]) aSize--;
						for(;aSize<bSize;aSize++) {
							result++;
							char tmp = a[aSize+1];
							a[aSize+1] = a[aSize];
							a[aSize] = tmp;
						}
					}
				}
                
            }
        }

        cout << result << "\n";
    }

    return 0;
}