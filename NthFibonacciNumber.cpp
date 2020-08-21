/* The Question is:-------------------->

Given a positive integer N, find the Nth fibonacci number. Since the answer can be very large, print the answer modulo 1000000007.

Input:
The first line of input contains T denoting the number of testcases.Then each of the T lines contains a single positive integer N.

Output:
Output the Nth fibonacci number.

Constraints:
1 <= T <= 200
1 <= N <= 1000
Example:
Input:
3
1
2
5
Output:
1
1
5

*/

#include<iostream>
#define ll long long
using namespace std;
ll fibo(ll n)
{
    ll a=0,b=1,c,i;
    if(n==0)
    {
        return a;
    }
    for(i=2;i<=n;i++)
    {

      // why we are gving this modulo ? Because the answer is expected in this format so(Check the question
      // first line)
        c=(a+b)% 1000000007;
        a=b;
        b=c;
    }
    return b ;
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
	    cout<<fibo(n)<<endl;
	}
	return 0;
}
