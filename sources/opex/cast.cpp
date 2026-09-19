module;
#include <opex/macros.hpp>

export module opex.cast;
import opex.ops;
import std;

namespace opex::cast {
  struct U8Type {
  };

  struct U16Type {
  };

  struct U32Type {
  };

  struct U64Type {
  };

  struct USizeType {
  };

  struct S8Type {
  };

  struct S16Type {
  };

  struct S32Type {
  };

  struct S64Type {
  };

  struct SSizeType {
  };

  struct F32Type {
  };

  struct F64Type {
  };

  struct BoolType {
  };

  struct CharType {
  };

  struct CharWType {
  };

  struct Char8Type {
  };

  struct Char16Type {
  };

  struct Char32Type {
  };
}

export constexpr auto U8 = opex::cast::U8Type{};
export constexpr auto U16 = opex::cast::U16Type{};
export constexpr auto U32 = opex::cast::U32Type{};
export constexpr auto U64 = opex::cast::U64Type{};
export constexpr auto USize = opex::cast::USizeType{};
export constexpr auto S8 = opex::cast::S8Type{};
export constexpr auto S16 = opex::cast::S16Type{};
export constexpr auto S32 = opex::cast::S32Type{};
export constexpr auto S64 = opex::cast::S64Type{};
export constexpr auto SSize = opex::cast::SSizeType{};
export constexpr auto F32 = opex::cast::F32Type{};
export constexpr auto F64 = opex::cast::F64Type{};
export constexpr auto Bool = opex::cast::BoolType{};
export constexpr auto Char = opex::cast::CharType{};
export constexpr auto CharW = opex::cast::CharWType{};
export constexpr auto Char8 = opex::cast::Char8Type{};
export constexpr auto Char16 = opex::cast::Char16Type{};
export constexpr auto Char32 = opex::cast::Char32Type{};

OPEX_MAKE_BIN_OP_OVERLOAD_MASTER(as);

#define OPEX_CREATE_CAST_OVERLOADS_FOR(T)\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::U8Type) {\
    OPEX_PROLOGUE;\
    return static_cast<std::uint8_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::U16Type) {\
    OPEX_PROLOGUE;\
    return static_cast<std::uint16_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::U32Type) {\
    OPEX_PROLOGUE;\
    return static_cast<std::uint32_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::U64Type) {\
    OPEX_PROLOGUE;\
    return static_cast<std::uint64_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::USizeType) {\
    OPEX_PROLOGUE;\
    return static_cast<std::size_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::S8Type) {\
    OPEX_PROLOGUE;\
    return static_cast<std::int8_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::S16Type) {\
    OPEX_PROLOGUE;\
    return static_cast<std::int16_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::S32Type) {\
    OPEX_PROLOGUE;\
    return static_cast<std::int32_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::S64Type) {\
    OPEX_PROLOGUE;\
    return static_cast<std::int64_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::SSizeType) {\
    OPEX_PROLOGUE;\
    return static_cast<std::ptrdiff_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::F32Type) {\
    OPEX_PROLOGUE;\
    return static_cast<float>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::F64Type) {\
    OPEX_PROLOGUE;\
    return static_cast<double>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::BoolType) {\
    OPEX_PROLOGUE;\
    return static_cast<bool>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::CharType) {\
    OPEX_PROLOGUE;\
    return static_cast<char>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::CharWType) {\
    OPEX_PROLOGUE;\
    return static_cast<wchar_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::Char8Type) {\
    OPEX_PROLOGUE;\
    return static_cast<char8_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::Char16Type) {\
    OPEX_PROLOGUE;\
    return static_cast<char16_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::Char32Type) {\
    OPEX_PROLOGUE;\
    return static_cast<char32_t>(lhs);\
}

OPEX_CREATE_CAST_OVERLOADS_FOR(std::uint8_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(std::uint16_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(std::uint32_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(std::uint64_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(std::int8_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(std::int16_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(std::int32_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(std::int64_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(float)
OPEX_CREATE_CAST_OVERLOADS_FOR(double)
OPEX_CREATE_CAST_OVERLOADS_FOR(bool)
OPEX_CREATE_CAST_OVERLOADS_FOR(char)
OPEX_CREATE_CAST_OVERLOADS_FOR(wchar_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(char8_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(char16_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(char32_t)
