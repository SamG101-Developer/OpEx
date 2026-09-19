#pragma once

#define OPEX_MAKE_BIN_OP(name, lhs_type, rhs_type)                                                                                        \
  struct name ## _unique {};                                                                                                              \
  export constexpr auto _ ## name ## _ = opex::bin_op::LeftInnerTag<lhs_type, rhs_type, name ## _unique>();                               \
  export inline auto operator<(lhs_type lhs, opex::bin_op::LeftInnerTag<rhs_type, lhs_type, name ## _unique> const &) -> decltype(auto) { \
    return opex::bin_op::RightInnerTag<lhs_type, rhs_type, name ## _unique>(lhs);                                                         \
  }                                                                                                                                       \
  export inline auto operator>(opex::bin_op::RightInnerTag<lhs_type, rhs_type, name ## _unique> const &wrap, rhs_type rhs) -> decltype(auto)

#define OPEX_MAKE_POST_OP(name, lhs_type)                                                                                            \
  struct name ## _unique {};                                                                                                         \
  export constexpr auto _ ## name ## _ = opex::bin_op::LeftInnerTag<int, lhs_type, name ## _unique>();                               \
  export inline auto operator<(lhs_type lhs, opex::bin_op::LeftInnerTag<int, lhs_type, name ## _unique> const &) -> decltype(auto) { \
    return opex::bin_op::RightInnerTag<lhs_type, int, name ## _unique>(lhs);                                                         \
  }                                                                                                                                  \
  export inline auto operator>(opex::bin_op::RightInnerTag<lhs_type, int, name ## _unique> const &wrap, int rhs) -> decltype(auto)

#define OPEX_MAKE_UNARY_OP(name, rhs_type)                                                                                      \
  struct name ## _unique {};                                                                                                    \
  using name ## _unary_tag = opex::bin_op::RightInnerTag<int, rhs_type, name ## _unique>;                                       \
  export constexpr auto _ ## name ## _ = opex::bin_op::LeftInnerTag<rhs_type, int, name ## _unique>();                          \
  export inline auto operator<(int lhs, opex::bin_op::LeftInnerTag<rhs_type, int, name ## _unique> const &) -> decltype(auto) { \
    return opex::bin_op::RightInnerTag<int, rhs_type, name ## _unique>(lhs);                                                    \
  }                                                                                                                             \
  export inline auto operator>([[maybe_unused]] opex::bin_op::RightInnerTag<int, rhs_type, name ## _unique> const &wrap, rhs_type rhs) -> decltype(auto)

// Adds another operand type to an existing OPEX_MAKE_UNARY_OP.
// Must be used in the same module/TU as the original op.
// Optional trailing arguments are template parameters:
//   OPEX_MAKE_UNARY_OP_ADD_OVERLOAD(name, std::string const&) { ... }
//   OPEX_MAKE_UNARY_OP_ADD_OVERLOAD(name, T*, typename T) { ... }
#define OPEX_UNARY_OP_ADD_OVERLOAD(name, rhs_type, ...) \
  export __VA_OPT__(template <__VA_ARGS__>)                  \
  inline auto operator>([[maybe_unused]] name ## _unary_tag const &wrap, rhs_type rhs) -> decltype(auto)

#define OPEX_MAKE_BIN_OP_OVERLOAD_MASTER(name)                                                                     \
  struct name ## _unique {};                                                                                       \
  export constexpr auto _ ## name ## _ = opex::bin_op::LeftInnerTagForOverload<name ## _unique>();                 \
  export template <typename T>                                                                                     \
  inline auto operator<(T lhs, opex::bin_op::LeftInnerTagForOverload<name ## _unique> const &) -> decltype(auto) { \
    return opex::bin_op::RightInnerTagForOverload<name ## _unique, T>(lhs);                                        \
  }

#define OPEX_MAKE_BIN_OP_OVERLOAD(name, lhs_type, rhs_type) \
  export inline auto operator>(opex::bin_op::RightInnerTagForOverload<name ## _unique, lhs_type> const &wrap, rhs_type rhs) -> decltype(auto)

#define OPEX_PROLOGUE auto lhs = std::move(wrap.lhs)

#define as <_as_> // requires import opex.cast

#define try_prop(expr)                          \
  ({                                            \
    auto &&result = expr;                       \
    if (not result.has_value()) {               \
        return std::unexpected(result.error()); \
    }                                           \
    std::move(result).value();                  \
  })
