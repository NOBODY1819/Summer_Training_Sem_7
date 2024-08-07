/*
Link: https://leetcode.com/problems/basic-calculator-ii/description/
227. Basic Calculator II
Given a string s which represents an expression, evaluate this expression and return its value. 
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().


Example 1:
Input: s = "3+2*2"
Output: 7

Example 2:
Input: s = " 3/2 "
Output: 1

Example 3:
Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:
1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
*/
#include<iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;

int calculate(string s) { 
    stack<int> operand;
    stack<char> operation;
    map<char,int> prec={{'+',1},{'-',1},{'*',2},{'/',2}};
    int ss=s.size();
    for(int i=0;i<ss;i++){
        if(s[i]==' ') continue;
        if(isdigit(s[i])){
            int val=0;
        while(i<ss && isdigit(s[i])){
            val=val*10+(s[i]-'0');
            i++;
        }
        i--;
        operand.push(val);
        }else{
            while(!operation.empty() && prec[s[i]]<=prec[operation.top()]){
                int x,y,z;
                y=operand.top(); operand.pop();
                x=operand.top(); operand.pop();
                char o=operation.top(); operation.pop();
                switch(o){
                    case '+': z=x+y;
                    break;
                    case '-': z=x-y;
                    break;
                    case '*': z=x*y;
                    break;
                    case '/': z=x/y;
                    break;
                }
                operand.push(z);
            }
            operation.push(s[i]);
        }
    }
    while(!operation.empty()){
        int x,y,z;
        y=operand.top(); operand.pop();
        x=operand.top(); operand.pop();
        char o=operation.top(); operation.pop();
        switch(o){
            case '+': z=x+y;
            break;
            case '-': z=x-y;
            break;
            case '*': z=x*y;
            break;
            case '/': z=x/y;
            break;
            }
    operand.push(z);
    }
    return operand.top();
}

int main(){
    cout<<calculate("3+2*2")<<endl;
    cout<<calculate(" 3+5 / 2 ")<<endl;
    return 0;
}