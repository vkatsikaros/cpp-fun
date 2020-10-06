// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
 
void func(std::string label, int n = 1)
{
  std::cout << label << " is alive!" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(n));
}

int main() 
{
  std::thread first (func, "a", 1);     // spawn new thread that calls foo()
  std::thread second (func, "b", 10);   // spawn new thread that calls bar(0)

  std::cout << "main , first and second now execute concurrently..." << std::endl;

  // The main was previously blocking until first and second finished.
  // Removing join is excpected to break some things. For example main
  // will finish before second.
  // So this happens:
  //
  // $ ./fun
  // main , first and second now execute concurrently...b is alive!
  //
  // first and second completed
  // terminate called without an active exception
  // a is alive!
  // Aborted (core dumped)


  std::cout << "first and second completed" << std::endl;

  return 0;
}