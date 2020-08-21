/* This problem is not in any practice portal Done this just to grab some conceptual ideas
   Permutation is being claculated for a specific input using O(n) time and O(1) time complexity
*/

#include<iostream>
#define ll long long
using namespace std;
ll Permu(ll n,ll k)
{
  ll P=1;
  for(ll i=0;i<k;i++)
  {
    P*=(n-i);
  }
  return P;
}

int main()
{
  // no of test cases
  ll t;
  cin>>t;
  while(t--)
  {
    ll n;         // value P power n
    cin>>n;
    ll k;         // Base power of P
    cin>>k;
    cout<<"Permuatation of P"<<"("<<n<<","<<k<<") "<<Permu(n,k)<<endl;
  }
  return 0;
}
