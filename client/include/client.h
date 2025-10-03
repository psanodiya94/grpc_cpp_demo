// Minimal client header
#pragma once
#include "sample.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <memory>

namespace client {

/**
 * @brief Client class for making gRPC calls to the sample service
 */
class Client {
public:
    /**
     * @brief Construct a new Client object
     * @param channel The gRPC channel to use for communication
     */
    explicit Client(std::shared_ptr<grpc::Channel> channel);

    /**
     * @brief Make a sample RPC call
     * @param input The input string to send
     * @return std::string The response from the server
     */
    std::string SampleCall(const std::string& input);

private:
    /// The gRPC stub for making RPC calls
    std::unique_ptr<sample::SampleService::Stub> stub_;
};

}  // namespace client
