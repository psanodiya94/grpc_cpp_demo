// Stub for generated protobuf header (minimal)
#pragma once
#include <string>

namespace demo {

class HelloRequest {
public:
  void set_name(const std::string &n) { name_ = n; }
  const std::string& name() const { return name_; }
private:
  std::string name_;
};

class HelloReply {
public:
  void set_message(const std::string &m) { message_ = m; }
  const std::string& message() const { return message_; }
private:
  std::string message_;
};

} // namespace demo
