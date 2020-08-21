/* QUESTIO IS:------------------>
nCr
Find nCr for given n and r.

Input:
First line contains number of test cases T. T testcases follow. Each testcase contains 1 line of input containing 2 integers n and r separated by a space.

Output:
For each testcase, in a new line, find the nCr. Modulus your output to 109+7.

Constraints:
1 <= T <= 50
1 <= n <= 103
1 <= r <= 800

Example:
Input:
2
3 2
4 2
Output:
3
6

Question link: https://practice.geeksforgeeks.org/problems/ncr/0

Appraoch used:--> Dynamic programming, Also recursive approach can be used
                  but not effecient
*/

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

ll binomialCoeff(ll n,ll k)
{
    ll C[k+1];
    memset(C,0,sizeof(C));
    C[0]=1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=min(i,k);j>0;j--)
        {
            // There might be a confusion why modulo is used here
            // but the answer is the question demanded it
            C[j]=(C[j]+C[j-1])%1000000007;
        }
    }
    return C[k];
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
	    ll r;
	    cin>>r;
	    cout<<binomialCoeff(n,r)<<endl;
	}
	return 0;
}
