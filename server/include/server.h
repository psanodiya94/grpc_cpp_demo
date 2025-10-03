// Minimal server header
#pragma once
#include "sample.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <memory>

namespace server {

/**
 * @brief Implementation of the Sample gRPC service
 */
class SampleServiceImpl final : public sample::SampleService::Service {
public:
    /**
     * @brief Handle the sample RPC call
     * @param context Server context for the RPC
     * @param request The incoming request
     * @param response The response to be sent
     * @return grpc::Status The status of the RPC call
     */
    grpc::Status SampleCall(grpc::ServerContext* context,
                           const sample::SampleRequest* request,
                           sample::SampleResponse* response) override;
};

/**
 * @brief Server class that manages the gRPC service
 */
class Server {
public:
    /**
     * @brief Run the server on the specified address
     * @param server_address The address to listen on (e.g., "localhost:50051")
     */
    void Run(const std::string& server_address);

private:
    /// The underlying gRPC server instance
    std::unique_ptr<grpc::Server> server_;
};

}  // namespace server
