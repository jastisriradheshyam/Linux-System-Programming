/* Program to demonstrate the use of writev (write vector I/O) function */
#include <stdio.h> /* perror, printf function */
#include <sys/types.h> /* ssize */
#include <fcntl.h> /* open function and flags (O_CREAT,etc) */
#include <string.h> /* strlen function */
#include <sys/uio.h> /* iovec structure, writev function */
#include <unistd.h> /* close function */
int main ()
{
 struct iovec iov[3]; /* created iovec array object */
 ssize_t no_of_bytes; /* bytes variable for error */
 int fd, i;
 char *buf[] = {"This is an example of writev function.\n","This function is specified in open group.\n","This function is used in Linux and Unix systems.\n"};
 fd = open ("writev_eg.txt", O_WRONLY | O_CREAT | O_TRUNC); /*open writev_eg.txt under write, create if not created, truncate options */
 if(fd == -1){ /* file error checking */
  perror ("open");
  return 1;
 }
 /* fill out three iovec structures */
 for (i = 0; i < 3; i++) {
  iov[i].iov_base = buf[i];
  iov[i].iov_len = strlen(buf[i]);
 }
 /* with a single call, write them all out */
 no_of_bytes = writev (fd, iov, 3); /* write the data 
 if(no_of_bytes == -1){
  perror ("writev");
  return 1;
 }
 printf ("wrote %ld bytes\n", no_of_bytes);

 if(close (fd)) { /* close file */
  perror ("close");
  return 1;
 }
 return 0;
}
