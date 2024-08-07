/*
Link: https://leetcode.com/problems/basic-calculator/
224. Basic Calculator
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().


Example 1:
Input: s = "1 + 1"
Output: 2

Example 2:
Input: s = " 2-1 + 2 "
Output: 3

Example 3:
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:
1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int calculate(string s) {
    stack<int> stk;
    int sig=1;
    int num=0, sum=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' ') continue;
        if(isdigit(s[i])){
            while(i<s.size()&&isdigit(s[i])){
                num=num*10+(s[i]-'0');
                i++;}
                i--;
        }else
        if(s[i]=='+'){
            sum+= num * sig;
            sig=1;
            num=0;
        }else
        if(s[i]=='-'){
            sum+= num * sig;
            sig=(-1);
            num=0;
        }else
        if(s[i]=='('){
            stk.push(sig);
            stk.push(sum);
            sum=0;
            num=0;
            sig=1;
        }else if(s[i]==')'){
            sum+=num*sig;
            num=0;
            int last_sum=stk.top();stk.pop();
            int last_sign=stk.top();stk.pop();
            sum=sum*last_sign;
            sum=sum+last_sum;
        }
    }
    sum+=num*sig;
    return sum;
}

int main(){
    cout<<calculate("(1+(4+5+2)-3)+(6+8)")<<endl;
    cout<<calculate("1 + 1")<<endl;
    return 0;
}