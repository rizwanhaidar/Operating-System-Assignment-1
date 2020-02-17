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
  /*
     Parent solves 
     Child B solves w*(x+y) = sl_B //solved by B, will use variable from E
     Child C solves (w+v)+(v+x) = sl_C //solved by C, will use solved variables from F & G
     Child D solves (z-x) = sl_D //solved by D
     Child E solves(x+y)  = sl_E //solved by E
     Child F solves(w+v)  = sl_F //solved by F
     Child G solves(v+x)  = sl_G //solved by G
   */
  pid_t parent_id = getpid ();
  pid_t childpid_1, childpid_2, childpid_3, childpid_1_a, childpid_2_a,
    childpid_2_a_1, childpid_2_b;
  int v, w, x, y, z;		//Using variable names sames a the names that has been used in the given formula to avoid any unexpected handling.....
  int sl_B /*solved by B */ , sl_C /*solved by C */ , sl_D /*solved by D */ ,
    sl_E /*solved by E */ , sl_F /*solved by F */ , sl_G /*solved by G */ ;
  cout <<
    "\nNote: Sum of the valus W,V should be completely divisible by V,X \n";
  cout << "Enter V = ";
  cin >> v;
  cout << endl;
  cout << "Enter W = ";
  cin >> w;
  cout << endl;
  cout << "Enter X = ";
  cin >> x;
  cout << endl;
  cout << "Enter Y = ";
  cin >> y;
  cout << endl;
  cout << "Enter Z = ";
  cin >> z;
  cout << endl;

  cout << "I am Process A (Parent of All) with Process id = " << getpid () <<
    endl;
  childpid_1 = fork ();
  wait (&sl_B);
  sl_B = WEXITSTATUS (sl_B);
  //sleep(2);
  if (childpid_1 > 0)
    {
      childpid_2 = fork ();
      wait (&sl_C);
      sl_C = WEXITSTATUS (sl_C);
      //sleep(2);
      if (childpid_2 > 0)
	{
	  childpid_3 = fork ();
	  wait (&sl_D);
	  sl_D = WEXITSTATUS (sl_D);
	}
    }

  /*cout<<"I am Process A (Parent of All) with Process id = "<<getpid()<<endl;
     childpid_1 = fork();
     wait(&sl_B);
     sl_B = WEXITSTATUS(sl_B); 
     childpid_2 = fork();
     wait(&sl_C);
     sl_C = WEXITSTATUS(sl_C);
     childpid_3 = fork();
     wait(&sl_D);
     sl_D = WEXITSTATUS(sl_D);   
   */

/*
	cout<<"sl_B = "<<sl_B<<endl;
	cout<<"sl_D = "<<sl_D<<endl;
*/
  //childpid_2=childpid_3=-1;

  if (childpid_1 == 0 /* && childpid_2!=0 && childpid_3!=0 */ )
    {

      cout << "I am Process B with Process id = " << getpid () <<
	" and Parent Process id = " << getppid () << endl;
      childpid_1_a = fork ();

      wait (&sl_E);
      sl_E = WEXITSTATUS (sl_E);
      if (childpid_1_a == 0)
	{
	  cout << "I am Process E with Process id = " << getpid () <<
	    " and Parent Process id = " << getppid () << endl;
	  //                      sl_E=x+y;
	  ///                     cout<<"SL_e = "<<sl_E<<endl;
	  exit (x + y);
	}
      //cout<<"sl_E = "<<sl_E<<endl;          
      //w*sl_E                
      exit (w * (sl_E));
    }
  else if (childpid_2 == 0 /*&& childpid_1!=0 && childpid_3!=0 */ )
    {

      cout << "I am Process C with Process id = " << getpid () <<
	" and Parent Process id = " << getppid () << endl;

      childpid_2_a = fork ();
      wait (&sl_F);
      sl_F = WEXITSTATUS (sl_F);
      if (childpid_2_a > 0)
	{
	  childpid_2_b = fork ();
	  wait (&sl_G);
	  sl_G = WEXITSTATUS (sl_G);
	}
      //              cout<<"SL_F = "<<sl_F<<endl;
      //              cout<<"SL_G = "<<sl_G<<endl;

      if (childpid_2_a == 0 /*&& childpid_2_b != 0 */ )
	{
	  cout << "I am Process F with Process id = " << getpid () <<
	    " and Parent Process id = " << getppid () << endl;
	  //                      cout<<"\n v+w = "<<v+w<<endl;
	  exit (v + w);
	}

      if (childpid_2_b == 0 /*&& childpid_2_a != 0 */ )
	{
	  cout << "I am Process G with Process id = " << getpid () <<
	    " and Parent Process id = " << getppid () << endl;
	  //                      cout<<"\n v+X = "<<v+x<<endl;
	  exit (v + x);
	}
      //              cout<<sl_F+sl_G<<endl;
      exit ((sl_F) + (sl_G));
    }
  if (childpid_3 == 0 /*&& childpid_1!=0 && childpid_2!=0 */ )
    {
      cout << "I am Process D with Process id = " << getpid () <<
	" and Parent Process id = " << getppid () << endl;
      exit (z - x);
    }

  if (getpid () == parent_id)
    {
      cout << "SL_B = " << sl_B << endl;
      cout << "SL_C = " << sl_C << endl;
      cout << "SL_D = " << sl_D << endl;

      cout << "Total Sum of the Series is  = " << sl_B + sl_C + sl_D << endl;
    }

  return 0;
}
