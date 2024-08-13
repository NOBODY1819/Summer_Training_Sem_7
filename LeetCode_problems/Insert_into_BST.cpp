/*
Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
701. Insert into a Binary Search Tree
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

Example 1:
Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:
Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]

Example 3:
Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]
 

Constraints:
The number of nodes in the tree will be in the range [0, 104].
-108 <= Node.val <= 108
All the values Node.val are unique.
-108 <= val <= 108
It's guaranteed that val does not exist in the original BST.
*/
#include<iostream>
#include<vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {      // Solution 1
        if (root==NULL){
            return new TreeNode(val);
        }
        TreeNode *temp=root;
        while(temp!=NULL){
            if(temp->val>val){
                if(temp->left==NULL){
                    temp->left=new TreeNode(val);
                    break;
                }
                temp=temp->left;
            }else{
                if(temp->right==NULL){
                    temp->right=new TreeNode(val);
                    break;
                }
                temp=temp->right;
            } 
        }
        return root;
    }
    TreeNode* insertIntoBST1(TreeNode* root, int val) {     //Solution 2
        if(root==NULL){
            root=new TreeNode(val);
            return root;
        }else if(root->val > val){
            root->left=insertIntoBST(root->left,val);
        }else {
            root->right=insertIntoBST(root->right,val);
        }
        return root;
    }
};

int main(){
    return 0;
}