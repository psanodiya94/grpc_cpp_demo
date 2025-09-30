// Minimal client header
#pragma once
#include <string>
#include "sample.pb.h"

namespace client {

class Client {
public:
  Client() = default;
  std::string MakeRequest(const std::string &name);
};

} // namespace client
