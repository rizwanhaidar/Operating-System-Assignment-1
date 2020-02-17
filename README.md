# Operating-System-Assignment-1
This is my first assignment of Operating system Course spring 2020.

All main details about the assignment questions is mentioned here


1)
# QUESTION NO. 01
Write a C program on Linux platform to implement the below given process hierarchy. Each process displays its name (e.g. A,B,..), its process ID and the process ID of its parent. A process used the getpid () and getppid () system calls to obtain these IDs.
Sample output of the process is: P1: ID: = 1234, Parent ID = 1123

2)
# QUESTION NO. 02
Write two different programs for Producer process Pp and worker process Pw. Pp will take an integer value as an argument: Pp num
where num indicates the total number of Pw processes it will create. Generate an error message if num is not greater then equal to one and terminate the process. Otherwise in each run {1...num} Pp will take x and y as input. It will then create a child process and replace its image with a new Pw process and pass x and y to the new process as parameters. Pw now created by Pp get two variables values x and y. Calculate the output using the following expression:
output
After displaying the value of output terminate the current Pw process

3)
# QUESTION NO. 03
Write a C program on Linux platform to implement the below given scenario. You have to solve the following equation: output= w*(x+y) + [ (w+v) + (v+x) ] - (z-x);
For computing the equation,
Parent solves
Child B solves w*(x+y)
Child C solves (w+v)+(v+x)
Child D solves (z-x)
Child E solves(x+y)
Child F solves(w+v)
Child G solves(v+x)
Child B first will first wait for child E to solve its part and store it somewhere, and child B will use the calculation performed by child E. Similarly, child C will wait for F & G to solve their parts and will use its calculated terms (Hint: You need to use wait call efficiently).
Note: You need to take inputs from user in the parent process before using fork and at last, parent will sum up the equation and show output. Also your answer can be float if it’s less than 1 then add one in your answer.

4)
Run the below code again and again, observe the output and explain what is happening.
Hint: Use "top" command and observe the process table. Also study about orphan and zombies processes.

5)
QUESTION NO. 05
You need to make a program that takes 2 arrays, and sort each array using a separate process(fork). First child should sort first array and display it and after that second child sort the second array and display it.
Important: Sequence should be followed otherwise 0 marks.
