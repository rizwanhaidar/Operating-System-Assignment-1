#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main ()
{

//char *argv[10];

  cout << "I am Parent My id Is = " << getpid () << endl;
  pid_t childpid;
  int num, x, y, wait1;
  cout << "\nEnter the number times you want to make new process\n";
  cin >> num;
  if (num >= 1)
    {
/* code */

      for (int i = 0; i < num; i++)
	{

	  cout << "\nEnter  the X\n";
	  cin >> x;
	  cout << "\nEnter  the Y\n";
	  cin >> y;
	  childpid = fork ();

	  int wait11;
	  wait (&wait11);
	  if (childpid == 0)
	    {
	      cout <<
		"\nI am a Child Process calling another procees my ID is = "
		<< getpid () << " and my parent id is = " << getppid () <<
		"\n";

	      char str_x[50];
	      snprintf (str_x, sizeof (str_x), "%d", x);
	      char str_y[50];
	      snprintf (str_y, sizeof (str_y), "%d", y);
	      execl ("/home/rizwan/Desktop/Assignment1/q2pw", "./q2pw", str_x,
		     str_y, NULL);
	      printf ("Exec failed\n");
	    }
	}
    }
  else
    {
      cout << "Invalid Number of desired processes" << endl;
      exit (-1);

    }
  return 0;
}
