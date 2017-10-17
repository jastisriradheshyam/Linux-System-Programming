#program without system call interface (OS module)
with open('foo','rb') as fin: #open the file foo with read binary option and returning file object to fin.
	with open('bar', 'wb') as fout: #open the file bar with write binary option and returning file object to fout.
		fout.write(fin.read()) # read function reads the file and return the read data to write function to write the data.
# Here with 'with' file close after the inner commands get executed.
