// Minimal server header
#pragma once
#include <string>
#include "sample.grpc.pb.h"

namespace server {

class Server {
public:
  Server() = default;
  std::string SayHello(const std::string &name);
};

} // namespace server
