#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string>
#include<math.h>
using namespace std;

int
main (int argc, char *argv[])
{

/*str_x , str_y, str_num */
  cout << "I am a Working Process" << endl;
  int x_arg = atoi (argv[1]);	//here i have converted  string/ char array of x in to the integer
  int y_arg = atoi (argv[2]);	//here i have converted  string/ char array of y in to the integer

  int result_to_show = 0;
  cout << "Arguments passes to me are x = " << x_arg << " y = " << y_arg <<
    endl;


  for (int i = 1; i <= x_arg; i++)
    {
      result_to_show += pow (y_arg, i);
    }
  cout << "My computed result Y^n = " << result_to_show << endl;

  return 0;

}
