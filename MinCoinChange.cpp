/* QUESTION:->

Number of Coins
Given a value V. You have to make change for V cents, given that you have infinite supply of each of C{ C1, C2, .. , Cm} valued coins. Find the minimum number of coins to make the change.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is V and N, V is the value of cents and N is the number of coins. The second line of each test case contains N input C[i], value of available coins.

Output:
Print the minimum number of coins to make the change, if not possible print "-1".

Constraints:
1 ≤ T ≤ 100
1 ≤ V ≤ 106
1 ≤ N ≤ 106
1 ≤ C[i] ≤ 106

Example:
Input:
1
7 2
2 1

Output:
4

Explanation :
Testcase 1: We can use coin with value 2 three times, and coin with value 1 one times to change a total of 7.


Link:->https://practice.geeksforgeeks.org/problems/number-of-coins/0
Study:->https://codemummy.blogspot.com/2020/08/minimum-coin-change-problem.html
        https://www.youtube.com/watch?v=I-l6PBeERuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=17&t=4s
*/



// sme code on the article I just learned the concept

#include <iostream>
using namespace std;

void mincoins(int a[],int n,int sum)
{
      int t[n+1][sum+1];

   for(int i=0;i<=n;i++)
      t[i][0]=0;

   for(int j=1;j<=sum;j++)
      t[0][j]=10000;


       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=sum;j++)
           {
              if(a[i-1]>j)
              t[i][j]=t[i-1][j];
            else
            t[i][j]=min(t[i][j-a[i-1]]+1,t[i-1][j]);

           }
       }


      if(t[n][sum]==10000)
      cout<<-1;
      else
      cout<<t[n][sum];
}



int main() {
int y; cin>>y;
while(y--)
{  int sum;   cin>>sum;

   int n;   cin>>n;

int a[n];
for(int i=0;i<n;i++)
cin>>a[i];

mincoins(a,n,sum);
  cout<<endl;
}
 return 0;
}
