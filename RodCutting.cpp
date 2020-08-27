/* QUESTION:->

Rod Cutting
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input:
First line consists of T test cases. First line of every test case consists of n, denoting the size of array. Second line of every test case consists of price of ith length piece.

Output:
For each testcase, in a new line, print a single line output consists of maximum price obtained.

Constraints:
1 <= T <= 100
1 <= n <= 100
1 <= Ai <= 100

Example:
Input:
1
8
1 5 8 9 10 17 17 20
Output:
22


Link:https://practice.geeksforgeeks.org/problems/rod-cutting/0/
Yt:->https://www.youtube.com/watch?v=SZqAQLjDsag&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=15&t=0s

*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cutRod(ll price[],ll n)
{
    ll val[n+1];
    val[0]=0;
    ll i,j;
    for(i=1;i<=n;i++)
    {
        ll max_val=INT_MIN;
        for(j=0;j<i;j++)
        {
            max_val=max(max_val,price[j]+val[i-j-1]);
        }
        val[i]=max_val;
    }
    return val[n];
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
	    ll arr[n+1];
	    for(ll i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }

	    cout<<cutRod(arr,n)<<endl;
	}
	return 0;
}
