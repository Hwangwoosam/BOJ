#include <iostream>
#include <string>
#include <stack>

std::string str;

std::stack<char> oper;


int main(){
    std::cin >> str;
    
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            std::cout << str[i];
        }else{
            if(str[i] =='('){
                oper.push(str[i]);
            }else if(str[i] == '*' || str[i] == '/'){
                while(!oper.empty() && (oper.top() == '*' || oper.top() == '/')){
                    std::cout << oper.top();
                    oper.pop();
                }
                oper.push(str[i]);
            }else if(str[i] == '+' || str[i] == '-'){
                while(!oper.empty() && oper.top() != '('){
                    std::cout << oper.top();
                    oper.pop();
                }
                oper.push(str[i]);
            }else if (str[i] == ')'){
                while(!oper.empty() && oper.top() != '('){
                    std::cout << oper.top();
                    oper.pop();
                }
                oper.pop();
            }
        }
    }
    while(!oper.empty()){
        
        std::cout << oper.top();
        oper.pop();
    }


    return 0;
}