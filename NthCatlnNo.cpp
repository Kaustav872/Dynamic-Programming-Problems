/*Given a number N. The task is to find the nth Catalan number.
The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …

Input:
The first line of input contains a single integer T which denotes the number of test cases. The first line of each test case contains a single integer N.

Output:
For each test case, in a new line print the Catalan number at position N.
Note: Positions start from 0 as shown above.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
3
5
4
10

Output:
42
14
16796
Explanation:
From the given first few Catalan's number we can easily the answer for first two test cases.

Link of the Question: https://practice.geeksforgeeks.org/problems/nth-catalan-number/0
*/

#include <bits/stdc++.h>

// check for this lib in the net  This lib is used for getting more precision
// than 64bits

// the library wont run here since this compiler is not that updated one
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
using namespace std;
cpp_int cat(unsigned int n)
{
    cpp_int catlan[n+1];
    catlan[0]=catlan[1]=1;
    for(int i=2;i<=n;i++)
    {
        catlan[i]=0;
        for(int j=0;j<i;j++)
        {
            catlan[i]+=catlan[j]*catlan[i-j-1];
        }
    }
    return catlan[n];
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    cout<<cat(n)<<endl;
	}
	return 0;
}
