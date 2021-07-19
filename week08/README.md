# week08

## What does an operating system do?

- Manages resources (CPU time, RAM, power).

- Provides useful services called system calls (files!).

- Bytes are stored in a SSD/USB/Hard drive... but every device is different.

- The OS abstracts all the physical devices used to store bytes into files.

- A lot easier...

## What is a process?

- Execution of an individual program.

- Contains one or more threads.

- Stores state like:
    - Process ID
    - Global variables
    - Open files
    - Address space
    - Thread states

## What is a file?

- Array of bytes.

- Stored on a hard drive.

## What is a file descriptor?

- The process and OS has a table of representing open files.

- A file descriptor is just an index into the process' table.

![process_table](process_table.jpg)

## What is a man page?

man lets you browse the Unix Programmer's Manual via the terminal.

write(2) means write is in the 2nd section of the manual.

fopen(3) means fopen is in the 3rd section of the manual.

printf(1) and printf(3) are both in the manual!

Use `man 1 printf` or `man 3 printf` to access the write man page.

If in doubt, use `man man`.

- 1 are General commands
- 2 are System calls
- 3 are C library functions
- 7 are Miscellanea

## What is an environment variable?

- Just a variable in your shell!

- Always a string.

- Controls settings in programs.

- Create by `export VARIABLE=VALUE`

- Used by `$VARIABLE`

- `env | more`

## What is shuck?

[Assignment 2 has been released!](https://cgi.cse.unsw.edu.au/~cs1521/21T2/assignments/ass2/index.html)

Don't worry, the lab this week is shorter than usual :)
