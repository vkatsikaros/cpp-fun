// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <stdlib.h>       // rand
#include <algorithm>      // std::fill
#include <string>
#include <mutex>          // std::mutex, std::lock_guard

const int len = 50;
std::string s;
std::mutex mu;

void writer(const char* x)
{
  std::lock_guard<std::mutex> lck(mu);
  for(int i = 0; i < len-1; i++)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 50 + 1));
    s.replace(i,1,x);
  }
}

void reader()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 250 + 1));
  std::cout << s << std::endl;
}

int main() 
{
  s.reserve(len);
  writer("0");
  reader();

  std::thread write_a(writer, "a");
  std::thread read_a(reader);
  std::thread write_b(writer, "b");
  std::thread read_b(reader);

  write_a.join();
  write_b.join();
  read_a.join();
  read_b.join();
  return 0;
}