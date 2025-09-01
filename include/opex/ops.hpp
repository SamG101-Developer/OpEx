#pragma once
#include <optional>
#include <utility>


namespace opex::bin_op {
    template <typename LHS, typename RHS, typename Unique>
    struct LeftInnerTag;

    template <typename LHS, typename RHS, typename Unique>
    struct RightInnerTag;
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


// if teh type is &&, move it, otherwise copy it
#define OPEX_MOVE_OR_COPY(obj, obj_type) \
    ([&]() -> decltype(auto) { \
        if constexpr (std::is_rvalue_reference_v<obj_type>) { \
            return std::move(obj); \
        } else { \
            return obj; \
        } \
    }())


#define OPEX_MAKE_BIN_OP(name, lhs_type, rhs_type)\
    struct name ## _unique {};\
    constexpr auto _ ## name ## _ = opex::bin_op::LeftInnerTag<lhs_type, rhs_type, name ## _unique>(); \
    inline auto operator<(lhs_type lhs, opex::bin_op::LeftInnerTag<rhs_type, lhs_type, name ## _unique> const &) -> decltype(auto) { \
        return opex::bin_op::RightInnerTag<lhs_type, rhs_type, name ## _unique>(lhs); \
    } \
    inline auto operator>(opex::bin_op::RightInnerTag<lhs_type, rhs_type, name ## _unique> const &wrap, rhs_type rhs) -> decltype(auto)

#define OPEX_MAKE_POST_OP(name, lhs_type) \
    struct name ## _unique {};\
    constexpr auto _ ## name ## _ = opex::bin_op::LeftInnerTag<int, lhs_type, name ## _unique>(); \
    inline auto operator<(lhs_type lhs, opex::bin_op::LeftInnerTag<int, lhs_type, name ## _unique> const &) -> decltype(auto) { \
        return opex::bin_op::RightInnerTag<lhs_type, int, name ## _unique>(lhs); \
    } \
    inline auto operator>(opex::bin_op::RightInnerTag<lhs_type, int, name ## _unique> const &wrap, int rhs) -> decltype(auto)

#define OPEX_MAKE_UNARY_OP(name, rhs_type) \
    struct name ## _unique {};\
    constexpr auto _ ## name ## _ = opex::bin_op::LeftInnerTag<rhs_type, int, name ## _unique>(); \
    inline auto operator<(int lhs, opex::bin_op::LeftInnerTag<rhs_type, int, name ## _unique> const &) -> decltype(auto) { \
        return opex::bin_op::RightInnerTag<int, rhs_type, name ## _unique>(lhs); \
    } \
    inline auto operator>(opex::bin_op::RightInnerTag<int, rhs_type, name ## _unique> const &wrap, rhs_type rhs) -> decltype(auto)


#define OPEX_PROLOGUE auto lhs = std::move(wrap.lhs)
