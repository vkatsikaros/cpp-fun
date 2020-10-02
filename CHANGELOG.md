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

v0.2
====
Additionally print the thread id. It messes up even more the output (buffering etc).

Can we fix this:
```
$ ./fun
bar 139651505256192
foo 139651513648896
main (139651513653056), foo and bar now execute concurrently...
foo and bar completed.

$ ./fun
main (barfoo  140355060897600140355060893440), foo and bar now execute concurrently...
140355052500736

foo and bar completed.

$ ./fun
main (140500647270208bar), foo and bar now execute concurrently...
 140500638873344
foo 140500647266048
foo and bar completed.
```

Tried several tricks, but it seems I either don't get some definitions or it's complicated. In either case, a problem for later.

I ended up with v0.1 but using `endl`.