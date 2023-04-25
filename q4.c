/*
* The program is running fine, but memory leak is detected using gdb or Valgrind
*/

/**
* Using gdb to detect the error. No stack and leak memomry are pointed out.
* Malloc of int size without free so 4bytes lost is detected
Reading symbols from ./prog...
(gdb) run
Starting program: /home/vydinh/Desktop/cs149/WS12/prog 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
[Inferior 1 (process 8586) exited normally]
(gdb) where
No stack.
(gdb) list
15	==8010== 
16	==8010== LEAK SUMMARY:
17	==8010==    definitely lost: 4 bytes in 1 blocks
18	==8010==    indirectly lost: 0 bytes in 0 blocks
19	==8010==      possibly lost: 0 bytes in 0 blocks
20	==8010==    still reachable: 0 bytes in 0 blocks
21	==8010==         suppressed: 0 bytes in 0 blocks
22	==8010== 
23	==8010== For lists of detected and suppressed errors, rerun with: -s
24	==8010== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

*/
/** Memory leak summary is showed when using Valgrind
==8010== Memcheck, a memory error detector
==8010== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8010== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==8010== Command: ./q
==8010== 
==8010== 
==8010== HEAP SUMMARY:
==8010==     in use at exit: 4 bytes in 1 blocks
==8010==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
==8010== 
==8010== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
==8010==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==8010==    by 0x10915E: main (in /home/vydinh/Desktop/cs149/WS12/q)
==8010== 
==8010== LEAK SUMMARY:
==8010==    definitely lost: 4 bytes in 1 blocks
==8010==    indirectly lost: 0 bytes in 0 blocks
==8010==      possibly lost: 0 bytes in 0 blocks
==8010==    still reachable: 0 bytes in 0 blocks
==8010==         suppressed: 0 bytes in 0 blocks
==8010== 
==8010== For lists of detected and suppressed errors, rerun with: -s
==8010== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
**/

#include <stdlib.h>
int main()
{
	int *ptr = (int *) malloc(sizeof(int));
	
	return 0;
}
