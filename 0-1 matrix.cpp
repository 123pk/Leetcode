/*
Platform :- Leetcode
Problem :- 0-1 matrix
Approach :- push all the points {i,j} in queue where mat[i][j] = 0 and perform bfs and update the neigbouring cells with the min values out of all possible values   
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m,1e5));
        set<pair<int,int>>used;
        queue<pair<pair<int,int>,int>>P;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==0){
                    P.push({{i,j},0});
                    ans[i][j]=0;
                    used.insert({i,j});
                }
            }
        }
        
        
            
            
        // performing BFS on points where mat[i][j] = 0 
            while(!P.empty()){
                int c=P.size();
                
                for(int j=1;j<=c;++j){
                    pair<pair<int,int>,int>temp=P.front();
                    P.pop();
                    
                    int x = temp.first.first;
                    int y = temp.first.second;
                    int d=temp.second+1;
                    
                    if((x+1)<n){
                        if(used.find({x+1,y})!=used.end())
                            ans[x+1][y]=min(ans[x+1][y],d);
                        else{
                            ans[x+1][y]=min(ans[x+1][y],d);
                            used.insert({x+1,y});
                            P.push({{x+1,y},d});
                        }
                    }
                    if((x-1)>=0){
                        if(used.find({x-1,y})!=used.end())
                            ans[x-1][y]=min(ans[x-1][y],d);
                        else{
                            ans[x-1][y]=min(ans[x-1][y],d);
                            used.insert({x-1,y});
                            P.push({{x-1,y},d});
                        }
                    }
                    if((y-1)>=0){
                        if(used.find({x,y-1})!=used.end())
                            ans[x][y-1]=min(ans[x][y-1],d);
                        else{
                            ans[x][y-1]=min(ans[x][y-1],d);
                            used.insert({x,y-1});
                            P.push({{x,y-1},d});
                        }
                    }
                    if((y+1)<m){
                        if(used.find({x,y+1})!=used.end())
                            ans[x][y+1]=min(ans[x][y+1],d);
                        else{
                            ans[x][y+1]=min(ans[x][y+1],d);
                            used.insert({x,y+1});
                            P.push({{x,y+1},d});
                        }
                    }
                }
            }
         
        
        return ans;
    }
};
