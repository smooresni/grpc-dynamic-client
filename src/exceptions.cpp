
#include "exceptions.h"

#include <cstdio>
#include <memory>

using grpc::Status;
using std::string;
using std::unique_ptr;

namespace ni {
namespace grpc_json_client {

template <typename... Arguments>
std::string FormatString(const std::string& format, const Arguments&... args) {
    int size = snprintf(nullptr, 0, format.c_str(), args...) + 1;  // + null char
    std::unique_ptr<char> buffer(new char[size]);
    snprintf(buffer.get(), size, format.c_str(), args...);
    return buffer.get();
}

ErrorCode JsonClientException::code() const {
    return _code;
}

const char* JsonClientException::what() const {
    return _message.c_str();
}

const string& JsonClientException::message() const {
    return _message;
}

string JsonClientException::FormatMessage(
    ErrorCode code, const string& summary, const string& details
) {
    string format("Error Code: %d\nError Message: %s");
    string message = FormatString(format, static_cast<int>(code), summary.c_str());
    if (!details.empty()) {
        message += "\n\n" + details;
    }
    return message;
}

string RemoteProcedureCallException::AppendStatusDetails(const Status& status, string message) {
    if (!status.ok()) {
        if (!message.empty()) {
            message += "\n\n";
        }
        string format("gRPC Error Code: %d\ngRPC Error Message: %s");
        int code_as_int = static_cast<int>(status.error_code());
        message += FormatString(format, code_as_int, status.error_message().c_str());
    }
    return message;
}

const Status& RemoteProcedureCallException::status() const {
    return _status;
}

ServiceNotFoundException::ServiceNotFoundException(const std::string& name) :
    JsonClientException(
        ErrorCode::kServiceNotFoundError, "The service \"" + name + "\" was not found.")
{}

MethodNotFoundException::MethodNotFoundException(const std::string& name) :
    JsonClientException(
        ErrorCode::kServiceNotFoundError, "The method \"" + name + "\" was not found.")
{}

}  // namespace grpc_json_client
}  // namespace ni
