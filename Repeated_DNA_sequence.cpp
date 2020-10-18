#include<bits/stdc++.h>
using namespace std;


vector<string> findRepeatedDnaSequences(string s) 
{
  vector<string>ans;
  map<string,int>P;

  if(s.size()<10)
  {
      return ans;
  }
  string temp;
  for(int i=0;i<10;++i)
  {
      temp+=s[i];
  }
  P[temp]++;

  for(int i=10;i<s.size();++i)
  {
      temp.erase(temp.begin());
      temp+=s[i];
      P[temp]++;
     if(P[temp]==2)
     {
         ans.push_back(temp);
     }
  }

  return ans;
}

int main()
{
  string s;
  cin>>s;

  vector<string>solution;
  solution = findRepeatedDnaSequences(s);
  cout<<"[";
  for(auto x: solutions)
  {
    cout<<x<<", ";
  }
  cout<<"]";
}

