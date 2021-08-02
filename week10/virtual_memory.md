# Virtual Memory

## Why use virtual memory?

You have 4 GB of RAM but want to run processes that take up 8 GB of RAM.

Solution: virtual memory!

Advantages:
- allows a computer to use more RAM than it actually has
- lazy loading - only load memory you actually use
- share read-only memory like libraries (think stdio.h)

Disadvantages:
- assembly (i.e. MIPS) works on actual, physical addresses
    - but you won't know what actual address you will be given?
    - must semi-recompile before you run a program
    - virtual addressing avoids this (translation is done by hardware)


q5) Each new process in a computer system will have a new address space. Which parts of the address space contain initial values at the point when the process starts running? Code? Data? Heap? Stack? Which parts of the address space can be modified as the process executes?

![address_space](address_space.png)


## What is virtual memory?

Physical memory is split into equal sized frames.

Virtual memory is split into equal sized pages.

A frame is the same size as a page.

Frame/page size is a power of 2.

Whenever you access memory, translate virtual page to physical frame

Could work with varying sized pages/frames but a lot harder and slower.

Could work with non power of 2 sizes but slower - power of 2 lets you use bitwise operators.

Q7) What is the difference between a virtual address and a physical address?


## Translation

#define PAGE_SIZE 4096

page_table is an array
- index is your virtual memory page number.
- get back is your physical frame number

page_number = virtual_address / PAGE_SIZE;
offset = virtual_address % PAGE_SIZE;
physical_address = PAGE_SIZE * page_table[page_number] + offset;

| Virtual Page | Physical Frame|
|--------------|---------------|
| 0            | 11            |
| 1            | NA            |
| 2            | 5             |
| 3            | 2             |

Given a virtual address of 10000, what is the phhysical address?

TODO

Given a virtual address of 5096, what is the phhysical address?

TODO


## Least Recently Used

Virtual memory let's you have more virtual memory (pages) than actual physical memory (frame).

So we may have to kick out some pages if #pages > #frames.

How do we decide which frames to kick out?

Page not used recently probably won't be needed again soon.

// 1) The virtual page is already in a physical page
//
// 2) The virtual page is not in a physical page,
//    and there is free physical page
//
// 3) The virtual page is not in a physical page,
//    and there is no free physical page

Q3) Assume we have 6 virtual memory pages and 4 physical memory frames
and are using a least-recently-used (LRU) replacement strategy.

What will happen if these virtual memory pages were accessed? 

5 3 5 3 0 1 2 2 3 5

Clock: 0

| Frame | Page | Last Used |
|-------|------|-----------|
| 1     |      |           |
| 2     |      |           |
| 3     |      |           |
| 4     |      |           |


Note: Least recently used is the best possible algorithm. However, it is too slow too to be practical in a real OS.

## Page fault

When we try to a page in physical RAM but it isn't there :(

We load it in from the hard drive.

This is how demand paging works.

It is really slow...

![memory_hierarchy](memory_hierarchy.gif)


## Thrashing

Why do all the kicked out pages go?

HDD is 1 000 000x slower than RAM.
SDD is 10 000x slower than RAM.

RAM - volatile - it does not save.

What will happen if these virtual memory pages were accessed? 

1 2 3 4 5 1 2 3 4 5 1 2 3 4 5

| Frame | Page | Last Used |
|-------|------|-----------|
| 1     | 5    | 5         |
| 2     | 1    | 6         |
| 3     | 2    | 7         |
| 4     | 4    | 4         |

working set > #physical RAM

We are loading pages into RAM and out of RAM very frequently.

This is called thrashing.

Your computer will be extremely slow...
