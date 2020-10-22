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
    int minDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        
        queue<TreeNode*>P;
        P.push(root);
        int c=1;
        int ans=0;
        while(!P.empty())
        {  
            c=P.size();
            ans++;
            for(int i=0;i<c;++i)
            {
                TreeNode*temp=P.front();
               
                
                if(temp->left)
                {
                    P.push(temp->left);
                }
               
                
                if(temp->right)
                {
                    P.push(temp->right);
                }
                  
                if((temp->left==NULL)&&(temp->right==NULL))
                {
                    return ans;
                }
                P.pop(); 
                
            }
            
        }
        return c;
        
    }
};
