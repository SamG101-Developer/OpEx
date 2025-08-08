#include <expected>
#include <iostream>
#include <string>
#include <opex/ops.hpp>
#include <opex/try.hpp>

struct Error {};


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


auto test_function_1() -> std::expected<int, Error> {
    return std::unexpected(Error());
}


auto test_function_2() -> std::expected<int, Error> {
    const auto x = try(test_function_1());
    return x + 1;
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

    if (const auto ex = test_function_2(); ex.has_value()) {
        std::cout << ex.value() << std::endl;
    }
    else {
        std::cout << "ERROR" << std::endl;
    }

    return 0;
}
