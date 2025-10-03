#include "client.h"
#include <iostream>

int main(int argc, char** argv) {
    std::string target_str = "localhost:50051";
    client::Client client(
        grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
    
    std::string response = client.SampleCall("world");
    std::cout << "Response: " << response << std::endl;
    
    return 0;
}
