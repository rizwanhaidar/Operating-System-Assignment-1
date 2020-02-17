#include<iostream>
#include<unistd.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

using namespace std;

int
main ()
{
  pid_t childpid_1, childpid_2, childpid_3, childpid_1_a, childpid_1_a_i,
    childpid_1_a_ii, childpid_2_a, childpid_2_a_1, childpid_2_b;
  int wait1;
  //char *argv[10];
  cout << "I am Process A (Parent of All) with Process id = " << getpid () <<
    endl;
  childpid_1 = fork ();
  wait (&wait1);
//      sleep(1);
  if (childpid_1 > 0)
    {
      childpid_2 = fork ();
      wait (&wait1);
//              sleep(1);
      if (childpid_2 > 0)
	{
	  childpid_3 = fork ();
	  wait (&wait1);
	}
    }
  if (childpid_1 == 0)
    {

      cout << "I am Process B with Process id = " << getpid () <<
	" and Parent Process id = " << getppid () << endl;

      childpid_1_a = fork ();
      wait (&wait1);

      if (childpid_1_a == 0)
	{
	  cout << "I am Process E with Process id = " << getpid () <<
	    " and Parent Process id = " << getppid () << endl;

	  childpid_1_a_i = fork ();
	  wait (&wait1);
	  if (childpid_1_a_i > 0)
	    {
	      childpid_1_a_ii = fork ();
	      wait (&wait1);
	    }
	  if (childpid_1_a_i == 0)
	    {
	      cout << "I am Process I with Process id = " << getpid () <<
		" and Parent Process id = " << getppid () << endl;
	      exit (1);
	    }
	  else if (childpid_1_a_ii == 0)
	    {
	      cout << "I am Process j with Process id = " << getpid () <<
		" and Parent Process id = " << getppid () << endl;
	      exit (1);
	    }
	  exit (1);
	}
      exit (1);
    }
  else if (childpid_2 == 0)
    {
      cout << "I am Process C with Process id = " << getpid () <<
	" and Parent Process id = " << getppid () << endl;
      childpid_2_a = fork ();
      wait (&wait1);
      if (childpid_2_a > 0)
	{
	  childpid_2_b = fork ();
	  wait (&wait1);
	}
      if (childpid_2_a == 0)
	{
	  cout << "I am Process F with Process id = " << getpid () <<
	    " and Parent Process id = " << getppid () << endl;
	  childpid_2_a_1 = fork ();
	  wait (&wait1);
	  if (childpid_2_a_1 == 0)
	    {
	      cout << "I am Process H with Process id = " << getpid () <<
		" and Parent Process id = " << getppid () << endl;
	      exit (1);
	    }	    
	  exit (1);
	}
      else if (childpid_2_b == 0)
	{
	  cout << "I am Process G with Process id = " << getpid () <<
	    " and Parent Process id = " << getppid () << endl;
	  exit (1);
	}
      exit (1);
    }
  else if (childpid_3 == 0)
    {
      cout << "I am Process D with Process id = " << getpid () <<
	" and Parent Process id = " << getppid () << endl;
      exit (1);
    }
  return 0;
}
