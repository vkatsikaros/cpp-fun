v0.1
====

Simple thread program, creates 2 threads each running a function that prints the function's name. Due to buffering and thread execution the output will vary:

```
(master)$ ./fun 
main, foo and bar now execute concurrently...
foo
bar
foo and bar completed.

(master)$ ./fun 
foo
barmain, foo and bar now execute concurrently...

foo and bar completed.

(master)$ ./fun 
main, foo and bar now execute concurrently...
bar
foo
foo and bar completed.
```