/*
Link: https://leetcode.com/problems/remove-duplicate-letters/description/
316. Remove Duplicate Letters
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
the smallest in lexicographical order among all possible results.

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:
1 <= s.length <= 104
s consists of lowercase English letters.
*/
#include<iostream>
#include<stack>
#include<map>
#include<string>
using namespace std;

string removeDuplicateLetters(string s) {
    stack<char> st;
    int i = 0;
    map<char,int> freq;
    map<char,bool> visit;
    for(auto i:s){
        freq[i]++;
        visit[i] = false;
    }
    for(int i=0;i<s.size();i++){
        if(visit[s[i]]){
            freq[s[i]]--;
            continue;
        }
        while(!st.empty() && st.top()>s[i] && freq[st.top()]>0){
            visit[st.top()] = false;
            st.pop();
        }
        st.push(s[i]);
        visit[s[i]]=true;
        freq[s[i]]--;
    }
    string result = "";
    while(!st.empty()){
        result.insert(result.begin(),st.top());
        st.pop();
    }
    return result;
}

int main(){
    return 0;
}