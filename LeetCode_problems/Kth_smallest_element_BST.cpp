/*
Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
230. Kth Smallest Element in a BST
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.


Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
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
    int temp=0, v=0;
    int kthSmallest(TreeNode* root, int k) {        //Solution 1
        inorder(root,k);
        return v;
    }
    void inorder(TreeNode* root, int k){
        if(root!=NULL){
        inorder(root->left,k);
        temp++;
        if(k==temp){ 
            v=root->val;
            return;
        }
        inorder(root->right,k);
        } 
    }
                        //Solution 2
    vector<int> tree;
    int kthSmallest1(TreeNode* root, int k) {
        inorder1(root);
        return tree[k-1];
    }
    void inorder1(TreeNode* root){
        if(root==NULL) return;
        inorder1(root->left);
        tree.push_back(root->val);
        inorder1(root->right);
    }
};

int main(){
    return 0;
}