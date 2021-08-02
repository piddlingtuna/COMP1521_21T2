# Virtual Memory

## Why use virtual memory?

4 GB -> 8 GB

- allows a computer to use more RAM than it has
- lazy loading - only load pages you actually use at the moment into RAM
- share read-only memory like libraries
- assembly (ie MIPS) works on actual, physical addresses
    - but you won't know what actual address you will be given?
    - must semi-recompile before you run a program
    - virtual addressing avoids this

j 0xff331243 -> 0x1245566

jal 0x123456

locality.c

## Idea

Physical memory is split into equal sized frames.

Virtual memory is split into equal sized pages.

A frame is the same size as a page.

Frame/page size is a power of 2.

Whenever you access memory, translate virtual page to physical frame

Could work with varying sized pages/frames but a lot harder and slower.

Could work with non power of 2 sizes but slower - power of 2 lets you use bitwise operators.

## Translation

#define PAGE_SIZE 4096

page_table is an array
- index is your virtual memory page number.
- get back is your physical frame number

PAGE_SIZE * page_table[page_number].frame + offset;

| Virtual Page | Physical Frame|
|--------------|---------------|
| 0            | 11            |
| 1            | NA            |
| 2            | 5             |
| 3            | 2             |

What is the physical address of 5096?

Physical address = 9192

Virtual page == 5096 / 4096 = 1

Offset 5096 % 4096 = 1000

Physical page page_table[1] == 2

2 * 4096 + offset

2 * 4096 + 1000

Virtual address == 10000
Find physical address

Virtual page == 10000 / PAGESIZE = 10 000 / 4096 == 2
Offset == 10 000 % PAGESIZE == 1808

Physical page = 5

Physical address == PAGESIZE * physical_page + offset
                 == 4096 * 5 + 1808
                 == 22288


## Least Recently Used

Remember - virtual memory let's you have more virtual memory (pages) than actual physical memory (frame).

So we may have to kick out some pages if #pages > #frames.

How do we decide which frames to kick out?

Idea - page not used recently probably won't be needed again soon.

Assume we have 6 virtual memory pages and 4 physical memory frames and are using a least-recently-used (LRU) replacement strategy.

What will happen if these virtual memory pages were accessed? 

5 3 5 3 0 1 2 4 2 3 5

| Frame | Page | Last Used |
|-------|------|-----------|
| 1     | 4    | 7         |
| 2     | 3    | 9         |
| 3     | 5    | 10        |
| 4     | 2    | 8         |

// 1) The virtual page is already in a physical page
//
// 2) The virtual page is not in a physical page,
//    and there is free physical page
//
// 3) The virtual page is not in a physical page,
//    and there is no free physical page


Note: Least recently used is the best possible algorithm. However, it is too slow too to be practical in a real OS.

## Page fault

When we try to a page in physical RAM but it isn't there :(

We load it in from the hard drive.

This is how demand paging works.


## Thrashing?

Why do all the kicked out pages go...

your hard drive

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

This will cause your computer to be extremely slow.

