/*
Link: https://leetcode.com/problems/reverse-integer/description/
7. Reverse Integer
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 
Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21
 

Constraints:
-231 <= x <= 231 - 1
*/
#include<iostream>
#include<climits>
using namespace std;

int reverse(int x) {
        int y=0, temp=abs(x);
        while(temp){
            if(y>INT_MAX/10 || y < INT_MIN/10) return 0;
            y = (y*10) + (temp%10);
            temp/=10;
        }
        if(x<0) y=0-y;
        return y;
    }
int main(){
    return 0;
}