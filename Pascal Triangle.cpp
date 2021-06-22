
/*
Platform :- Leetcode
Problem :- Pascal Triangle
Approach :- we can analyse that no of elementh at 'ith' level is 'i' ,
            --> elements at level 1 = [ 1 ]
            --> elements at level 2 = [ 1, 1]
            --> for every level greater than 2 we have 1st and last element as '1' and 'jth' elements of that level is sum of elementh at previous level at index [ j-1] and [j]
                 A[i][j] = A[i-1][j-1] + A[i-1][j]
*/

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        
        for(int i=0;i<n;++i){
            vector<int>temp(i+1);
            if(i==0){
                temp[i]=1;
            }
            else {
                temp[0]=1;
                temp[i]=1;
                for(int j=1;j<i;++j){
                    temp[j]=ans[i-1][j-1]+ans[i-1][j];
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
