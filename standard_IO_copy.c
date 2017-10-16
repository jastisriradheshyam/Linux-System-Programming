/* Trivial file copy program using standard I/O library */

#include <stdio.h>
#define BSIZE 16384

void main()
{
 FILE *fin, *fout; /* Input and output handles */
 char buf[BSIZE]; /* Max. buffer size */
 int count; /* For no. of characters */

 fin = fopen("foo","r"); /* standard library file open funtion with read option*/`
 fout = fopen("bar", "w"); /* standard library file open funtion with write option*/`
 
 while ((count = fread(buf, 1, BSIZE,fin)) > 0)  /* standard library file read funtion*/`
 fwrite(buf, 1, count, fout);  /* standard library file write funtion*/`

 fclose(fin);  /* standard library file close function*/`
 fclose(fout);
}
