/* QUESTION:-->


Minimum number of deletions and insertions.
Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains integers N and M denoting the length of the strings str1 and str2. Both the strings consist of only small letter alphabets.

The second line of each test case contains the strings str1 and str2.


Output:

Print the total no of insertions and deletions to be done to convert str1 to str2. Output the answer in a new line.


Constraints:

1<= T <=100

1<= N, M <=1000


Example:

Input:

1

4 3

heap pea

Output:

3



Link:->https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions/0
Study Link:->https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/

*/


#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll lcs(string str1,string str2,ll m,ll n)
{
    ll L[m+1][n+1];
    ll i,j;

    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                L[i][j]=0;
            }
            else if(str1.at(i-1)==str2.at(j-1))
            {
                L[i][j]=L[i-1][j-1]+1;
            }
            else
            {
                L[i][j]=max(L[i-1][j],L[i][j-1]);
            }
        }
    }

    return L[m][n];
}

void printt(string str1,string str2)
{
    ll m=str1.size();
    ll n=str2.size();
    ll len=lcs(str1,str2,m,n);
    ll sum1=m-len;
    ll sum2=n-len;
    cout<<sum1+sum2<<endl;
    // cout<<(m-len)+(n-len)<<<endl;
    // cout<<(n-len)<<endl;
}
int main()
 {
	//code
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,m;
	    cin>>n>>m;
	    string str1;
	    string str2;
	    cin>>str1>>str2;
	    printt(str1,str2);

	}
	return 0;
}
