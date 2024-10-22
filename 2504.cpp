#include<iostream>
#include<stack>
#include<string>

using namespace std;
 
int n;


int main()
{	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	stack<char> st;
	string inp;
	cin >> inp;

	int flag = 0;
	int result = 0;
	int tmp = 1;
    int inpSize = inp.length();
	
    for(int i = 0; i < inpSize; i++){
		if(inp[i] == '('){
			st.push(inp[i]);
			tmp *= 2;
		}else if(inp[i] == '['){
			st.push(inp[i]);
			tmp *= 3;
		}else if(inp[i] == ')'){
			if(!st.empty() && st.top() == '('){
				if(inp[i-1] == '(')	result += tmp;
				st.pop();
				tmp /= 2;
			}else{
				flag = 1;
				break;
			}
		}else if(inp[i] == ']'){
			if(!st.empty() && st.top() == '['){
				if(inp[i-1] == '[') result += tmp;
				st.pop();
				tmp /= 3;
			}else{
				flag = 1;
				break;
			}
		}
	}
	if(flag == 1 || !st.empty()) result = 0;
	
	cout << result <<"\n";
	
    return 0;
}	 