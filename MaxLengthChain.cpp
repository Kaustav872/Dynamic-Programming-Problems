/* Question--->

You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. You have to find the longest chain which can be formed from the given set of pairs.


Example 1:

Input:
N = 5
P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}
Output: 3
Explanation: The given pairs are { {5, 24}, {39, 60},
{15, 28}, {27, 40}, {50, 90} },the longest chain that
can be formed is of length 3, and the chain is
{{5, 24}, {27, 40}, {50, 90}}

​Example 2:

Input:
N = 2
P[] = {5 10 , 1 11}
Output: 1
Explanation:The max length chain possible is only of
length one.


Your Task:
You don't need to read input or print anything. Your task is to Complete the function maxChainLen() which takes a structure p[] denoting the pairs and n as the number of pairs and returns the length of the longest chain formed.



Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N)

Constraints:
1<=N<=100

** For More Input/Output Examples Use 'Expected Output' option **

Q Link:> https://practice.geeksforgeeks.org/problems/max-length-chain/1
Study Link:>  https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/

*/


bool logic(struct val p, struct val q){
    return p.first < q.first;
}
/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
//Your code here
sort(p, p+n, logic);
int i,j,max=0;
int *mcl=new int[sizeof(int)*n];
for(int i=0;i<n;i++)
{
    mcl[i]=1;
}
for(i=1;i<n;i++)
{
    for(j=0;j<i;j++)
    {
        if(p[i].first > p[j].second && mcl[i] < mcl[j]+1)
        {
            mcl[i]=mcl[j]+1;
        }
    }
}

for(i=0;i<n;i++)
{
    if(max<mcl[i])
    {
        max=mcl[i];
    }
}
return max;
}
