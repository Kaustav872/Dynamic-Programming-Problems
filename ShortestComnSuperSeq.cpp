/* QUESTION:---------->

Shortest Common Supersequence
Given two strings str1 and str2, find the length of the smallest string which has both, str1 and str2 as its sub-sequences.
Note: str1 and str2 can have both uppercase and lowercase letters.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two space-separated strings.

Output:
For each testcase, in a new line, output the length of the required string.

Expected Time Complexity: O(Length(str1) * Length(str2)).
Expected Auxiliary Space: O(Length(str1) * Length(str2)).

Constraints:
1 <= T <= 100
1<= |str1|, |str2| <= 100

Example:
Input:
2
abcd xycd
efgh jghi
Output:
6
6
Explanation:
Test Case 1: One of the shortest answer can be abxycd, which is of length 6.

** For More Input/Output Examples Use 'Expected Output' option **


Link:https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0
Study Link:->https://www.geeksforgeeks.org/shortest-common-supersequence/


*/

#include<bits/stdc++.h>
#include<string.h>
#define ll long long
using namespace std;
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
    }return L[m][n];
}
ll shortestSuperSequence(char *X,char *Y)
{
    ll m=strlen(X),n=strlen(Y);
    ll l=lcs(X,Y,m,n);
    return (m+n-l);
}

int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--)
	{
	    string a,b;
	    cin>>a>>b;
	    ll n,m;
	    n=a.length();
	    m=b.length();
	    char X[n+1];
	    char Y[m+1];
	    strcpy(X, a.c_str());
	    strcpy(Y, b.c_str());
	    cout<<shortestSuperSequence(X,Y)<<endl;
	}
	return 0;
}
