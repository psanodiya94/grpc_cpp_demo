cmake_minimum_required(VERSION 3.15)

# Optionally generate protobuf/grpc sources using protoc at configure time.
option(USE_PROTOC "Generate C++ sources from .proto files using protoc/grpc plugin" OFF)

if(USE_PROTOC)
	find_package(Protobuf REQUIRED)
	find_program(GRPC_CPP_PLUGIN grpc_cpp_plugin)
	if(NOT GRPC_CPP_PLUGIN)
		message(FATAL_ERROR "grpc_cpp_plugin not found in PATH but USE_PROTOC=ON")
	endif()

	file(GLOB PROTO_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.proto")
	set(GENERATED_SRCS)
	set(GENERATED_HDRS)

	foreach(proto ${PROTO_FILES})
		get_filename_component(name ${proto} NAME_WE)
		set(pb_h "${CMAKE_CURRENT_BINARY_DIR}/${name}.pb.h")
		set(pb_cc "${CMAKE_CURRENT_BINARY_DIR}/${name}.pb.cc")
		set(grpc_h "${CMAKE_CURRENT_BINARY_DIR}/${name}.grpc.pb.h")
		set(grpc_cc "${CMAKE_CURRENT_BINARY_DIR}/${name}.grpc.pb.cc")

		add_custom_command(
			OUTPUT ${pb_h} ${pb_cc}
			COMMAND ${Protobuf_PROTOC_EXECUTABLE} --cpp_out=${CMAKE_CURRENT_BINARY_DIR} -I ${CMAKE_CURRENT_SOURCE_DIR} ${proto}
			DEPENDS ${proto}
			COMMENT "Generating protobuf sources for ${proto}"
		)

		add_custom_command(
			OUTPUT ${grpc_h} ${grpc_cc}
			COMMAND ${Protobuf_PROTOC_EXECUTABLE} --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN} --grpc_out=${CMAKE_CURRENT_BINARY_DIR} -I ${CMAKE_CURRENT_SOURCE_DIR} ${proto}
			DEPENDS ${proto}
			COMMENT "Generating gRPC sources for ${proto}"
		)

		list(APPEND GENERATED_SRCS ${pb_cc} ${grpc_cc})
		list(APPEND GENERATED_HDRS ${pb_h} ${grpc_h})
	endforeach()

	add_library(protocols STATIC ${GENERATED_SRCS} ${GENERATED_HDRS})
	target_include_directories(protocols PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
	target_link_libraries(protocols PUBLIC protobuf::libprotobuf)
else()
	# This folder contains proto files and (for now) stub headers so the project can compile
	add_library(protocols INTERFACE)
	target_include_directories(protocols INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
endif()
