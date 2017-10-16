/* Trivial file copy program using low-level I/O */

#include <fcntl.h> /* for open and it's flags like O_RDONLY, etc. */
#include <stdlib.h> /* for exit */
#include <unistd.h> /* for read, write, close*/
#include <stdio.h> /* for perror */
#define BSIZE 16384  //buffer size

void main()
{
 int fin, fout; /* Input and output handles */
 char buf[BSIZE];
 int count;
 
 if ((fin = open("foo", O_RDONLY)) < 0) { /* Checks if file exists and if exists then open the file */
  perror("foo"); /* Shows before error is printed */
  exit(1);
 }
 if ((fout = open("bar", O_WRONLY | O_CREAT, 0644)) < 0) {
  perror("bar"); /* Shows before error is printed */
  exit(2);
 }
 while ((count = read(fin, buf, BSIZE)) > 0)
  write(fout, buf, count); /* write to the file */
 
 close(fin);
 close(fout);
}
