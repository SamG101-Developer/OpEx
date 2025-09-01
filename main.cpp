#include <expected>
#include <iostream>
#include <string>
#include <memory>
#include <opex/ops.hpp>
#include <opex/cast.hpp>
#include <opex/try.hpp>

struct Error {
};


OPEX_MAKE_BIN_OP(avg, float, float) {
    OPEX_PROLOGUE;
    return (lhs + rhs) / 2.0f;
}
#define avg <_avg_>


OPEX_MAKE_BIN_OP(max, float, float) {
    OPEX_PROLOGUE;
    return lhs > rhs ? lhs : rhs;
}
#define max <_max_>


OPEX_MAKE_POST_OP(dbl, std::string) {
    OPEX_PROLOGUE;
    return lhs + lhs;
}
#define dbl <_dbl_> 0


OPEX_MAKE_POST_OP(mov, std::unique_ptr<std::string> const&) {
    auto &&lhs = std::move(wrap.lhs);
    return static_cast<std::unique_ptr<std::string>&&>(const_cast<std::unique_ptr<std::string>&>(lhs));
}
#define mov <_mov_> 0


OPEX_MAKE_UNARY_OP(mov_new, std::unique_ptr<std::string> const&) {
    return static_cast<std::unique_ptr<std::string>&&>(const_cast<std::unique_ptr<std::string>&>(rhs));
}
#define mov_new 0 <_mov_new_>


auto test_function_1() -> std::expected<int, Error> {
    return std::unexpected(Error());
}


auto test_function_2() -> std::expected<int, Error> {
    const auto x = try(test_function_1());
    return x + 1;
}


auto test_function_3(std::unique_ptr<std::string> &&ptr) -> void {
    std::cout << "Accepted\n";
}


int main() {
    using namespace std::string_literals;

    const auto x = 10 avg 20;
    const auto y = 20 avg 50;
    const auto z = 10 max 70;

    const auto w = "hello"s dbl;

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
    std::cout << w << std::endl;

    auto ptr = std::make_unique<std::string>("unique string");
    test_function_3(ptr mov);

    auto ptr2 = std::make_unique<std::string>("another unique string");
    test_function_3(mov_new ptr2);

    auto a = 234;
    auto e = 123 as USize;
    auto f = a as F64;

    return 0;
}
