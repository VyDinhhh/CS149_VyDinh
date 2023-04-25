/*
* This program still runs probably. The memory leak is detected when we use 
* Valgrind. Thus, the program is running but have error in memory.
*/
/**
==12165== Memcheck, a memory error detector
==12165== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12165== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==12165== Command: ./q5
==12165== 
==12165== Invalid write of size 4
==12165==    at 0x10916D: main (in /home/vydinh/Desktop/cs149/WS12/q5)
==12165==  Address 0x4a971d0 is 0 bytes after a block of size 400 alloc'd
==12165==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==12165==    by 0x10915E: main (in /home/vydinh/Desktop/cs149/WS12/q5)
==12165== 
==12165== 
==12165== HEAP SUMMARY:
==12165==     in use at exit: 400 bytes in 1 blocks
==12165==   total heap usage: 1 allocs, 0 frees, 400 bytes allocated
==12165== 
==12165== 400 bytes in 1 blocks are definitely lost in loss record 1 of 1
==12165==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==12165==    by 0x10915E: main (in /home/vydinh/Desktop/cs149/WS12/q5)
==12165== 
==12165== LEAK SUMMARY:
==12165==    definitely lost: 400 bytes in 1 blocks
==12165==    indirectly lost: 0 bytes in 0 blocks
==12165==      possibly lost: 0 bytes in 0 blocks
==12165==    still reachable: 0 bytes in 0 blocks
==12165==         suppressed: 0 bytes in 0 blocks
==12165== 
==12165== For lists of detected and suppressed errors, rerun with: -s
==12165== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
**/
#include <stdlib.h>
int main()
{
	int *data = (int *) malloc(100*sizeof(int));
	
	data[100]=0;
	
	return 0;
}
