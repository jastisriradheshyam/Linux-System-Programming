/* copy using mmcopy */

#include <sys/mman.h> /* For mmap and msync function */
#include <sys/stat.h> /* S_IRUSR,S_IWUSR flags (permissions) in open command.*/
#include <sys/types.h> /* For size_t */
#include <fcntl.h> /* For open and it's flags */
#include <stdlib.h> /* exit function */
#include <string.h> /* For string operations */
#include <stdio.h> /* For perror function*/
#include <unistd.h> /* ftruncate and lseek fucntions */

int main()
{
 char *src, *dst;
 int fin, fout;
 size_t size;

 fin = open("foo", O_RDONLY); /* open file foo */
 if (fin < 0) {
  perror("foo"); /* for printing error */
  exit(1); /* exit safely */
 }

 /* get the size of the file. We use this to specify the size of the two mapping */

 size = lseek(fin, 0, SEEK_END);

 src = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fin, 0);
 if(src == MAP_FAILED) {
  perror("mmap");
  exit(2);
 }

 fout = open("bar", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
 if (fout < 0) {
  perror("bar");
  exit(3);
 }
/* ftruncate, sets the size of the output file to match the size of the input file */
 if (ftruncate(fout, size) == -1) {
  perror("ftruncate");
  exit(3);
 }

 dst = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fout, 0);
 if (dst == MAP_FAILED) {
  perror("mmap");
  exit(4);
 }

 memcpy(dst, src, size); /*Copy bytes between mapping */
 if ( msync(dst, size, MS_SYNC) == -1) {
  perror("mmsync");
  exit(5);
 }

 exit(0);
}
