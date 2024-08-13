/*
Link: https://leetcode.com/problems/delete-node-in-a-bst/description/
450. Delete Node in a BST
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.
 

Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:
Input: root = [], key = 0
Output: []
 

Constraints:
The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
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
    TreeNode *temp=NULL;                            //Solution 1
    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int> arr;
        if(preorder(root,arr,key)){
            for(int i:arr){
                temp = insert(temp,i);
            }
        }
        return temp;
    }
    bool preorder(TreeNode* root,vector<int>&arr,int key){
        static bool flag = false;
        if(root!=NULL){
            if(root->val == key){
                flag = true;
            }
            else{
                arr.push_back(root->val);
            }
            preorder(root->left,arr,key);
            preorder(root->right,arr,key);

        }
        return flag;
    }
    TreeNode* insert(TreeNode *temp,int val){
        if(temp == NULL) {
            return new TreeNode(val); 
        }
        if (val < temp->val) {
            temp->left = insert(temp->left, val); 
        } else {
            temp->right = insert(temp->right, val); 
        }
        return temp;
    }


    //Solution 2
// TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root!=NULL){
//             if(key==root->val){
//                 if(root->left==NULL && root->right==NULL){
//                    return NULL;
//                 }else if(root->left==NULL){
//                     return root->right;
//                 }else if(root->right==NULL){
//                     return root->left;
//                 }else{
//                     root->val=maxele(root->left);
//                     root->left=deleteNode(root->left,root->val);
//                     return root;
//                 }
//             }
//             if(root->val>key) root->left=deleteNode(root->left,key);
//             else root->right =deleteNode(root->right,key);
//         }
//         return root;
//     }
//     int maxele(TreeNode * temp){
//         int max=0;
//         while(temp!=NULL){
//             max=temp->val;
//             temp=temp->right;
//         }
//         return max;
//     }
};

int main(){
    return 0;
}