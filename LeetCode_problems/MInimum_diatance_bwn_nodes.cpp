/*
Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/submissions/
783. Minimum Distance Between BST Nodes
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.
 

Example 1:
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:
The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105
*/
#include<iostream>
#include<vector>
#include<climits>
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
    int minDiffInBST(TreeNode* root) {
        vector<int> arr;
        int mindiff = INT_MAX;
        inorder(root, arr);
        int i = 0, j = 1;
        while (j < arr.size()) {
            int diff = arr[j] - arr[i];
            mindiff = min(diff, mindiff);
            i++;
            j++;
        }
        return mindiff;
    }

    void inorder(TreeNode *root, vector<int> &arr) {
        if (root != nullptr) {
            inorder(root->left, arr);
            arr.push_back(root->val);
            inorder(root->right, arr);
        }
    }
};

int main(){
    return 0;
}