v0.6
====

Goal: Fix the 0.5 behavior

> Once you’ve seen the damage unsafe accesses can do, then it’s time we play with locking and mutual exclusion (mutexes).
>
> Here’s a reference page: http://cplusplus.com/reference/mutex/mutex/
>
> The basic pattern is this: have a std::mutex.  Then you have a contract that any time you access this variable (or variables), you must have that mutex locked.
>
> ```
> std::mutex mu;
> int val;
> ```
>
> Then in a function that does stuff to val…
>
> ```
> void do_stuff() {
>   std::lock_guard<std::mutex> l(mu);  // takes the mutex and locks it
>   val *= 2;
> }
> ```
>
> ... and this shows off a neat way to do things in C++: the `lock_guard` automatically disappears when you leave the function (going out of scope), and the destructor releases the mutex.  That means you can’t "forget to unlock it".
>
> Once you do this to every place that touches "val", you should never see inconsistent data.

v0.5
====
Goal:

> See if you can get a data structure to glitch out by having concurrent (unsafe) accesses to it.  You could have a global variable (icky, I know, but just used for educational purposes here), and have different threads writing to it.  Maybe one writes uppercase letters and another writes lowercase letters.  Then you could have a third thread reading whatever’s in it.  Then see if you ever find yourself with a mix of characters in there, or even other terrible behavior.
>
> You might need to mess with the length of the structure and/or do some dubious things involving how you set the values in there to see it reproduce.
>
> Another possibility: have a numeric value, and one thread does "a *= 2" and the other one does "a += 10" and see how mixed up it gets.  Or something like that.



v0.4
====

Goal:

Fix the 0.3 behavior with:

> Make your main() detach one of them and join() the other.  Note what this does in terms of your main()’s execution: where it gets stuck waiting on the threads to do their thing.
>
> Starting a thread should be something like this:
> 
> ```
>std::thread foo(func, "some label", 1);
>std::thread bar(func, "another label", 10);
> ```
>
> where "func" is just a function that returns void and takes a string and an int. Then you can try foo.detach() or bar.join() in your main to see how it fares.

v0.3
====

Goal:

> Make a function that takes a string and a number that displays something like "hey, I’m `<string>` and I’m alive", then sleeps for that many seconds.  Then make a couple of std::threads that both call that same function, albeit with different values for that string.
>
> What should happen initially is that your threads will still be running while your main() drops out the bottom, and you’ll get something like "terminate called without active exception" because they were still running when you exited.

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