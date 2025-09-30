#include "client.h"
#include <iostream>

int main() {
  client::Client c;
  std::cout << c.MakeRequest("world") << std::endl;
  return 0;
}
