// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: testing_service.proto

#include "testing_service.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace ni {
namespace grpc_json_client {
constexpr UnaryUnaryEchoMessage::UnaryUnaryEchoMessage(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : delay_(0)
  , _oneof_case_{}{}
struct UnaryUnaryEchoMessageDefaultTypeInternal {
  constexpr UnaryUnaryEchoMessageDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~UnaryUnaryEchoMessageDefaultTypeInternal() {}
  union {
    UnaryUnaryEchoMessage _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT UnaryUnaryEchoMessageDefaultTypeInternal _UnaryUnaryEchoMessage_default_instance_;
}  // namespace grpc_json_client
}  // namespace ni
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_testing_5fservice_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_testing_5fservice_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_testing_5fservice_2eproto = nullptr;

const uint32_t TableStruct_testing_5fservice_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ni::grpc_json_client::UnaryUnaryEchoMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  PROTOBUF_FIELD_OFFSET(::ni::grpc_json_client::UnaryUnaryEchoMessage, _oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ni::grpc_json_client::UnaryUnaryEchoMessage, delay_),
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  PROTOBUF_FIELD_OFFSET(::ni::grpc_json_client::UnaryUnaryEchoMessage, field_types_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::ni::grpc_json_client::UnaryUnaryEchoMessage)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::ni::grpc_json_client::_UnaryUnaryEchoMessage_default_instance_),
};

const char descriptor_table_protodef_testing_5fservice_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\025testing_service.proto\022\023ni.grpc_json_cl"
  "ient\"|\n\025UnaryUnaryEchoMessage\022\r\n\005delay\030\001"
  " \001(\005\022\026\n\014string_field\030\002 \001(\tH\000\022\025\n\013int32_fi"
  "eld\030\003 \001(\005H\000\022\026\n\014double_field\030\004 \001(\001H\000B\r\n\013f"
  "ield_types2z\n\016TestingService\022h\n\016UnaryUna"
  "ryEcho\022*.ni.grpc_json_client.UnaryUnaryE"
  "choMessage\032*.ni.grpc_json_client.UnaryUn"
  "aryEchoMessageb\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_testing_5fservice_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_testing_5fservice_2eproto = {
  false, false, 302, descriptor_table_protodef_testing_5fservice_2eproto, "testing_service.proto", 
  &descriptor_table_testing_5fservice_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_testing_5fservice_2eproto::offsets,
  file_level_metadata_testing_5fservice_2eproto, file_level_enum_descriptors_testing_5fservice_2eproto, file_level_service_descriptors_testing_5fservice_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_testing_5fservice_2eproto_getter() {
  return &descriptor_table_testing_5fservice_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_testing_5fservice_2eproto(&descriptor_table_testing_5fservice_2eproto);
namespace ni {
namespace grpc_json_client {

// ===================================================================

class UnaryUnaryEchoMessage::_Internal {
 public:
};

UnaryUnaryEchoMessage::UnaryUnaryEchoMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:ni.grpc_json_client.UnaryUnaryEchoMessage)
}
UnaryUnaryEchoMessage::UnaryUnaryEchoMessage(const UnaryUnaryEchoMessage& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  delay_ = from.delay_;
  clear_has_field_types();
  switch (from.field_types_case()) {
    case kStringField: {
      _internal_set_string_field(from._internal_string_field());
      break;
    }
    case kInt32Field: {
      _internal_set_int32_field(from._internal_int32_field());
      break;
    }
    case kDoubleField: {
      _internal_set_double_field(from._internal_double_field());
      break;
    }
    case FIELD_TYPES_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:ni.grpc_json_client.UnaryUnaryEchoMessage)
}

inline void UnaryUnaryEchoMessage::SharedCtor() {
delay_ = 0;
clear_has_field_types();
}

UnaryUnaryEchoMessage::~UnaryUnaryEchoMessage() {
  // @@protoc_insertion_point(destructor:ni.grpc_json_client.UnaryUnaryEchoMessage)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void UnaryUnaryEchoMessage::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (has_field_types()) {
    clear_field_types();
  }
}

