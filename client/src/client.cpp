#include "client.h"
#include <iostream>

namespace client {

Client::Client(std::shared_ptr<grpc::Channel> channel)
    : stub_(sample::SampleService::NewStub(channel)) {
}

std::string Client::SampleCall(const std::string& input) {
    sample::SampleRequest request;
    request.set_input(input);

    sample::SampleResponse response;
    grpc::ClientContext context;

    grpc::Status status = stub_->SampleCall(&context, request, &response);

    if (status.ok()) {
        return response.output();
    } else {
        std::cout << "RPC failed: " << status.error_message() << std::endl;
        return "RPC failed";
    }
}

}  // namespace client