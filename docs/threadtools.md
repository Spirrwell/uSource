# namespace threadtools



## Functions

### AtomicSwapPtr

*void * AtomicSwapPtr(void ** dst, void * src)*

 Atomically swaps pointers, returning the old value of dst 

### AtomicSwapInt

*int AtomicSwapInt(int * dst, int src)*

 Atomically swaps integers, returns old value of dst 

### AtomicGetPtr

*void * AtomicGetPtr(void ** atomic)*

### AtomicGetInt

*int AtomicGetInt(int * atomic)*

### mfence

*void mfence()*

*Defined at line 55 of ./public/threadtools.h*

### lfence

*void lfence()*

*Defined at line 64 of ./public/threadtools.h*

### sfence

*void sfence()*

*Defined at line 73 of ./public/threadtools.h*



