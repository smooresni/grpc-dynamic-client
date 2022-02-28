
#include "grpc_json_client.h"

#include <memory>

#include "session.h"

using grpc::ChannelCredentials;
using ni::grpc_json_client::Session;
using std::shared_ptr;
using std::unique_ptr;

int32_t GrpcJsonClient_Initialize(const char* target, void** session_handle) {
    shared_ptr<ChannelCredentials> credentials = grpc::InsecureChannelCredentials();
    unique_ptr<Session> session = std::make_unique<Session>(target, credentials);
    int32_t error_code = session->QueryReflectionService();
    if (error_code >= 0) {
        *session_handle = session.release();
    }
    return error_code;
}

int32_t GrpcJsonClient_StartAsyncCall(
    void* session_handle, const char* service, const char* method, const char* request, void** tag
) {
    return static_cast<Session*>(session_handle)->StartAsyncCall(service, method, request, tag);
}

int32_t GrpcJsonClient_FinishAsyncCall(
    void* session_handle, void* tag, int32_t timeout, char* buffer, size_t* size
) {
    return static_cast<Session*>(session_handle)->FinishAsyncCall(tag, timeout, buffer, size);
}

int32_t GrpcJsonClient_BlockingCall(
    void* session_handle,
    const char* service,
    const char* method,
    const char* request,
    void** tag,
    int32_t timeout,
    char* response,
    size_t* size
) {
    return static_cast<Session*>(session_handle)->BlockingCall(
        service, method, request, tag, timeout, response, size);
}

int32_t GrpcJsonClient_LockSession(void* session_handle) {
    return static_cast<Session*>(session_handle)->Lock();
}

int32_t GrpcJsonClient_UnlockSession(void* session_handle) {
    return static_cast<Session*>(session_handle)->Unlock();
}

int32_t GrpcJsonClient_Close(void* session_handle) {
    int32_t error_code = static_cast<Session*>(session_handle)->Close();
    delete session_handle;
    return error_code;
}

int32_t GrpcJsonClient_GetError(void* session_handle, int32_t* code, char* buffer, size_t* size) {
    return Session::GetError(static_cast<Session*>(session_handle), code, buffer, size);
}
