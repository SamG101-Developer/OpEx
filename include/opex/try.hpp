#pragma once

/**
 * The try macro allows a std::expected type (or similar) to propagate an error is the error state is present, and
 * otherwise use the value method to unwrap the value. The usage will be something like:
 * @code
 *      auto result = try(some_expected_value);
 * @endcode
 * This will return the error out of the current function if @c some_expected_value.has_value() is false, and otherwise
 * will set result to the internal value.
 */
#define try(expr) \
    ({\
        auto &&result = expr;\
        if (not result.has_value()) { \
            return std::unexpected(result.error()); \
        } \
        std::move(result).value();\
    })
