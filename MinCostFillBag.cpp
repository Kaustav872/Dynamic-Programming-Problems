/* QUESTION:---------->


https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag/0

Minimum cost to fill given weight in a bag
You are given a bag of size W kg and you are provided costs of packets different weights of oranges in array cost[] where cost[i] is basically cost of ‘i’ kg packet of oranges. Where cost[i] = -1 means that ‘i’ kg packet of orange is unavailable

Find the minimum total cost to buy exactly W kg oranges and if it is not possible to buy exactly W kg oranges then print -1. It may be assumed that there is infinite supply of all available packet types.

Note : array starts from index 1.

Input: The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains integers N and W where N denotes the size of array cost[ ] and W is the size of the bag.

The second line of each test case contains N space separated integers denoting elements of the array cost[ ].


Output: Print the minimum cost to buy exactly W kg oranges. If no such answer exists print "-1".


Constraints:
1<= T <=100
1<= N, W <=1000
1<= cost[ ] <=1000


Example:

Input:
2
5 5
20 10 4 50 100
5 5
-1 -1 4 5 -1

Output:
14
-1

 I have copied the solution from the editorial

 HAVE TO PRACTICE More

 Link of the Question: https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag/0

 */


 /* prakhar tiwari
                    */


#include<bits/stdc++.h>
using namespace std;
 vector<int>dp;
  int helper(vector<int> v, int W, int n)
  {
       dp[0]=0;
       for(int i=1;i<=W; i++)
       {        int mini=INT_MAX;
           for(int j=0; j<i && j<n; j++)
           {
                if(v[j]!=-1 && dp[i-j-1]!=INT_MAX)
                    mini=min(mini,v[j]+dp[i-j-1]); //another way (dp[i], v[j]+dp[i-j-1]);
           }
               dp[i]=mini;

       }
        // for(int i=0; i<W+1; i++)
        //  cout<<dp[i]<<" ";
       return (dp[W]!=INT_MAX)?dp[W]:-1;
  }
int main()
 {
 int t;
 cin>>t;
 while(t--)
 {
   int n,W;
    cin>>n>>W;
     vector<int>v(n);
      for(int i=0; i<n; i++)
      {
          cin>>v[i];
      }
      dp.resize(W+1, INT_MAX);
      cout<<helper(v,W,n)<<endl;
      dp.clear();
 }
	//code
	return 0;
}
