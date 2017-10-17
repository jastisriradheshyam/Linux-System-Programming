import os #import os module
bsize = 16384 #buffer size
fin = os.open("foo", os.O_RDONLY) #open file in read only mode.
fout = os.open("bar", os.O_WRONLY | os.O_CREAT,  0o644) #open file in write and create if not found modes.

while 1: 
	buf = os.read(fin,bsize) # reads the file with specified buffer size.
	if buf: #check if any data has been retived from the file.
		os.write(fout, buf) #write the data copied from first file to second file.
	else: 
		break #break the loop if no data found on the file for copying.

os.close(fin) #close the input file.
os.close(fout) #close the output file.
