/* QUESTION->

Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.

Output:
Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= arr[i] <= 1000

Example:
Input:
2
4
1 5 11 5
3
1 3 5

Output:
YES
NO

Explanation:
Testcase 1: There exists two subsets such that {1, 5, 5} and {11}.

** For More Input/Output Examples Use 'Expected Output' option **

Link Question:https://practice.geeksforgeeks.org/problems/subset-sum-problem/0

*/

#include<iostream>
#define ll long long
using namespace std;
bool findP(ll arr[],ll n)
{
    ll sum=0;
    ll i,j;
    for(i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    if(sum%2!=0)
    {
        return false;
    }
    bool part[sum/2 +1][n+1];

    for(i=0;i<=n;i++)
    {
        part[0][i]=true;
    }
    for(int i=1;i<=sum/2;i++)
    {
        part[i][0]=false;
    }
    for(i=1;i<=sum/2;i++)
    {
        for(j=1;j<=n;j++)
        {
            part[i][j]=part[i][j-1];
            if(i>=arr[j-1])
            {
                part[i][j]=part[i][j] || part[i-arr[j-1]][j-1];
            }
        }

    }return part[sum/2][n];
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
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    if(findP(arr,n)==true)
	    {
	        cout<<"YES"<<endl;
	    }
	    else
	    {
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}
