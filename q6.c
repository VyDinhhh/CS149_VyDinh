/*
** The program still runs and prints out the first value.
* However, there are still error in memory and is detected by Valgrind
==23773== Conditional jump or move depends on uninitialised value(s)
==23773==    at 0x48E1C85: __vfprintf_internal (vfprintf-internal.c:1516)
==23773==    by 0x48CC81E: printf (printf.c:33)
==23773==    by 0x10919E: main (in /home/vydinh/Desktop/cs149/WS12/q66)
==23773== 
First value 0==23773== 
==23773== HEAP SUMMARY:
==23773==     in use at exit: 400 bytes in 1 blocks
==23773==   total heap usage: 2 allocs, 1 frees, 1,424 bytes allocated
==23773== 
==23773== 400 bytes in 1 blocks are definitely lost in loss record 1 of 1
==23773==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==23773==    by 0x10917E: main (in /home/vydinh/Desktop/cs149/WS12/q66)
==23773== 
==23773== LEAK SUMMARY:
==23773==    definitely lost: 400 bytes in 1 blocks
==23773==    indirectly lost: 0 bytes in 0 blocks
==23773==      possibly lost: 0 bytes in 0 blocks
==23773==    still reachable: 0 bytes in 0 blocks
==23773==         suppressed: 0 bytes in 0 blocks

*/
#include <stdlib.h>
#include <stdio.h>
int main()
{
	int *data = (int *) malloc(100*sizeof(int));
	
	// *data=0;
	
	printf("First value %d", data[0]);
	
	return 0;
}
