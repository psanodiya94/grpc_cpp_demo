#include "client.h"

namespace client {

std::string Client::MakeRequest(const std::string &name) {
  demo::HelloRequest req;
  req.set_name(name);
  demo::HelloReply reply;
  reply.set_message("Hello, " + req.name());
  return reply.message();
}

} // namespace client
