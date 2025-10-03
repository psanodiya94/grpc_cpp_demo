#include "server.h"
#include <iostream>

namespace server {

grpc::Status SampleServiceImpl::SampleCall(grpc::ServerContext* context,
                                         const sample::SampleRequest* request,
                                         sample::SampleResponse* response) {
    response->set_output("Hello, " + request->input());
    return grpc::Status::OK;
}

void Server::Run(const std::string& server_address) {
    SampleServiceImpl service;
    grpc::ServerBuilder builder;
    
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    
    server_ = builder.BuildAndStart();
    std::cout << "Server listening on " << server_address << std::endl;
    
    server_->Wait();
}

}  // namespace server
