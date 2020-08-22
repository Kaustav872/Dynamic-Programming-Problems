/* QUESTION:---------->

LCS of three strings
Given 3 strings X, Y and Z, the task is to find the longest common sub-sequence in all three given sequences.



Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains integers n, m and k denoting the length of strings X, Y and Z respectively.

The second line of each test case contains the three strings X, Y and Z. The string consists of only lower case english alphabets.

Output:

Print the length of the longest common sub- sequence of the three strings for each test case in a new line.


Constraints:
1<= T <=100
1<= N, M, K <=100


Example:
Input:
1
5 8 13
geeks geeksfor geeksforgeeks

Output:
5

Explanation:
All the 3 strings given have "geeks" as the longest subsequence present which has a length of 5.
geeks geeksfor geeksforgeeks

** For More Input/Output Examples Use 'Expected Output' option **

Link: https://practice.geeksforgeeks.org/problems/lcs-of-three-strings/0
Learning Link: https://www.geeksforgeeks.org/lcs-longest-common-subsequence-three-strings/

*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll lcsOf3(string X,string Y,string Z,ll m,ll n,ll o)
{
    ll L[m+1][n+1][o+1];
    for(ll i=0;i<=m;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            for(ll k=0;k<=o;k++)
            {
                if(i==0 || j==0 || k==0)
                {
                    L[i][j][k]=0;
                }
                else if(X[i-1]==Y[j-1] && X[i-1]==Z[k-1])
                {
                    L[i][j][k]=L[i-1][j-1][k-1]+1;
                }
                else
                {
                    L[i][j][k]=max(max(L[i-1][j][k],L[i][j-1][k]),L[i][j][k-1]);
                }
            }
        }
    }
    return L[m][n][o];
}
int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,m,k;
	    cin>>n>>m>>k;
	    string X,Y,Z;
	    cin>>X>>Y>>Z;
	    cout<<lcsOf3(X,Y,Z,n,m,k)<<endl;
	}
	return 0;
}
