#include "server.h"
#include <iostream>

int main() {
  server::Server s;
  std::cout << s.SayHello("world") << std::endl;
  return 0;
}
