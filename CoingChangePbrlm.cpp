/* QUESTION IS------>

Coin Change
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'M' denoting the size of array. The second line contains M space-separated integers A1, A2, ..., AN denoting the elements of the array. The third line contains an integer 'N' denoting the cents.

Output:
Print number of possible ways to make change for N cents.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 300
1 ≤ A[i] ≤ 300

Example:
Input:
2
3
1 2 3
4
4
2 5 3 6
10

Output:
4
5

Explanation:
Testcase 1: The possiblities are as such: {1, 1, 1, 1}, {1, 1, 2}, {1, 3}, {2, 2}.

** For More Input/Output Examples Use 'Expected Output' option **

Link: https://practice.geeksforgeeks.org/problems/coin-change/0
Source Study Material: https://www.geeksforgeeks.org/coin-change-dp-7/
                       https://www.youtube.com/watch?v=ruMqWViJ2_U

Ultimate Understandable video : https://www.youtube.com/watch?v=PafJOaMzstY
(But the approach is not that effecient we can also do it using 1D arry)
*/

#include<iostream>
#include<vector>
#include<string.h>
#define ll long long
using namespace std;
ll count(vector<ll> S,ll m,ll n)
{
    ll table[n+1];
    memset(table,0,sizeof(table));
    table[0]=1;
    for(ll i=0;i<m;i++){
        for(ll j=S[i];j<=n;j++){
            table[j]+=table[j-S[i]];
            cout<<table[j]<<" ";}

     cout<<endl;}


    return table[n];
}
int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--)
	{
	    ll m;
	    cin>>m;
	    vector<ll> arr;
	    ll input;
	    for(ll i=0;i<m;i++)
	    {
	        cin>>input;
	        arr.push_back(input);
	    }
	    ll n;
	    cin>>n;
	    cout<<count(arr,m,n)<<endl;
	}
	return 0;
}
