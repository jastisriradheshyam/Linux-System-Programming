# Linux-System-Programming
Linux System Programs. Based on **IEEE POSIX.1** standard and closer to **SUSv4** standard.  
More on [Linux System Programming Wiki](https://github.com/jastisriradheshyam/Linux-System-Programming/wiki)

## hello_world.c
Simple program that **write "Hello World"** to a file.

## low_level_copy.c
Simple copy program that **copies** data from file "foo" to file "bar". File operations are done with only **low-level I/O functions**.

## standard_IO_copy.c
Simple copy program that **copies** data from file "foo" to file "bar". File operations are done with **standard library I/O functions**.

## :snake: python_system_call_copy.py
Simple python program to **copy** data from file "foo" to "bar". File operations are _**with**_ system call interface **(OS Module)**.

## :snake: python_standard_copy.py
Simple python program to **copy** data from file "foo" to "bar". File operations are _**without**_ system call interface **(OS Module)**.

## writev.c
Simple program to demonstrate the use of **writev (write vector I/O)** function which is a part of **Scatter/Gather I/O**.

## mmcopy.c
Simple program to demonstrate the use of **mmap (memory map)** function.
