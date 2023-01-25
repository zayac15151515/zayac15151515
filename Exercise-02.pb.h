// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Exercise-02.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Exercise_2d02_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Exercise_2d02_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Exercise_2d02_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Exercise_2d02_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Exercise_2d02_2eproto;
namespace lesson07 {
class Student;
struct StudentDefaultTypeInternal;
extern StudentDefaultTypeInternal _Student_default_instance_;
class Student_FullName;
struct Student_FullNameDefaultTypeInternal;
extern Student_FullNameDefaultTypeInternal _Student_FullName_default_instance_;
class StudentsGroup;
struct StudentsGroupDefaultTypeInternal;
extern StudentsGroupDefaultTypeInternal _StudentsGroup_default_instance_;
}  // namespace lesson07
PROTOBUF_NAMESPACE_OPEN
template<> ::lesson07::Student* Arena::CreateMaybeMessage<::lesson07::Student>(Arena*);
template<> ::lesson07::Student_FullName* Arena::CreateMaybeMessage<::lesson07::Student_FullName>(Arena*);
template<> ::lesson07::StudentsGroup* Arena::CreateMaybeMessage<::lesson07::StudentsGroup>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace lesson07 {

// ===================================================================

class Student_FullName final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:lesson07.Student.FullName) */ {
 public:
  inline Student_FullName() : Student_FullName(nullptr) {}
  ~Student_FullName() override;
  explicit PROTOBUF_CONSTEXPR Student_FullName(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Student_FullName(const Student_FullName& from);
  Student_FullName(Student_FullName&& from) noexcept
    : Student_FullName() {
    *this = ::std::move(from);
  }

  inline Student_FullName& operator=(const Student_FullName& from) {
    CopyFrom(from);
    return *this;
  }
  inline Student_FullName& operator=(Student_FullName&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Student_FullName& default_instance() {
    return *internal_default_instance();
  }
  static inline const Student_FullName* internal_default_instance() {
    return reinterpret_cast<const Student_FullName*>(
               &_Student_FullName_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Student_FullName& a, Student_FullName& b) {
    a.Swap(&b);
  }
  inline void Swap(Student_FullName* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Student_FullName* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Student_FullName* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Student_FullName>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Student_FullName& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Student_FullName& from) {
    Student_FullName::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Student_FullName* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "lesson07.Student.FullName";
  }
  protected:
  explicit Student_FullName(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFirstNameFieldNumber = 1,
    kLastNameFieldNumber = 2,
    kPatronymicFieldNumber = 3,
  };
  // string firstName = 1;
  void clear_firstname();
  const std::string& firstname() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_firstname(ArgT0&& arg0, ArgT... args);
  std::string* mutable_firstname();
  PROTOBUF_NODISCARD std::string* release_firstname();
  void set_allocated_firstname(std::string* firstname);
  private:
  const std::string& _internal_firstname() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_firstname(const std::string& value);
  std::string* _internal_mutable_firstname();
  public:

  // string lastName = 2;
  void clear_lastname();
  const std::string& lastname() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_lastname(ArgT0&& arg0, ArgT... args);
  std::string* mutable_lastname();
  PROTOBUF_NODISCARD std::string* release_lastname();
  void set_allocated_lastname(std::string* lastname);
  private:
  const std::string& _internal_lastname() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_lastname(const std::string& value);
  std::string* _internal_mutable_lastname();
  public:

  // optional string patronymic = 3;
  bool has_patronymic() const;
  private:
  bool _internal_has_patronymic() const;
  public:
  void clear_patronymic();
  const std::string& patronymic() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_patronymic(ArgT0&& arg0, ArgT... args);
  std::string* mutable_patronymic();
  PROTOBUF_NODISCARD std::string* release_patronymic();
  void set_allocated_patronymic(std::string* patronymic);
  private:
  const std::string& _internal_patronymic() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_patronymic(const std::string& value);
  std::string* _internal_mutable_patronymic();
  public:

  // @@protoc_insertion_point(class_scope:lesson07.Student.FullName)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr firstname_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr lastname_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr patronymic_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Exercise_2d02_2eproto;
};
// -------------------------------------------------------------------

class Student final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:lesson07.Student) */ {
 public:
  inline Student() : Student(nullptr) {}
  ~Student() override;
  explicit PROTOBUF_CONSTEXPR Student(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Student(const Student& from);
  Student(Student&& from) noexcept
    : Student() {
    *this = ::std::move(from);
  }

  inline Student& operator=(const Student& from) {
    CopyFrom(from);
    return *this;
  }
  inline Student& operator=(Student&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Student& default_instance() {
    return *internal_default_instance();
  }
  static inline const Student* internal_default_instance() {
    return reinterpret_cast<const Student*>(
               &_Student_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Student& a, Student& b) {
    a.Swap(&b);
  }
  inline void Swap(Student* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Student* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Student* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Student>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Student& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Student& from) {
    Student::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Student* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "lesson07.Student";
  }
  protected:
  explicit Student(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef Student_FullName FullName;

  // accessors -------------------------------------------------------

  enum : int {
    kGradesFieldNumber = 2,
    kFIOFieldNumber = 1,
    kAvgGradeFieldNumber = 3,
  };
  // repeated uint32 grades = 2 [packed = true];
  int grades_size() const;
  private:
  int _internal_grades_size() const;
  public:
  void clear_grades();
  private:
  uint32_t _internal_grades(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
      _internal_grades() const;
  void _internal_add_grades(uint32_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
      _internal_mutable_grades();
  public:
  uint32_t grades(int index) const;
  void set_grades(int index, uint32_t value);
  void add_grades(uint32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
      grades() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
      mutable_grades();

  // .lesson07.Student.FullName FIO = 1;
  bool has_fio() const;
  private:
  bool _internal_has_fio() const;
  public:
  void clear_fio();
  const ::lesson07::Student_FullName& fio() const;
  PROTOBUF_NODISCARD ::lesson07::Student_FullName* release_fio();
  ::lesson07::Student_FullName* mutable_fio();
  void set_allocated_fio(::lesson07::Student_FullName* fio);
  private:
  const ::lesson07::Student_FullName& _internal_fio() const;
  ::lesson07::Student_FullName* _internal_mutable_fio();
  public:
  void unsafe_arena_set_allocated_fio(
      ::lesson07::Student_FullName* fio);
  ::lesson07::Student_FullName* unsafe_arena_release_fio();

  // float avgGrade = 3;
  void clear_avggrade();
  float avggrade() const;
  void set_avggrade(float value);
  private:
  float _internal_avggrade() const;
  void _internal_set_avggrade(float value);
  public:

  // @@protoc_insertion_point(class_scope:lesson07.Student)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t > grades_;
    mutable std::atomic<int> _grades_cached_byte_size_;
    ::lesson07::Student_FullName* fio_;
    float avggrade_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Exercise_2d02_2eproto;
};
// -------------------------------------------------------------------

class StudentsGroup final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:lesson07.StudentsGroup) */ {
 public:
  inline StudentsGroup() : StudentsGroup(nullptr) {}
  ~StudentsGroup() override;
  explicit PROTOBUF_CONSTEXPR StudentsGroup(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  StudentsGroup(const StudentsGroup& from);
  StudentsGroup(StudentsGroup&& from) noexcept
    : StudentsGroup() {
    *this = ::std::move(from);
  }

  inline StudentsGroup& operator=(const StudentsGroup& from) {
    CopyFrom(from);
    return *this;
  }
  inline StudentsGroup& operator=(StudentsGroup&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const StudentsGroup& default_instance() {
    return *internal_default_instance();
  }
  static inline const StudentsGroup* internal_default_instance() {
    return reinterpret_cast<const StudentsGroup*>(
               &_StudentsGroup_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(StudentsGroup& a, StudentsGroup& b) {
    a.Swap(&b);
  }
  inline void Swap(StudentsGroup* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(StudentsGroup* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  StudentsGroup* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<StudentsGroup>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const StudentsGroup& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const StudentsGroup& from) {
    StudentsGroup::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(StudentsGroup* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "lesson07.StudentsGroup";
  }
  protected:
  explicit StudentsGroup(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStudentsFieldNumber = 1,
  };
  // repeated .lesson07.Student students = 1;
  int students_size() const;
  private:
  int _internal_students_size() const;
  public:
  void clear_students();
  ::lesson07::Student* mutable_students(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::lesson07::Student >*
      mutable_students();
  private:
  const ::lesson07::Student& _internal_students(int index) const;
  ::lesson07::Student* _internal_add_students();
  public:
  const ::lesson07::Student& students(int index) const;
  ::lesson07::Student* add_students();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::lesson07::Student >&
      students() const;

  // @@protoc_insertion_point(class_scope:lesson07.StudentsGroup)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::lesson07::Student > students_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Exercise_2d02_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Student_FullName

// string firstName = 1;
inline void Student_FullName::clear_firstname() {
  _impl_.firstname_.ClearToEmpty();
}
inline const std::string& Student_FullName::firstname() const {
  // @@protoc_insertion_point(field_get:lesson07.Student.FullName.firstName)
  return _internal_firstname();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Student_FullName::set_firstname(ArgT0&& arg0, ArgT... args) {
 
 _impl_.firstname_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:lesson07.Student.FullName.firstName)
}
inline std::string* Student_FullName::mutable_firstname() {
  std::string* _s = _internal_mutable_firstname();
  // @@protoc_insertion_point(field_mutable:lesson07.Student.FullName.firstName)
  return _s;
}
inline const std::string& Student_FullName::_internal_firstname() const {
  return _impl_.firstname_.Get();
}
inline void Student_FullName::_internal_set_firstname(const std::string& value) {
  
  _impl_.firstname_.Set(value, GetArenaForAllocation());
}
inline std::string* Student_FullName::_internal_mutable_firstname() {
  
  return _impl_.firstname_.Mutable(GetArenaForAllocation());
}
inline std::string* Student_FullName::release_firstname() {
  // @@protoc_insertion_point(field_release:lesson07.Student.FullName.firstName)
  return _impl_.firstname_.Release();
}
inline void Student_FullName::set_allocated_firstname(std::string* firstname) {
  if (firstname != nullptr) {
    
  } else {
    
  }
  _impl_.firstname_.SetAllocated(firstname, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.firstname_.IsDefault()) {
    _impl_.firstname_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:lesson07.Student.FullName.firstName)
}

// string lastName = 2;
inline void Student_FullName::clear_lastname() {
  _impl_.lastname_.ClearToEmpty();
}
inline const std::string& Student_FullName::lastname() const {
  // @@protoc_insertion_point(field_get:lesson07.Student.FullName.lastName)
  return _internal_lastname();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Student_FullName::set_lastname(ArgT0&& arg0, ArgT... args) {
 
 _impl_.lastname_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:lesson07.Student.FullName.lastName)
}
inline std::string* Student_FullName::mutable_lastname() {
  std::string* _s = _internal_mutable_lastname();
  // @@protoc_insertion_point(field_mutable:lesson07.Student.FullName.lastName)
  return _s;
}
inline const std::string& Student_FullName::_internal_lastname() const {
  return _impl_.lastname_.Get();
}
inline void Student_FullName::_internal_set_lastname(const std::string& value) {
  
  _impl_.lastname_.Set(value, GetArenaForAllocation());
}
inline std::string* Student_FullName::_internal_mutable_lastname() {
  
  return _impl_.lastname_.Mutable(GetArenaForAllocation());
}
inline std::string* Student_FullName::release_lastname() {
  // @@protoc_insertion_point(field_release:lesson07.Student.FullName.lastName)
  return _impl_.lastname_.Release();
}
inline void Student_FullName::set_allocated_lastname(std::string* lastname) {
  if (lastname != nullptr) {
    
  } else {
    
  }
  _impl_.lastname_.SetAllocated(lastname, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.lastname_.IsDefault()) {
    _impl_.lastname_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:lesson07.Student.FullName.lastName)
}

// optional string patronymic = 3;
inline bool Student_FullName::_internal_has_patronymic() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Student_FullName::has_patronymic() const {
  return _internal_has_patronymic();
}
inline void Student_FullName::clear_patronymic() {
  _impl_.patronymic_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Student_FullName::patronymic() const {
  // @@protoc_insertion_point(field_get:lesson07.Student.FullName.patronymic)
  return _internal_patronymic();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Student_FullName::set_patronymic(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000001u;
 _impl_.patronymic_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:lesson07.Student.FullName.patronymic)
}
inline std::string* Student_FullName::mutable_patronymic() {
  std::string* _s = _internal_mutable_patronymic();
  // @@protoc_insertion_point(field_mutable:lesson07.Student.FullName.patronymic)
  return _s;
}
inline const std::string& Student_FullName::_internal_patronymic() const {
  return _impl_.patronymic_.Get();
}
inline void Student_FullName::_internal_set_patronymic(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.patronymic_.Set(value, GetArenaForAllocation());
}
inline std::string* Student_FullName::_internal_mutable_patronymic() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.patronymic_.Mutable(GetArenaForAllocation());
}
inline std::string* Student_FullName::release_patronymic() {
  // @@protoc_insertion_point(field_release:lesson07.Student.FullName.patronymic)
  if (!_internal_has_patronymic()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* p = _impl_.patronymic_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.patronymic_.IsDefault()) {
    _impl_.patronymic_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void Student_FullName::set_allocated_patronymic(std::string* patronymic) {
  if (patronymic != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.patronymic_.SetAllocated(patronymic, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.patronymic_.IsDefault()) {
    _impl_.patronymic_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:lesson07.Student.FullName.patronymic)
}

// -------------------------------------------------------------------

// Student

// .lesson07.Student.FullName FIO = 1;
inline bool Student::_internal_has_fio() const {
  return this != internal_default_instance() && _impl_.fio_ != nullptr;
}
inline bool Student::has_fio() const {
  return _internal_has_fio();
}
inline void Student::clear_fio() {
  if (GetArenaForAllocation() == nullptr && _impl_.fio_ != nullptr) {
    delete _impl_.fio_;
  }
  _impl_.fio_ = nullptr;
}
inline const ::lesson07::Student_FullName& Student::_internal_fio() const {
  const ::lesson07::Student_FullName* p = _impl_.fio_;
  return p != nullptr ? *p : reinterpret_cast<const ::lesson07::Student_FullName&>(
      ::lesson07::_Student_FullName_default_instance_);
}
inline const ::lesson07::Student_FullName& Student::fio() const {
  // @@protoc_insertion_point(field_get:lesson07.Student.FIO)
  return _internal_fio();
}
inline void Student::unsafe_arena_set_allocated_fio(
    ::lesson07::Student_FullName* fio) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.fio_);
  }
  _impl_.fio_ = fio;
  if (fio) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:lesson07.Student.FIO)
}
inline ::lesson07::Student_FullName* Student::release_fio() {
  
  ::lesson07::Student_FullName* temp = _impl_.fio_;
  _impl_.fio_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::lesson07::Student_FullName* Student::unsafe_arena_release_fio() {
  // @@protoc_insertion_point(field_release:lesson07.Student.FIO)
  
  ::lesson07::Student_FullName* temp = _impl_.fio_;
  _impl_.fio_ = nullptr;
  return temp;
}
inline ::lesson07::Student_FullName* Student::_internal_mutable_fio() {
  
  if (_impl_.fio_ == nullptr) {
    auto* p = CreateMaybeMessage<::lesson07::Student_FullName>(GetArenaForAllocation());
    _impl_.fio_ = p;
  }
  return _impl_.fio_;
}
inline ::lesson07::Student_FullName* Student::mutable_fio() {
  ::lesson07::Student_FullName* _msg = _internal_mutable_fio();
  // @@protoc_insertion_point(field_mutable:lesson07.Student.FIO)
  return _msg;
}
inline void Student::set_allocated_fio(::lesson07::Student_FullName* fio) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete _impl_.fio_;
  }
  if (fio) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(fio);
    if (message_arena != submessage_arena) {
      fio = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, fio, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.fio_ = fio;
  // @@protoc_insertion_point(field_set_allocated:lesson07.Student.FIO)
}

// repeated uint32 grades = 2 [packed = true];
inline int Student::_internal_grades_size() const {
  return _impl_.grades_.size();
}
inline int Student::grades_size() const {
  return _internal_grades_size();
}
inline void Student::clear_grades() {
  _impl_.grades_.Clear();
}
inline uint32_t Student::_internal_grades(int index) const {
  return _impl_.grades_.Get(index);
}
inline uint32_t Student::grades(int index) const {
  // @@protoc_insertion_point(field_get:lesson07.Student.grades)
  return _internal_grades(index);
}
inline void Student::set_grades(int index, uint32_t value) {
  _impl_.grades_.Set(index, value);
  // @@protoc_insertion_point(field_set:lesson07.Student.grades)
}
inline void Student::_internal_add_grades(uint32_t value) {
  _impl_.grades_.Add(value);
}
inline void Student::add_grades(uint32_t value) {
  _internal_add_grades(value);
  // @@protoc_insertion_point(field_add:lesson07.Student.grades)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
Student::_internal_grades() const {
  return _impl_.grades_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
Student::grades() const {
  // @@protoc_insertion_point(field_list:lesson07.Student.grades)
  return _internal_grades();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
Student::_internal_mutable_grades() {
  return &_impl_.grades_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
Student::mutable_grades() {
  // @@protoc_insertion_point(field_mutable_list:lesson07.Student.grades)
  return _internal_mutable_grades();
}

// float avgGrade = 3;
inline void Student::clear_avggrade() {
  _impl_.avggrade_ = 0;
}
inline float Student::_internal_avggrade() const {
  return _impl_.avggrade_;
}
inline float Student::avggrade() const {
  // @@protoc_insertion_point(field_get:lesson07.Student.avgGrade)
  return _internal_avggrade();
}
inline void Student::_internal_set_avggrade(float value) {
  
  _impl_.avggrade_ = value;
}
inline void Student::set_avggrade(float value) {
  _internal_set_avggrade(value);
  // @@protoc_insertion_point(field_set:lesson07.Student.avgGrade)
}

// -------------------------------------------------------------------

// StudentsGroup

// repeated .lesson07.Student students = 1;
inline int StudentsGroup::_internal_students_size() const {
  return _impl_.students_.size();
}
inline int StudentsGroup::students_size() const {
  return _internal_students_size();
}
inline void StudentsGroup::clear_students() {
  _impl_.students_.Clear();
}
inline ::lesson07::Student* StudentsGroup::mutable_students(int index) {
  // @@protoc_insertion_point(field_mutable:lesson07.StudentsGroup.students)
  return _impl_.students_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::lesson07::Student >*
StudentsGroup::mutable_students() {
  // @@protoc_insertion_point(field_mutable_list:lesson07.StudentsGroup.students)
  return &_impl_.students_;
}
inline const ::lesson07::Student& StudentsGroup::_internal_students(int index) const {
  return _impl_.students_.Get(index);
}
inline const ::lesson07::Student& StudentsGroup::students(int index) const {
  // @@protoc_insertion_point(field_get:lesson07.StudentsGroup.students)
  return _internal_students(index);
}
inline ::lesson07::Student* StudentsGroup::_internal_add_students() {
  return _impl_.students_.Add();
}
inline ::lesson07::Student* StudentsGroup::add_students() {
  ::lesson07::Student* _add = _internal_add_students();
  // @@protoc_insertion_point(field_add:lesson07.StudentsGroup.students)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::lesson07::Student >&
StudentsGroup::students() const {
  // @@protoc_insertion_point(field_list:lesson07.StudentsGroup.students)
  return _impl_.students_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace lesson07

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Exercise_2d02_2eproto