/*QUESTION:--->


Distinct occurrences
Given two strings S and T of length n and m respectively. find count of distinct occurrences of T in S as a sub-sequence.


Example 1:

Input:
S = "banana" , T = "ban"
Output: 3
Explanation: There are 3 sub-sequences:
[ban], [ba n], [b an].

​Example 2:

Input:
S = "geeksforgeeks" , T = "ge"
Output: 6
Explanation: There are 6 sub-sequences:
[ge], [ ge], [g e], [g e] [g e] and [ g e].



Your Task:
You don't need to read input or print anything.Your task is to complete the function subsequenceCount() which takes two strings as argument S and T and returns the count of the sub-sequences modulo 109 + 7.


Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).

Constraints:
1<=length of(T)<=100
1<=length of(S)<=8000

** For More Input/Output Examples Use 'Expected Output' option **


Link:->https://practice.geeksforgeeks.org/problems/distinct-occurrences/1
(learned the concept myself but copied the cde)

*/

#define mod 1000000007

int subsequenceCount(string S, string T)
{
  //Your code here
      int dp[S.size()+1][T.size()+1];

    for(int i=0;i<=T.size();i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<=S.size();i++){
        dp[i][0] = 1;
    }

    for(int i=1; i<=S.size(); i++){
        for(int j=1; j<=T.size(); j++){
            if(S[i-1] == T[j-1]){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % mod;
            }
            else{
                dp[i][j] = dp[i-1][j] % mod;
            }
        }
    }
    return dp[S.size()][T.size()] % mod;
}
