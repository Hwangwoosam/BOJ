#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int x;
    string inp;

    cin >> x >> inp;

    int inpSize = inp.size();
    int loopLimit = inpSize/2;

    set<string> word;
    vector<string> wordOrder;

    bool odd = (inpSize%2 == 1);
    
    string inpCopy = inp;
    string next(inpSize,'x');
    for(int i = 0; i < x; i++){
        for(int j = 0; j < inpSize-1; j+=2){
            next[j/2] = inpCopy[j];
            next[inpSize-1-(j/2)] = inpCopy[j+1];
        }
        if(odd) next[loopLimit] = inpCopy[inpSize-1];

        if(word.count(next) > 0) break;
        // cout << next << "\n";
        word.insert(next);
        wordOrder.push_back(next);
        inpCopy = next;
    }

    int idx = (x-1)%word.size();
    cout << wordOrder[idx] << "\n";

    return 0;
}