A few C examples, which demonstrate: 
 * C syntax;
 * How to work with pointers;
 * Build your own relatively fast and efficient `tail` utility;
 * Simple datastructures like Linked list, Doubly linked list (via Bitwise XOR links) and Binary tree.

### Traverse C program memory up and down

Compile:
```shell
$ gcc memory-up.c -o memory-up
$ gcc memory-down.c -o memory-down
```

Run (`Segmentation fault` is OK, since we reach our limits):
```shell
$ ./memory-up
1 0x7ffe272ef9b0 0x7ffe272ef9c9: �
...
5616 0x7ffe272ef9b0 0x7ffe272f0fb7: GTK_IM_MODULE=ibus 
5635 0x7ffe272ef9b0 0x7ffe272f0fca: LC_TIME=ru_RU.UTF-8 
5655 0x7ffe272ef9b0 0x7ffe272f0fde: _=./memory-up 
5669 0x7ffe272ef9b0 0x7ffe272f0fec: ./memory-up 
Segmentation fault (core dumped)
```

```shell
$ ./memory-down
1 0x7ffcc8753224 0x7ffcc8753236: t 
2 0x7ffcc8753224 0x7ffcc8753235: st 
3 0x7ffcc8753224 0x7ffcc8753234: est 
4 0x7ffcc8753224 0x7ffcc8753233: test 
5 0x7ffcc8753224 0x7ffcc8753232: utest 
6 0x7ffcc8753224 0x7ffcc8753231: 3utest 

...
3738 0x7ffcc8753224 0x7ffcc875239d:  
3739 0x7ffcc8753224 0x7ffcc875239c: � 
3740 0x7ffcc8753224 0x7ffcc875239b: �� 
3741 0x7ffcc8753224 0x7ffcc875239a: (�� 
3742 0x7ffcc8753224 0x7ffcc8752399: g(�� 
3743 0x7ffcc8753224 0x7ffcc8752398: Tg(�� 
Segmentation fault (core dumped)
```
