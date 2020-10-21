    /*My approach is to use <strong> stack </strong>
      there are certain cases we need to take care of :- 
      1. if element is positive we push in stack.
      2. if stack is empty we push whatever element we have (negative or positive )
      3. if stack top element is -ve we push the current element 
      4. if stack top element is positive we pop it out of stack until we find any element whose value is greater than or equal to abs( current element )
      5. if stack becomes empty after performing operation 4 we will push the current element in stack
      6. now we will take all the elements from stack and push it in vector and reverse it as stack uses LIFO( last in first out)
    */
    
    #include<bits/stdc++.h>
    using namespace std;
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>P;
        for(auto x:asteroids)
        {
            if(x>0)
            {
                P.push(x);
            }
            else
            {
                if(!P.empty())
                {
                    int temp=P.top();
                    if(temp<0)
                    {
                        P.push(x);
                    }
                    else
                    {
                        if(temp<=abs(x))
                        {
                            while(1)
                            {
                                int y=P.top();
                                if(y<0)
                                {
                                    P.push(x);
                                    break;
                                }
                                else
                                {
                                    if(y==abs(x))
                                    {
                                        P.pop();
                                        break;
                                    }
                                    else
                                    {
                                        if(y>abs(x))
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            P.pop();
                                        }
                                    }
                                }
                                
                                if(P.empty())
                                {
                                    P.push(x);
                                    break;
                                }
                            }
                        }
                    }
                }
                else
                {
                   P.push(x);
                }
            }
        }
        
        
        vector<int>ans;
        while(!P.empty())
        {
            ans.push_back(P.top());
            P.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    int main()
    {
         int n;
         cin>>n;
         
         vector<int>asteroids(n);
         for(int i=0;i<n;++i)
         {
            cin>>asteroids[i];
         }
         
         vector<int> ans = asteroidCollision( asteroids);
         cout<<"[ "; 
         for( auto x: ans)
         {
           cout<< x<<", ";
         }
         cout<<"]";
    }
