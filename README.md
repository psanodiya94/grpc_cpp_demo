# grpc_cpp_demo

This repository is a skeleton for a C++ gRPC client/server project using CMake.

Structure:

- `protocols/` - proto files and (for now) stub generated headers
- `server/` - server module (include/src)
- `client/` - client module (include/src)
- `tests/` - GoogleTest unit tests

Build (Linux):

```bash
mkdir -p build && cd build
cmake ..
cmake --build . -- -j
ctest --output-on-failure
```

Notes:

- The `protocols/include` contains stub headers so the project can compile without installing protoc/grpc yet.
- Later, replace stubs with generated files from your .proto files and link real grpc++ / protobuf libraries in CMake.

Generating real protobuf / gRPC sources:

- Install protobuf/protoc and gRPC for your platform.
- Replace the stub headers in `protocols/include` by running protoc / grpc_cpp_plugin to generate `.pb.h/.pb.cc` and `.grpc.pb.h/.grpc.pb.cc` files into `protocols/generated` (or update CMake to run codegen at configure time).
- Update `protocols/CMakeLists.txt` to add the generated sources and link the real protobuf/grpc libraries.

Testing:

- By default BUILD_TESTS is ON in the top-level `CMakeLists.txt`. To disable tests during configure:

```bash
cmake -S . -B build -DBUILD_TESTS=OFF
```
