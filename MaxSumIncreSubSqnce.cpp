/* QUESTION:----------->

Maximum sum increasing subsequence
Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N(the size of array). The second line of each test case contains array elements.

Output:
For each test case print the required answer in new line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ Ai ≤ 106

Example:
Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10

Explanation:
Testcase 1: All the increasing subsequences are : (1,101); (1,2,3,100); (1,2,3,4,5). Out of these (1, 2, 3, 100) has maximum sum,i.e., 106.

Link: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0
StudyLink: https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/

*/
#include<iostream>
#define ll long long
using namespace std;
ll maxSumIS(ll arr[],ll n)
{
    ll i,j,max=0;
    ll msis[n];
    for(i=0;i<n;i++)
    {
        msis[i]=arr[i];
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && msis[i]<msis[j]+arr[i])
            {
                msis[i]=msis[j]+arr[i];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(max<msis[i])
        {
            max=msis[i];
        }
    }
    return max;
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
	    ll arr[n];
	    for(ll i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    cout<<maxSumIS(arr,n)<<endl;
	}
	return 0;
}
