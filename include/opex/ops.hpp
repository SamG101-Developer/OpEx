#pragma once
#include <optional>
#include <utility>


namespace opex::bin_op {
    template <typename LHS, typename RHS, typename Unique>
    struct LeftInnerTag;

    template <typename LHS, typename RHS, typename Unique>
    struct RightInnerTag;

    template <typename Unique>
    struct LeftInnerTagForOverload;

    template <typename Unique, typename LHS>
    struct RightInnerTagForOverload;
}


template <typename LHS, typename RHS, typename Unique>
struct opex::bin_op::LeftInnerTag {
};


template <typename LHS, typename RHS, typename Unique>
struct opex::bin_op::RightInnerTag {
    explicit RightInnerTag(LHS lhs) : lhs(std::move(lhs)) {
    }

    LHS lhs;
};


template <typename Unique>
struct opex::bin_op::LeftInnerTagForOverload {
};


template <typename Unique, typename LHS>
struct opex::bin_op::RightInnerTagForOverload {
    explicit RightInnerTagForOverload(LHS lhs) : lhs(std::move(lhs)) {
    }

    LHS lhs;
};


#define OPEX_MAKE_BIN_OP(name, lhs_type, rhs_type)                                                                                      \
    struct name ## _unique {};                                                                                                          \
    constexpr auto _ ## name ## _ = opex::bin_op::LeftInnerTag<lhs_type, rhs_type, name ## _unique>();                                  \
    inline auto operator<(lhs_type lhs, opex::bin_op::LeftInnerTag<rhs_type, lhs_type, name ## _unique> const &) -> decltype(auto) {    \
        return opex::bin_op::RightInnerTag<lhs_type, rhs_type, name ## _unique>(lhs);                                                   \
    }                                                                                                                                   \
    inline auto operator>(opex::bin_op::RightInnerTag<lhs_type, rhs_type, name ## _unique> const &wrap, rhs_type rhs) -> decltype(auto) \

#define OPEX_MAKE_POST_OP(name, lhs_type)                                                                                       \
    struct name ## _unique {};                                                                                                  \
    constexpr auto _ ## name ## _ = opex::bin_op::LeftInnerTag<int, lhs_type, name ## _unique>();                               \
    inline auto operator<(lhs_type lhs, opex::bin_op::LeftInnerTag<int, lhs_type, name ## _unique> const &) -> decltype(auto) { \
        return opex::bin_op::RightInnerTag<lhs_type, int, name ## _unique>(lhs);                                                \
    }                                                                                                                           \
    inline auto operator>(opex::bin_op::RightInnerTag<lhs_type, int, name ## _unique> const &wrap, int rhs) -> decltype(auto)   \

#define OPEX_MAKE_UNARY_OP(name, rhs_type)                                                                                         \
    struct name ## _unique {};                                                                                                     \
    constexpr auto _ ## name ## _ = opex::bin_op::LeftInnerTag<rhs_type, int, name ## _unique>();                                  \
    inline auto operator<(int lhs, opex::bin_op::LeftInnerTag<rhs_type, int, name ## _unique> const &) -> decltype(auto) {         \
        return opex::bin_op::RightInnerTag<int, rhs_type, name ## _unique>(lhs);                                                   \
    }                                                                                                                              \
    inline auto operator>(opex::bin_op::RightInnerTag<int, rhs_type, name ## _unique> const &wrap, rhs_type rhs) -> decltype(auto) \


#define OPEX_MAKE_BIN_OP_OVERLOAD_MASTER(name)                                                                         \
    struct name ## _unique {};                                                                                         \
    constexpr auto _ ## name ## _ = opex::bin_op::LeftInnerTagForOverload<name ## _unique>();                          \
    template <typename T>                                                                                              \
    inline auto operator<(T &&lhs, opex::bin_op::LeftInnerTagForOverload<name ## _unique> const &) -> decltype(auto) { \
        return opex::bin_op::RightInnerTagForOverload<name ## _unique, T>(std::forward<T>(lhs));                       \
    }                                                                                                                  \

#define OPEX_MAKE_BIN_OP_OVERLOAD(name, lhs_type, rhs_type)\
    inline auto operator>(opex::bin_op::RightInnerTagForOverload<name ## _unique, lhs_type> const &wrap, rhs_type rhs) -> decltype(auto)


#define OPEX_PROLOGUE auto lhs = std::move(wrap.lhs)