void UnaryUnaryEchoMessage::ArenaDtor(void* object) {
  UnaryUnaryEchoMessage* _this = reinterpret_cast< UnaryUnaryEchoMessage* >(object);
  (void)_this;
}
void UnaryUnaryEchoMessage::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void UnaryUnaryEchoMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void UnaryUnaryEchoMessage::clear_field_types() {
// @@protoc_insertion_point(one_of_clear_start:ni.grpc_json_client.UnaryUnaryEchoMessage)
  switch (field_types_case()) {
    case kStringField: {
      field_types_.string_field_.Destroy(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
      break;
    }
    case kInt32Field: {
      // No need to clear
      break;
    }
    case kDoubleField: {
      // No need to clear
      break;
    }
    case FIELD_TYPES_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = FIELD_TYPES_NOT_SET;
}


void UnaryUnaryEchoMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:ni.grpc_json_client.UnaryUnaryEchoMessage)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  delay_ = 0;
  clear_field_types();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* UnaryUnaryEchoMessage::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 delay = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          delay_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string string_field = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_string_field();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ni.grpc_json_client.UnaryUnaryEchoMessage.string_field"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 int32_field = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _internal_set_int32_field(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // double double_field = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 33)) {
          _internal_set_double_field(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr));
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* UnaryUnaryEchoMessage::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ni.grpc_json_client.UnaryUnaryEchoMessage)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 delay = 1;
  if (this->_internal_delay() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_delay(), target);
  }

  // string string_field = 2;
  if (_internal_has_string_field()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_string_field().data(), static_cast<int>(this->_internal_string_field().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ni.grpc_json_client.UnaryUnaryEchoMessage.string_field");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_string_field(), target);
  }

  // int32 int32_field = 3;
  if (_internal_has_int32_field()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->_internal_int32_field(), target);
  }

  // double double_field = 4;
  if (_internal_has_double_field()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(4, this->_internal_double_field(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ni.grpc_json_client.UnaryUnaryEchoMessage)
  return target;
}

size_t UnaryUnaryEchoMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ni.grpc_json_client.UnaryUnaryEchoMessage)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 delay = 1;
  if (this->_internal_delay() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_delay());
  }

  switch (field_types_case()) {
    // string string_field = 2;
    case kStringField: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_string_field());
      break;
    }
    // int32 int32_field = 3;
    case kInt32Field: {
      total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_int32_field());
      break;
    }
    // double double_field = 4;
    case kDoubleField: {
      total_size += 1 + 8;
      break;
    }
    case FIELD_TYPES_NOT_SET: {
      break;
    }
  }
  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData UnaryUnaryEchoMessage::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    UnaryUnaryEchoMessage::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*UnaryUnaryEchoMessage::GetClassData() const { return &_class_data_; }

void UnaryUnaryEchoMessage::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<UnaryUnaryEchoMessage *>(to)->MergeFrom(
      static_cast<const UnaryUnaryEchoMessage &>(from));
}


void UnaryUnaryEchoMessage::MergeFrom(const UnaryUnaryEchoMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ni.grpc_json_client.UnaryUnaryEchoMessage)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_delay() != 0) {
    _internal_set_delay(from._internal_delay());
  }
  switch (from.field_types_case()) {
    case kStringField: {
      _internal_set_string_field(from._internal_string_field());
      break;
    }
    case kInt32Field: {
      _internal_set_int32_field(from._internal_int32_field());
      break;
    }
    case kDoubleField: {
      _internal_set_double_field(from._internal_double_field());
      break;
    }
    case FIELD_TYPES_NOT_SET: {
      break;
    }
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void UnaryUnaryEchoMessage::CopyFrom(const UnaryUnaryEchoMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ni.grpc_json_client.UnaryUnaryEchoMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UnaryUnaryEchoMessage::IsInitialized() const {
  return true;
}

void UnaryUnaryEchoMessage::InternalSwap(UnaryUnaryEchoMessage* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(delay_, other->delay_);
  swap(field_types_, other->field_types_);
  swap(_oneof_case_[0], other->_oneof_case_[0]);
}

::PROTOBUF_NAMESPACE_ID::Metadata UnaryUnaryEchoMessage::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_testing_5fservice_2eproto_getter, &descriptor_table_testing_5fservice_2eproto_once,
      file_level_metadata_testing_5fservice_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace grpc_json_client
}  // namespace ni
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ni::grpc_json_client::UnaryUnaryEchoMessage* Arena::CreateMaybeMessage< ::ni::grpc_json_client::UnaryUnaryEchoMessage >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ni::grpc_json_client::UnaryUnaryEchoMessage >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
