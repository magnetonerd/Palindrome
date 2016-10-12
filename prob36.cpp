#include <iostream>

/*
  Program Name: Palandrom addition

  Coder: Christopher Rodgers

  Description: This is a program that adds up 
  all numbers less than 1 million that are 
  palandroms in base 10 and base 2.
*/

int palfind(register int x, int b) //linear time palandrom sieve
{
  register int revl, d; //saves variables directly to the memory registers

  revl = 0;
  
  while( x != 0)
    {
      d = x % b; //This puts the number in terms of the relevent base
      x = x/b; //slices off the least significant digit with each iteration
      revl = (revl * b) + d; //This constructs the number to be checked
    }

  return revl;
}

bool check(int rev, int n) //logical check to make sure that number is a palandrom
{
  bool r;
  
  if(rev == n) r = true;
  else r = false;

  return r;
}

int main()
{
  register int total, n, c;
  register int rev1, rev2;

  total = 0;

  for (n = 0; n < 1000000; ++n)
    {
      c = n + 1; //number being tested
      
      rev1 = palfind(c, 10); //running the pal sieve for base 10

      check(rev1,c); //If the pal sieve returns the original number it is a pal in base 10

      rev2 = palfind(c,2); //running the pal sieve for base 2

      check(rev2,c); //If the palsieve returns the original number it is a pal in base 2

      if(check(rev1,c))
	{
	  if(check(rev2,c))
	    {
	      total += c; //If the number checks out for both bases add it to the total
	    }
	}
    }

  std::cout << total << std::endl;

  return 0;
}

      
