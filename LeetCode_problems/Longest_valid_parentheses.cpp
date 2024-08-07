/*
Link: https://leetcode.com/problems/longest-valid-parentheses/
32. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring.

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0
 
Constraints:
0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int longestValidParentheses(string s) {         //Solution 1
    stack<int> brc;int valid=0;
    brc.push(-1);
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            brc.push(i);
        }else{
            brc.pop();
            if(brc.empty())
                brc.push(i);
            else 
            valid=max(valid,i-brc.top());
        }
    }
    return valid;
}

int longestValidParentheses_1(string s) {           //Solution 2
    int count_1=0,count_2=0;int valid=0,count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            count_1++;
        }else
            count_2++;
        if(count_2==count_1)
            valid=max(valid,count_1+count_2);
        else if(count_2>count_1) count_1=count_2=0;
    }
    count_1=count_2=0;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='('){
            count_1++;
        }else
            count_2++;
        if(count_2==count_1)
            valid=max(valid,count_1+count_2);
        else if(count_2<count_1) count_1=count_2=0;
    }
    return valid;
}

int main(){
    return 0;
}