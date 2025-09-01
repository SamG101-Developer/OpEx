#pragma once
#include <cstdint>
#include <opex/ops.hpp>
#include <sys/types.h>


namespace opex::cast {
    struct U8Type {
    };

    struct U16Type {
    };

    struct U32Type {
    };

    struct U64Type {
    };

    struct U128Type {
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

    struct S128Type {
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


constexpr auto U8 = opex::cast::U8Type{};
constexpr auto U16 = opex::cast::U16Type{};
constexpr auto U32 = opex::cast::U32Type{};
constexpr auto U64 = opex::cast::U64Type{};
constexpr auto U128 = opex::cast::U128Type{};
constexpr auto USize = opex::cast::USizeType{};
constexpr auto S8 = opex::cast::S8Type{};
constexpr auto S16 = opex::cast::S16Type{};
constexpr auto S32 = opex::cast::S32Type{};
constexpr auto S64 = opex::cast::S64Type{};
constexpr auto S128 = opex::cast::S128Type{};
constexpr auto SSize = opex::cast::SSizeType{};
constexpr auto F32 = opex::cast::F32Type{};
constexpr auto F64 = opex::cast::F64Type{};
constexpr auto Bool = opex::cast::BoolType{};
constexpr auto Char = opex::cast::CharType{};
constexpr auto CharW = opex::cast::CharWType{};
constexpr auto Char8 = opex::cast::Char8Type{};
constexpr auto Char16 = opex::cast::Char16Type{};
constexpr auto Char32 = opex::cast::Char32Type{};


OPEX_MAKE_BIN_OP_OVERLOAD_MASTER(as);


#define OPEX_CREATE_CAST_OVERLOADS_FOR(T)\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::U8Type) {\
    OPEX_PROLOGUE;\
    return static_cast<__uint8_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::U16Type) {\
    OPEX_PROLOGUE;\
    return static_cast<__uint16_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::U32Type) {\
    OPEX_PROLOGUE;\
    return static_cast<__uint32_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::U64Type) {\
    OPEX_PROLOGUE;\
    return static_cast<__uint64_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::U128Type) {\
    OPEX_PROLOGUE;\
    return static_cast<__uint128_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::USizeType) {\
    OPEX_PROLOGUE;\
    return static_cast<std::size_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::S8Type) {\
    OPEX_PROLOGUE;\
    return static_cast<__int8_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::S16Type) {\
    OPEX_PROLOGUE;\
    return static_cast<__int16_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::S32Type) {\
    OPEX_PROLOGUE;\
    return static_cast<__int32_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::S64Type) {\
    OPEX_PROLOGUE;\
    return static_cast<__int64_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::S128Type) {\
    OPEX_PROLOGUE;\
    return static_cast<__int128_t>(lhs);\
}\
OPEX_MAKE_BIN_OP_OVERLOAD(as, T, opex::cast::SSizeType) {\
    OPEX_PROLOGUE;\
    return static_cast<ssize_t>(lhs);\
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

OPEX_CREATE_CAST_OVERLOADS_FOR(__uint8_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(__uint16_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(__uint32_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(__uint64_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(__uint128_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(__int8_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(__int16_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(__int32_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(__int64_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(__int128_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(float)
OPEX_CREATE_CAST_OVERLOADS_FOR(double)
OPEX_CREATE_CAST_OVERLOADS_FOR(bool)
OPEX_CREATE_CAST_OVERLOADS_FOR(char)
OPEX_CREATE_CAST_OVERLOADS_FOR(wchar_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(char8_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(char16_t)
OPEX_CREATE_CAST_OVERLOADS_FOR(char32_t)


#define as <_as_>