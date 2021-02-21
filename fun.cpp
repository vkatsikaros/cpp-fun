// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <stdlib.h>       // rand
#include <algorithm>      // std::fill
#include <string>

const int len = 100;
std::string s;

void writer(const char* x)
{
  for(int i = 0; i < len; i++)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 500 + 1));
    s.replace(i,i,x);
  }
}

void reader()
{
  std::cout << s << std::endl;
}

int main() 
{
  s.reserve(len);
  writer("a");
  reader();

  std::thread write_a(writer, 'a');
/*  std::thread read_a(reader);
  std::thread write_b(writer, 'b');
  std::thread read_b(reader);

  write_a.join();
  write_b.join();
  read_a.join();
  read_b.join();
  return 0;
  */
}