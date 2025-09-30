#include <gtest/gtest.h>
#include "client.h"
#include "server.h"

TEST(ClientServerTest, ClientMakesRequest) {
  client::Client c;
  auto resp = c.MakeRequest("Alice");
  EXPECT_EQ(resp, "Hello, Alice");
}

TEST(ClientServerTest, ServerResponds) {
  server::Server s;
  auto resp = s.SayHello("Bob");
  EXPECT_EQ(resp, "Hello, Bob from server");
}
