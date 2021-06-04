# Tutorial 1

2. Consider the following C program skeleton:

```c
int  a = 0;
char b[100] = {'\0'};

int fun1() {
    int c = 0;
    int d = 0;
    ...
}

double e = 1.0;

int fun2() {
    int f = 0;
    static int ff = 0;
    
    ...
    fun1();
    ...
}

int g = 0;

int main(void) {
    char h[10] = {'\0'};
    int i = 0;
    ...
    fun2();
    ...
}
```


Now consider what happens during the execution of this program and answer the following:

a. Which variables are accessible from within main()?

b. Which variables are accessible from within fun2()?

c. Which variables are accessible from within fun1()?

d. Which variables are removed when fun1() returns?

e. Which variables are removed when fun2() returns?

f. How long does the variable f exist during program execution?

g. How long does the variable g exist during program execution?


3. Explain the differences between the properties of the variables s1 and s2 in the following program fragment:

```c
#include <stdio.h>

char *s1 = "abc";

int main(void) {
    char *s2 = "def";
    ...
}
```

Where is each variable located in memory? Where are the strings located?


4. C's sizeof operator is a prefix unary operator (precedes its 1 operand) - what are examples of other C unary operators?


5. Why is C's sizeof operator different to other C unary & binary operators?


6. Discuss errors in this code:

```c
struct node *a = NULL;
struct node *b = NULL;
struct node *c = NULL;
struct node *d = NULL;
a = NULL:
b = malloc(sizeof b);
c = malloc(sizeof struct node);
d = malloc(8);
c = a;
d.data = 42;
c->data = 42;
```


8. Consider the following small C program:

```c
#include <stdio.h>

int main(void) {
    int n[4] = { 42, 23, 11, 7 };
    int *p;

    p = &n[0];
    printf("%p\n", p); // prints 0x7fff00000000
    printf("%lu\n", sizeof (int)); // prints 4

    // what do these statements print ?
    n[0]++;
    printf("%d\n", *p);
    p++;
    printf("%p\n", p);
    printf("%d\n", *p);

    return 0;
}
```

Assume the variable n has address 0x7fff00000000.

Assume sizeof (int) == 4.

What does the program print?


9. Consider the following pair of variables

```c
int  x;  // a variable located at address 1000 with initial value 0
int *p;  // a variable located at address 2000 with initial value 0
```

If each of the following statements is executed in turn, starting from the above state, show the value of both variables after each statement:

a. p = &x;

b. x = 5;

c. *p = 3;

d. x = (int)p;

e. x = (int)&p;

f. p = NULL;

g. *p = 1;

If any of the statements would trigger an error, state what the error would be.


10. Consider the following C program:

```c
#include <stdio.h>

int main(void) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // For loop version
    for (int i = 0; i < 10; i++) {
        printf("%d\n", nums[i]);
    }

    // While loop version
    int i = 0;
    while (i < 10) {
        printf("%d\n", nums[i]);
        i++;
    }

    return 0;
}
```

This program uses a for loop to print each element in the array

Rewrite this program using a recursive function.


12. Define a struct that might store information about a pet.

The information should include the pet's name, type of animal, age and weight.

Create a variable of this type and assign information to it to represent an axolotl named "Fluffy" of age 7 that weighs 300 grams.
