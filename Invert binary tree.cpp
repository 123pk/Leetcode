/*
Platform :- Leetcode
Approach :- Store the pointer to root in some variable now perform bfs on the tree and swap left and right children and now return the varible that stored the pointer to root
            take care of null root pointer.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
      
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        
        TreeNode*node = root;
        
        queue<TreeNode*>bfs;
        bfs.push(root);
        while(!bfs.empty()){
            int c = bfs.size();
            for(int i=0;i<bfs.size();++i){
                TreeNode* temp = bfs.front();
                bfs.pop();
                
                TreeNode*z=temp->left;
                temp->left = temp->right;
                temp->right=z;
                
                if(temp->left){
                    bfs.push(temp->left);
                }
                
                if(temp->right)bfs.push(temp->right);
            }
            
        }
        return node;
    }
};
