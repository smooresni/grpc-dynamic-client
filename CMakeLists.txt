﻿# CMakeList.txt : CMake project for grpc_json_client, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

project(grpc-json-client)

set(CMAKE_CXX_STANDARD 11)

# Options
option(GRPC_JSON_CLIENT_BUILD_TESTS "Build gRPC JSON client tests" ON)
option(GRPC_AS_SUBMODULE "Include gRPC as git submodule" OFF)

if(GRPC_AS_SUBMODULE)
    message(STATUS "Using gRPC via add_subdirectory.")
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party/grpc/)

    set(_PROTOBUF_LIBPROTOBUF libprotobuf)
    set(_PROTOBUF_PROTOC $<TARGET_FILE:protoc>)

    set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)
    set(_GRPC_GRPCPP grpc++)
    set(_GRPC_REFLECTION grpc++_reflection)
else()
    # Find Protobuf installation
    set(protobuf_MODULE_COMPATIBLE TRUE)
    find_package(Protobuf CONFIG REQUIRED)
    message(STATUS "Using protobuf ${Protobuf_VERSION}")
        
    set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
    set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)

    # Find gRPC installation
    find_package(gRPC CONFIG REQUIRED)
    message(STATUS "Using gRPC ${gRPC_VERSION}")

    set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:gRPC::grpc_cpp_plugin>)
    set(_GRPC_GRPCPP gRPC::grpc++)
    set(_GRPC_REFLECTION gRPC::grpc++_reflection)
endif()

# Paths
set(include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include/)
set(src_dir ${CMAKE_CURRENT_SOURCE_DIR}/src/)
set(reflection_protos_dir ${CMAKE_CURRENT_SOURCE_DIR}/third_party/grpc/src/proto/grpc/reflection/v1alpha/)
set(reflection_proto_path ${reflection_protos_dir}/reflection.proto)

# Generate sources
set(reflection_pb_hdr ${src_dir}/reflection.pb.h)
set(reflection_pb_src ${src_dir}/reflection.pb.cc)
set(reflection_grpc_hdr ${src_dir}/reflection.grpc.pb.h)
set(reflection_grpc_src ${src_dir}/reflection.grpc.pb.cc)
add_custom_command(
    OUTPUT ${reflection_pb_hdr} ${reflection_pb_src} ${reflection_grpc_hdr} ${reflection_grpc_src}
    COMMAND ${_PROTOBUF_PROTOC}
    ARGS --grpc_out ${src_dir}
         --cpp_out ${src_dir}
         -I ${reflection_protos_dir}
         --plugin=protoc-gen-grpc=${_GRPC_CPP_PLUGIN_EXECUTABLE}
         ${reflection_proto_path}
    DEPENDS ${reflection_proto_path}
)

set(src_files
    ${reflection_grpc_src}
    ${reflection_pb_src}
    ${src_dir}/error_code.cpp
    ${src_dir}/exceptions.cpp
    ${src_dir}/grpc_json_client.cpp
    ${src_dir}/json_client_base.cpp
    ${src_dir}/json_serializer.cpp
    ${src_dir}/session.cpp
    ${src_dir}/unary_unary_json_client.cpp
)
set(_GRPC_LIBS
    ${_GRPC_GRPCPP}
    ${_GRPC_REFLECTION}
    ${_PROTOBUF_LIBPROTOBUF}
)

# Add shared library
add_library(grpc_json_client SHARED ${src_files})
target_include_directories(grpc_json_client PUBLIC ${include_dir})
target_link_libraries(grpc_json_client ${_GRPC_LIBS})

# Build tests
if(GRPC_JSON_CLIENT_BUILD_TESTS)
    enable_testing()
    include(GoogleTest)

    # Paths
    set(tests_dir ${CMAKE_CURRENT_SOURCE_DIR}/tests/)
    set(tests_src_dir ${tests_dir}/src/)
    set(tests_protos_dir ${tests_dir}/protos/)

    # Add GTest submodule
    set(INSTALL_GTEST OFF CACHE BOOL "")
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    add_subdirectory("${CMAKE_SOURCE_DIR}/third_party/gtest/")

    set(_GTEST GTest::gtest)
    set(_GMOCK GTest::gmock)

    # Add JSON submodule
    set(JSON_BuildTests OFF CACHE INTERNAL "")
    add_subdirectory("${CMAKE_SOURCE_DIR}/third_party/json/")

    set(_JSON nlohmann_json::nlohmann_json)

    # Generate sources
    set(testing_service_proto_path ${tests_protos_dir}/testing_service.proto)
    set(testing_service_pb_hdr ${tests_src_dir}/testing_service.pb.h)
    set(testing_service_pb_src ${tests_src_dir}/testing_service.pb.cc)
    set(testing_service_grpc_hdr ${tests_src_dir}/testing_service.grpc.pb.h)
    set(testing_service_grpc_src ${tests_src_dir}/testing_service.grpc.pb.cc)
    add_custom_command(
        OUTPUT ${testing_service_pb_hdr} ${testing_service_pb_src} ${testing_service_grpc_hdr} ${testing_service_grpc_src}
        COMMAND ${_PROTOBUF_PROTOC}
        ARGS --grpc_out ${tests_src_dir}
             --cpp_out ${tests_src_dir}
             -I ${tests_protos_dir}
             --plugin=protoc-gen-grpc=${_GRPC_CPP_PLUGIN_EXECUTABLE}
             ${testing_service_proto_path}
        DEPENDS ${testing_service_proto_path}
    )

    # Add test executable
    add_executable(tests
        ${testing_service_pb_src}
        ${testing_service_grpc_src}
        ${tests_src_dir}/grpc_json_client_no_reflection_test.cpp
        ${tests_src_dir}/grpc_json_client_offline_test.cpp
        ${tests_src_dir}/grpc_json_client_serializer_test.cpp
        ${tests_src_dir}/grpc_json_client_test.cpp
        ${tests_src_dir}/grpc_json_client_test_base.cpp
        ${tests_src_dir}/helpers.cpp
        ${tests_src_dir}/testing_server.cpp
        ${tests_src_dir}/testing_service.cpp
        ${tests_src_dir}/tests.cpp
    )
    target_link_libraries(tests
        ${_GRPC_LIBS}
        ${_GTEST}
        ${_GMOCK}
        ${_JSON}
        grpc_json_client
    )
    gtest_discover_tests(tests)

    # Add standalone testing server executable
    add_executable(standalone_testing_server
        ${testing_service_pb_src}
        ${testing_service_grpc_src}
        ${tests_src_dir}/standalone_testing_server.cpp
        ${tests_src_dir}/testing_server.cpp
        ${tests_src_dir}/testing_service.cpp
    )
    target_link_libraries(standalone_testing_server ${_GRPC_LIBS})    
endif()
