# Tutorials of Data Structure

## 01_foo ~ 06_dynamic  
contains brief C tutorial  
## 05_stack  ~ 10_bst  
contains data structure codes

## Code structure

XXXX.h : contains layout definition of functions  
XXXX.c  : contains function details  
main.c  : contains main function to execute  

To use:  

```{.bash}
foo@bar:~$ make all
```

Then, Makefile will automatically write,  

```{.bash}
gcc -c XXXX.c
gcc -c main.c
gcc -o dataStructure XXXX.o XXXX.o
./dataStructure
```

and execute my codes