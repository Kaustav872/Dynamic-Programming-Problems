/* QUESTION IS:----------------->

Friends Pairing Problem
Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

Examples:

Input  : n = 3
Output : 4
Explanation
{1}, {2}, {3} : all single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N.

Output:
For each test case in a new line print the required answer mod 10^9+7.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
3
2
Output:
4
2

Link Q:https://practice.geeksforgeeks.org/problems/friends-pairing-problem/0

*/

#include<iostream>
#define ll long long
using namespace std;
ll countr(ll n)
{
    ll dp[n+1];
    for(ll i=0;i<=n;i++)
    {
        if(i<=2)
        {
            dp[i]=i;
        }
        else
        {
            dp[i]=(dp[i-1]%1000000007+((i-1)*dp[i-2]%1000000007)%1000000007);
        }
    }
    return dp[n]%1000000007;
}
int main()
 {
	//code
	ll t;
	cin>>t;
// 	memset(dp,-1,sizeof(dp));
	while(t--)
	{
	    ll n;
	    cin>>n;
	    cout<<countr(n)<<endl;
	}
	return 0;
}
