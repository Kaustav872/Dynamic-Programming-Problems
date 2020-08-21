/* This is a program to implement the dynamic prograaming problem
   named ugly number. So what is an ugly number? Ans: An ugly number is a
   number which is only divisble by 2 ,3 and 5 and the remainder is 1. This
   problem can be solved using recusrsion also but in this case we are
   approaching with a dynamic prgramming approach.
*/

/* This whole problemis coded to submit it on the geek for geeks practice portal
   so to make this solution to accept I have made some changes like taking of unsigned
   long long instead of only unsigned values since there are lot of long inputs which
   needs some very heavy output to get displayed. Also here in this case since
   the stl lib contains a lot of predefined headers soo it increased the compile
   time so istead of stl use the iostream one
*/

#include<iostream>
using namespace std;
#define ll long long

// fucntion to check whether the number is an ugly no or not
// fuction defined long long for taking long inputs
unsigned ll getuglyno(unsigned n)
{

  // this ugly array is declared to store the ugly numbers upto n
  unsigned ll ugly[n];

  // Since we are using the concept of multipilation so here we are declaring
 // some variables which needs to be used further in the problem(will be discussed later)
  unsigned ll i2=0,i3=0,i5=0;
  unsigned ll next_multiple_of_2=2;
  unsigned ll next_multiple_of_3=3;
  unsigned ll next_multiple_of_5=5;

 // we are storing ugly no =1 since  1 is an edge case of an ugly no
  unsigned ll next_ugly_no=1;
  // initialized it to 1
  ugly[0]=1;

  // this loop strts from 1 insted of 0 since we already know the first
  // ugly no that is 1
  for(ll i=1;i<n;i++)
  {

    // here you may think why we are giving two min fuction
    // But this is because of comparison of 2 values need to be done But
    // here we have three elements so done min of 3-5 then with min of 2
    next_ugly_no=min(next_multiple_of_2,min(next_multiple_of_3,next_multiple_of_5));

    // when we find the min values
    // we update the ugly with the value of the min
    ugly[i]=next_ugly_no;

    // now we need to increment the i2 to i2+1 so that next value is
    // taken for comparison if next_ugly no is from the concerened multiplication table
    if(next_ugly_no==next_multiple_of_2)
    {
      i2=i2+1;
      next_multiple_of_2=ugly[i2]*2;
    }
    if(next_ugly_no==next_multiple_of_3)
    {
      i3=i3+1;
      next_multiple_of_3=ugly[i3]*3;
    }
    if(next_ugly_no==next_multiple_of_5)
    {
      i5=i5+1;
      next_multiple_of_5=ugly[i5]*5;
    }
  }

  // return the last ugly number of the ugly array
  return next_ugly_no;
}


// main function-------------->

int main()
{

  // for taking the no of test cases
  ll t;

  // taking the i/p
  cin>>t;

  // loop to run the no of test cases
  while(t--)
  {

  // taking the main n value which is the n'th ugly no which needs to be
  // taken out as result
  ll n;
  cin>>n;

  // call the fuction execute it and display the returned o/p
  cout<<getuglyno(n)<<endl;
  }
}
