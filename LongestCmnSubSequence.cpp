/* QUESTION-------->

Longest Common Subsequence
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .

Output:
For each test case print the length of longest  common subsequence of the two strings .

Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2

Link of the Question: https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
Link to Study: https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll max(ll a,ll b);
ll lcs(char *X,char *Y,ll m,ll n)
{
    ll L[m+1][n+1];
    ll i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                L[i][j]=0;
            }
            else if(X[i-1]==Y[j-1])
            {
                L[i][j]=L[i-1][j-1]+1;
            }
            else
            {
                L[i][j]=max(L[i-1][j],L[i][j-1]);
            }
        }
    }
    return L[m][n];
}
ll max(ll a,ll b)
{
    return (a>b)?a:b;
}
int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    ll m;
	    cin>>m>>n;
	    string A,B;
	    cin>>A>>B;
	    char X[m+1];
	    char Y[n+1];
	    strcpy(X, A.c_str());
	    strcpy(Y, B.c_str());
	    cout<<lcs(X,Y,m,n)<<endl;

	}

	return 0;
}
