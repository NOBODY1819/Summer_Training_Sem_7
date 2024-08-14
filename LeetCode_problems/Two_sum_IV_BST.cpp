/*
Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
653. Two Sum IV - Input is a BST
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 
Constraints:
The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
*/
#include<iostream>
#include<map>
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
public:             //Solution 1
    map<int,int> visits;
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return false;
        if(root->left!=NULL && root->val+root->left->val==k){
                return true;
        }
        if(root->right!=NULL && root->val+root->right->val==k){
                return true;
        }
        
        int n=k-root->val;
        if(visits[n]==1) return true;
        visits[root->val]=1;
        return (findTarget(root->right, k) || findTarget(root->left, k));
    }
            //Solution 2
//  bool findTarget(TreeNode* root, int k) {
//         vector<int> tree;
//         inorder(root,tree);
//         int i=0,j=tree.size()-1;
//         while(i<j){
//             if(tree[i]+tree[j]==k) return true;
//             else if(tree[i]+tree[j]<k) i++;
//             else j--;
//         }
//         return false;
//     }
//     void inorder(TreeNode *root, vector<int> &tree){
//         if(root!=NULL){
//             inorder(root->left,tree);
//             tree.push_back(root->val);
//             inorder(root->right,tree);
//         }
//     }
};

int main(){
    TreeNode* root=nullptr;
    return 0;
}