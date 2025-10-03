#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "client.h"
#include "server.h"

/**
 * @brief Mock implementation of the Sample service for testing
 */
class MockSampleService : public sample::SampleService::Service {
public:
    MOCK_METHOD(grpc::Status, SampleCall,
                (grpc::ServerContext*,
                 const sample::SampleRequest*,
                 sample::SampleResponse*),
                (override));
};

/**
 * @brief Test that the client can make a request
 */
TEST(ClientServerTest, ClientMakesRequest) {
    // Setup client with a test channel
    auto channel = grpc::CreateChannel("localhost:50051",
                                     grpc::InsecureChannelCredentials());
    client::Client client(channel);
    
    // Make the request
    std::string response = client.SampleCall("Alice");
    
    // In a real test, we'd want to use a mock channel to verify the request
    EXPECT_FALSE(response.empty());
}

/**
 * @brief Test that the server responds correctly to requests
 */
TEST(ClientServerTest, ServerRespondsToRequest) {
    // Setup mock service
    MockSampleService service;
    
    // Setup expectation
    EXPECT_CALL(service, SampleCall(testing::_, testing::_, testing::_))
        .WillOnce([](grpc::ServerContext*,
                     const sample::SampleRequest* request,
                     sample::SampleResponse* response) {
            response->set_output("Hello, " + request->input());
            return grpc::Status::OK;
        });
    
    // Create a test server with a specific port
    std::string server_address = "localhost:50052";
    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server = builder.BuildAndStart();
    ASSERT_NE(server, nullptr) << "Failed to start server";
    
    // Make a client request using the same address
    auto channel = grpc::CreateChannel(server_address,
                                     grpc::InsecureChannelCredentials());
    client::Client client(channel);
    
    std::string response = client.SampleCall("Bob");
    EXPECT_EQ(response, "Hello, Bob");
    
    server->Shutdown();
    server->Wait();
}
