/*
Link: https://leetcode.com/problems/valid-parentheses/description/
20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false
 
Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

#include<iostream>
#include<string>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;

bool isValid(string s) {  //Solution function
        stack<char> st;
        map<char,char> pr={{')','('}, {'}','{'}, {']', '['}};
        for(char i:s){
            if(i=='(' || i=='{' || i=='['){
                st.push(i);
            }else{
                if(!st.empty() && st.top()==pr[i]) st.pop();
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }

int main(){
    return 0;
}