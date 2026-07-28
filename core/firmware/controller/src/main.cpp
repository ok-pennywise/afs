#include "scheduler.hpp"
#include <iostream>

int main(){
  std::cout << Scheduler::instance() << "\n";
  std::cout << Scheduler::instance() << "\n";
}