/* QUESTION IS ----->

You are given a number N. You have to find the number of operations required to reach N from 0. You have 2 operations available:

Double the number
Add one to the number
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N.

Output:
For each test case, in a new line, print the minimum number of operations required to reach N from 0.

Constraints:
1<=T<=100
1<=N<=104

Example:
Input:
2
8
7
Input:
4
5

Explanation:
Testcase1:
Input  : N = 8
Output : 4
0 + 1 = 1, 1 + 1 = 2, 2 * 2 = 4, 4 * 2 = 8
Testcase2:
Input  : N = 7
Output : 5
0 + 1 = 1, 1 + 1 = 2, 1 + 2 = 3, 3 * 2 = 6, 6 + 1 = 7


Link to the question is : https://practice.geeksforgeeks.org/problems/find-optimum-operation/0

*/

// Solution is as follows

#include<iostream>
using namespace std;


// Recursive approach used to get rid of the problem
int result(int n)
{
    if(n==0)
        return 0;

    else if(n%2==0)
    {
        return 1+result(n/2);
    }
    else
    {
        return 1 + result(n-1);
    }
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
	    cout<<result(n)<<endl;
	}
	return 0;
}
