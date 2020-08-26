/*QUESTION:->

Maximize The Cut Segments
Given an integer N denoting the Length of a line segment. you need to cut the line segment in such a way that the cut length of a line segment each time is integer either x , y or z. and after performing all cutting operation the total number of cutted segments must be maximum.


Input
First line of input contains of an integer 'T' denoting number of test cases. First line of each testcase contains N . Second line of each testcase contains 3 space separated integers x , y and z.

Output
For each test case print in a new line an integer corresponding to the answer .


Constraints
1<=t<=70
1<=N,x,y,z<=4000


Example

Input

2
4
2 1 1
5
5 3 2

Link:-> https://practice.geeksforgeeks.org/problems/cutted-segments/0
Studylink:->https://www.youtube.com/watch?v=SU54j2_GgWM
            https://www.geeksforgeeks.org/maximize-the-number-of-segments-of-length-p-q-and-r/

*/
#include<bits/stdc++.h>
#include<climits>
#define ll long long
using namespace std;
ll findMaximum(ll l, ll p, ll q, ll r)
{

    ll dp[l + 1];

    memset(dp, -1, sizeof(dp));

    dp[0] = 0;

    for (ll i = 0; i <= l; i++) {
        if (dp[i] == -1)
            continue;

        if (i + p <= l)
            dp[i + p] = max(dp[i + p], dp[i] + 1);

        if (i + q <= l)
            dp[i + q] = max(dp[i + q], dp[i] + 1);

        if (i + r <= l)
            dp[i + r] = max(dp[i + r], dp[i] + 1);
    }
    return dp[l];
}

int main()
 {
     ll t;
     cin>>t;
     while(t--)
     {
         ll l;
         cin>>l;
         ll p,q,r;
         cin>>p>>q>>r;
         cout<<findMaximum(l, p, q, r)<<endl;
     }
	//code
	return 0;
}
