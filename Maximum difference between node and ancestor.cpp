/*
Platform :- Leetcode
Approach :- BFS and maintain a min and max , whenever visiting any node find the absolute difference between node val and min and max and store in answer and update min and max .
*/
/*
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
    int maxAncestorDiff(TreeNode* root) {
        //do bfs and maintin min and max value at each level
        // compute the max difference that can be acheived
        int ans=0;
        
        queue<pair<TreeNode*,pair<int,int>>>bfs;
        bfs.push({root,{root->val,root->val}});
        
        while(!bfs.empty()){
            int c = bfs.size();
            for(int i=0;i<c;++i){
                pair<TreeNode*,pair<int,int>>temp = bfs.front();
                bfs.pop();
                
                if(temp.first->left){
                    int val =temp.first->left->val;
                    val=max(abs(val-temp.second.first),abs(val-temp.second.second));
                    ans=max(ans,val);
                    int val2 = min(temp.second.first,temp.first->left->val);
                    int val3 = max(temp.second.second,temp.first->left->val);
                    bfs.push({temp.first->left,{val2,val3}});
                }
                
                if(temp.first->right){
                    int val =temp.first->right->val;
                    val=max(abs(val-temp.second.first),abs(val-temp.second.second));
                    ans=max(ans,val);
                    int val2 = min(temp.second.first,temp.first->right->val);
                    int val3 = max(temp.second.second,temp.first->right->val);
                    bfs.push({temp.first->right,{val2,val3}});
                    
                }
            }
        }
        
        return ans;
    }
};
