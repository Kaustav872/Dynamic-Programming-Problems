/* QUESTION:---------->

Longest Repeating Subsequence
Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the length of string str.

The second line of each test case contains the string str consisting only of lower case english alphabets.

Output:

Print the length of the longest repeating subsequence for each test case in a new line.


Constraints:

1<= T <=100

1<= N <=1000


Example:

Input:

2

3

abc

5

axxxy

Output:

0

2

Q Link: https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0
Learning Link:- https://www.geeksforgeeks.org/longest-repeating-subsequence/

*/

#include<iostream>
#define ll long long
using namespace std;
ll find(string str)
{
    ll n=str.length();
    ll dp[n+1][n+1];
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            dp[i][j]=0;
        }
    }

    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(str[i-1]==str[j-1] && i!=j)
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n][n];
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
	    string s;
	    cin>>s;
	    cout<<find(s)<<endl;
	}
	return 0;
}
