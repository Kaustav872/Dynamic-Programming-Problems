/* QUESTION:->
Longest subsequence-1
Given an array A of size N, the task is to find the longest subsequence such that difference between adjacents is one.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size of array A.The second line of each test case contains N space separated integers denoting elements of the array A[ ].

Output:
For each testcase, in a new line, print the length of the longest subsequence such that difference between adjacents is one.

Constraints:
1<= T <=100
1<= N <=103
1<= A[ ] <=103

Example:
Input:
1
7
10 9 4 5 4 8 6
Output:
3

Link: https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one/0
Study Link:- https://www.geeksforgeeks.org/longest-subsequence-such-that-difference-between-adjacents-is-one/

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll LongestSub(ll arr[],ll n)
{
    ll dp[n];
    for(ll i=0;i<n;i++)
    {
        dp[i]=1;
    }

    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<i;j++)
        {
            if((arr[i]==arr[j]+1) || (arr[i]==arr[j]-1))
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    ll result=1;
    for(ll i=0;i<n;i++)
    {
        if(result<dp[i])
        {
            result=dp[i];
        }
    }
    return result;
}
int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll arr[n];
	    for(ll i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    cout<<LongestSub(arr,n)<<endl;
	}
	return 0;
}
