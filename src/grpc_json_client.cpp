#include "grpc_json_client.h"

#include "session.h"

using grpc::ChannelCredentials;
using ni::grpc_json_client::Session;
using std::shared_ptr;

int32_t InitInsecure(const char* target, void** session_handle)
{
    shared_ptr<ChannelCredentials> credentials = grpc::InsecureChannelCredentials();
    Session* session = new Session(target, credentials);
    *session_handle = session;
    return session->Init();
}

int32_t StartAsyncCall(void* session_handle, const char* service, const char* method, const char* request, void** tag)
{
    return static_cast<Session*>(session_handle)->StartAsyncCall(service, method, request, tag);
}

int32_t FinishAsyncCall(void* session_handle, void* tag, int32_t timeout, char* buffer, size_t* size)
{
    return static_cast<Session*>(session_handle)->FinishAsyncCall(tag, timeout, buffer, size);
}

int32_t Close(void* session_handle)
{
    int32_t error_code = static_cast<Session*>(session_handle)->Close();
    delete session_handle;
    return error_code;
}

int32_t GetError(void* session_handle, int32_t* code, char* description, size_t* size)
{
    return Session::GetError(static_cast<Session*>(session_handle), code, description, size);
}
