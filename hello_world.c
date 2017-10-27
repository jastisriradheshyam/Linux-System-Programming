#include <unistd.h> /* close, write functions*/
#include <fcntl.h> /* open function; O_WRONLY and O_CREAT flags */
int main ()
{
 int fd;
 fd = open("foo",O_WRONLY | O_CREAT, 0644); /* open the file with write only and create if not found with rw-r--r-- permissions*/
 write(fd, "Hello World",11); /* write "Hello World" to a file "*/
 close(fd); /* close the file discriptor */
}
