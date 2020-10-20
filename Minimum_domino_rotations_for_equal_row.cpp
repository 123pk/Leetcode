#include<bits/stdc++.h>
using namespace std;

int minDominoRotations(vector<int>& A, vector<int>& B) {
        int f=0,mn=A.size();
        for(int i=0;i<A.size();++i)
        {  
            int g=0,c=0;
            for(int j=0;j<B.size();++j)
            {
                if(A[j]==A[i])
                {
                    continue;
                }
                if(B[j]==A[i])
                {
                    c++;
                }
                else
                {
                    g=1;
                    break;
                }
            }
            
            if(g==0)
            {   
                f=1;
                mn=min(mn,c);
                break;
            }
        }
        
        int mn2=B.size();
        for(int i=0;i<A.size();++i)
        {  
            int g=0,c=0;
            for(int j=0;j<B.size();++j)
            {
                if(B[j]==B[i])
                {
                    continue;
                }
                if(A[j]==B[i])
                {
                    c++;
                }
                else
                {
                    g=1;
                    break;
                }
            }
            
            if(g==0)
            {   
                f=1;
                mn2=min(mn2,c);
                break;
            }
        }
        
        if(f)
        {
            return min(mn,mn2);
        }
        return -1;
    }
    
    
    int main()
    {
      int n;
      cin>>n;
      
      vector<int>A,B;
      for(int i=0;i<n;++i)
      { 
         int x;
         cin>>x;
         A.push_back(x);
      }
      
      for(int i=0;i<n;++i)
      {
         int x;
         cin>>x;
         B.push_back(x);
      }
      
      cout<<(minDominoRotations( A, B) << endl;
    }
