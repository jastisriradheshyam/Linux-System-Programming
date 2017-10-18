#include <stdio.h>
#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/uio.h>
#include <unistd.h>
int main ()
{
 struct iovec iov[3];
 ssize_t no_of_bytes;
 int fd, i;
 char *buf[] = {"This is an example of writev function.\n","This function is specified in open group.\n","This function is used in Linux and Unix systems.\n"};
 fd = open ("writev_eg.txt", O_WRONLY | O_CREAT | O_TRUNC);
 if(fd == -1){
  perror ("open");
  return 1;
 }
 /* fill out three iovec structures */
 for (i = 0; i < 3; i++) {
  iov[i].iov_base = buf[i];
  iov[i].iov_len = strlen(buf[i]);
 }
 /* with a single call, write them all out */
 no_of_bytes = writev (fd, iov, 3);
 if(no_of_bytes == -1){
  perror ("writev");
  return 1;
 }
 printf ("wrote %ld bytes\n", no_of_bytes);

 if(close (fd)) {
  perror ("close");
  return 1;
 }
 return 0;
}
