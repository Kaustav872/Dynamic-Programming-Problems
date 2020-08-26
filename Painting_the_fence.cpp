/* QUESTION:------>

Painting the Fence
Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two integers n and k.

Output:
Print an integer which denoted the number of ways in which the fence can be painted.(modulo 109 + 7)

Constraints:
1<=T<=1000
1<=n<=100000
1<=k<=100

Example:
Input:
2
2 4
3 2

Output:
16
6

For the second test case we have following possible combinations:



** For More Input/Output Examples Use 'Expected Output' option **

Link:-https://practice.geeksforgeeks.org/problems/painting-the-fence/0
Study link:->https://www.geeksforgeeks.org/painting-fence-algorithm/

*/

#include<iostream>
#define ll long long
using namespace std;
ll countWays(ll n,ll k)
{
    ll total=k;
    ll mod=1000000007;
    ll same=0,diff=k;
    for(ll i=2;i<=n;i++)
    {
        same=diff;
        diff=total*(k-1);
        diff=diff%mod;
        total=(same+diff)%mod;
    }
    return total;
}
int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    ll k;
	    cin>>n>>k;
	    cout<<countWays(n,k)<<endl;
	}
	return 0;
}
