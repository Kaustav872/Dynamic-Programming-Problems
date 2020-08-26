/* Question

Count number of hops
A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it reach the top.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains one line of input N denoting the total number of steps.

Output:
For each testcase, in a new line, print the number of ways to reach the top.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 50

Example:
Input:
2
1
5
Output:
1
13

Explanation:
Testcase 1:

** For More Input/Output Examples Use 'Expected Output' option **

Link:https://practice.geeksforgeeks.org/problems/count-number-of-hops/0


*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int dp[n+1] = {0};
	    dp[0]=1;
	    dp[1]=1;
	    dp[2]=2;
	    dp[3]=4;
	    for(int i=4;i<=n;i++){
	        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	    }
	    cout<<dp[n]<<endl;
	}
	return 0;
}
