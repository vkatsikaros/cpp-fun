// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
 
void foo() 
{
  std::cout << __FUNCTION__ << " " << std::this_thread::get_id() << "\n";
}

void bar(int x)
{
  std::cout << __FUNCTION__ << " " << std::this_thread::get_id() << "\n";
}

int main() 
{
  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (bar,0);  // spawn new thread that calls bar(0)

  std::cout << "main (" << std::this_thread::get_id() << "), foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  std::cout << "foo and bar completed.\n";

  return 0;
}