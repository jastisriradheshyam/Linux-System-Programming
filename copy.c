/* Trivial file copy program using low-level I/O */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define BSIZE 16384  //buffer size

void main()
{
 int fin, fout; /* Input and output handles */
 char buf[BSIZE];
 int count;
 
 if ((fin = open("foo", O_RDONLY)) < 0) {
  perror("foo");
  exit(1);
 }
 if ((fout = open("bar", O_WRONLY | O_CREAT, 0644)) < 0) {
  perror("bar");
  exit(2);
 }
 while ((count = read(fin, buf, BSIZE)) > 0)
  write(fout, buf, count);
 
 close(fin);
 close(fout);
}
