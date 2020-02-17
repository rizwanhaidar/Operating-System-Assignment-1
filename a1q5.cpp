#include<iostream>
#include<unistd.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include <iomanip>		// std::put_time
#include <thread>		// std::this_thread::sleep_until
#include <chrono>		// std::chrono::system_clock
#include <ctime>		// std::time_t, std::tm, std::localtime, std::mktime
using namespace std;


void swap (int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// A function to implement bubble sort  
void bubbleSort (int arr[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)

    // Last i elements are already in place  
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
	swap (&arr[j], &arr[j + 1]);
}

/* Function to print an array */
void printArray (int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main ()
{
  int *arr_1_, *arr_2_;
  int size_[2];

  cout << "Enter size of ist array = ";
  cin >> size_[0];
  arr_1_ = new int[size_[0]];
  cout << endl;
  for (int j = 0; j < size_[0]; j++)
    {
      cout << "Enter " << j + 1 << " Element of " << 1 << " Array = ";
      cin >> arr_1_[j];
      cout << endl;
    }
  cout << "Enter size of 2nd array = ";
  cin >> size_[1];
  arr_2_ = new int[size_[1]];
  cout << endl;
  for (int j = 0; j < size_[1]; j++)
    {
      cout << "Enter " << j + 1 << " Element of " << 2 << " Array = ";
      cin >> arr_2_[j];
      cout << endl;
    }

  int wait_1 = -1;
  int p2;
  int p1 = fork ();
  wait (&wait_1);
  //pause(1);
  if(p1>0){
   p2 = fork ();
   wait (&wait_1);
  }
  //pause(1);
  if (p1 == 0 && p2 != 0)
    {
      cout<<"\n I am Child with pid = "<<getpid()<<" and PPID = "<<getppid()<<endl;
      bubbleSort (arr_1_, size_[0]);
      printArray (arr_1_, size_[0]);
      exit (1);
    }
  else if (p2 == 0 && p1 != 0)
    {
      cout<<"\n I am Child with pid = "<<getpid()<<" and PPID = "<<getppid()<<endl;	
      bubbleSort (arr_2_, size_[1]);
      printArray (arr_2_, size_[1]);
      exit (1);
    }


  return 0;
}
