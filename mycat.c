/**
 * Description: This program modified from original mycat.c
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 3/27/2023
 * Creation date: 3/17/2023
 **/
#include "apue.h"

#define	BUFFSIZE	4096

int
main(void)
{
	int		n;
	char	buf[BUFFSIZE];
	

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	{
		fprintf(stderr, "\nNumber of bytes %d - ", n);
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");
	}

	if (n < 0)
		err_sys("read error");

	exit(0);
}
