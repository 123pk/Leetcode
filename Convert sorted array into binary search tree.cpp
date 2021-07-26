/*
Platform :- Leetcode
Approach :- like merge sort we keep on breaking our array into smaller sub array and the choosing the middle of the and accordingly making it left child or right child
*/

class Solution {
public:
    
    TreeNode* merge(vector<int>&A,int start,int end){
        if(end<=start)return NULL;
        
        TreeNode*root=new TreeNode;
        root->val=A[(start+end)/2];
        
        root->left=merge(A,start,(start+end)/2);
        root->right=merge(A,(start+end)/2+1,end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return merge(nums,0,n);
    }       
};
