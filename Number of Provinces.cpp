/*
Platform :- Leetcode
Problem :- Number of provinces
Approach :- create a graph using the matrix and do bfs from i=1 to n if the node is not already visited increment your count by 1 , during bfs visit all the nodes of that 
            graph and mark them visited and return your count at the end.
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& A) {
        int n = A.size();
        //Creating graph
        vector<int>Q[n];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(A[i][j])Q[i].push_back(j);
            }
        }
        
        int ans=0;
        vector<int>used(n+1);
        // doing bfs for all the unvisited nodes from 0 to n-1 if node is not visited we increment our answer by one
        for(int i=0;i<n;++i){
            if(used[i]==0){
                ans++;
                queue<int>P;
                P.push(i);
                used[i]++;
                while(!P.empty()){
                    int c=P.size();
                    for(int i=1;i<=c;++i){
                        int temp=P.front();
                        P.pop();
                        for(int j=0;j<Q[temp].size();++j){
                            if(used[Q[temp][j]]==0){
                                used[Q[temp][j]]++;
                                P.push(Q[temp][j]);
                            }
                        }
                    }
                }
            }
        }
            
        return ans;
    }
};
