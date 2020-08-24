/* QUESTION:----------->
Minimum number of jumps
Given an array of integers where each element represents the max number of steps that can be made forward from that element. The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input:
The first line contains an integer T, depicting total number of test cases.  Then following T lines contains a number n denoting the size of the array. Next line contains the sequence of integers a1, a2, ..., an.

Output:
For each testcase, in a new line, print the minimum number of jumps. If answer is not possible print "-1"(without quotes).

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 <= ai <= 107

Example:
Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2

Explanation:
Testcase 1: First jump from 1st element, and we jump to 2nd element with value 3. Now, from here we jump to 5h element with value 9. and from here we will jump to last.


** For More Input/Output Examples Use 'Expected Output' option **

Link:https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
Study link: https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/

*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll min(ll x,ll y)
{
    return (x<y)?x:y;
}
ll minJumps(ll arr[], ll n)
{
    // jumps[n-1] will hold the result
    ll* jumps = new ll[n];
    ll i, j;

    if (n == 0 || arr[0] == 0)
        return -1;

    jumps[0] = 0;

    // Find the minimum number of jumps to reach arr[i]
    // from arr[0], and assign this value to jumps[i]
    for (i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++) {
            if (i <= j + arr[j] && jumps[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }

    if(jumps[n-1]==INT_MAX)
    {
        return -1;
    }
    else
    {
        return jumps[n-1];
    }
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
	    cout<<minJumps(arr,n)<<endl;
	}
	return 0;
}
