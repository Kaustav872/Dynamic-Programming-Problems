/*QUESTION:-------------->

Knapsack with Duplicate Items
Given weights and values related to n items and the maximum capacity allowed for these items. What is the maximum value we can achieve if we can pick any weights any number of times for a total allowed weight of W?

Input:
The first line of input contains an integer denoting the number of test cases. Then T test cases follow . Each test case contains two integers N and W denoting the number of items and the total allowed weight. In the next two lines are space separated values of the array denoting values of the items (val[]) and their weights (wt[]) respectively.

Output:
For each test case, in a new line, print the  maximum value which we can achieve if we can pick any weights any number of times for a bag of size W.

Constraints:
1 <= T <= 100
1 <= N, W <= 103
1 <= wt[], val[] <= 100

Example:
Input:
2
2 3
1 1
2 1
4 8
1 4 5 7
1 3 4 5
Output:
3
11


Link:->https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0
StudyLink:->https://www.youtube.com/watch?v=aycn9KO8_Ls&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=13
*/


#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ub(ll w,ll n,ll val[],ll wt[])
{
    ll dp[w+1];
    memset(dp,0,sizeof dp);
    for(ll i=0;i<=w;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(wt[j]<=i)
            {
                dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
            }
        }
    }
    return dp[w];
}
int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--){
	ll n,w;
	cin>>n>>w;
	ll val[n+1];
	ll weg[n+1];
	for(ll i=0;i<n;i++)
	{
	    cin>>val[i];
	}
	for(ll i=0;i<n;i++)
	{
	    cin>>weg[i];
	}
	cout<<ub(w,n,val,weg)<<endl;
	}return 0;
}
