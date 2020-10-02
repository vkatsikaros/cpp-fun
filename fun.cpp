// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
 
void foo() 
{
  std::cout << __FUNCTION__ << std::endl;
}

void bar(int x)
{
  std::cout << __FUNCTION__ << std::endl;
}

int main() 
{
  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (bar,0);  // spawn new thread that calls bar(0)

  std::cout << "main , foo and bar now execute concurrently..." << std::endl;

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  std::cout << "foo and bar completed.\n";

  return 0;
}