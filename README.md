# OpEx

The `OpEx` library adds support for defining custom operators in C++. the three types of operators are currently
supported:

- Binary operations
- Postfix operations
- Unary operations

## Examples

### Binary

The float `avg` binary operator can be defined and used like this:

```C++
OPEX_MAKE_BIN_OP(avg, float, float) {
    OPEX_PROLOGUE;
    return (lhs + rhs) / 2.0f;
}
#define avg <_avg_>
```

```C++
auto x = 3.0f avg 5.0f;
```

### Postfix

The string `dbl` postfix operator can be defined and used like this:

```C++
OPEX_MAKE_POST_OP(dbl, std::string) {
    OPEX_PROLOGUE;
    return lhs + lhs;
}
#define dbl <_dbl_> 0
```

```C++
const auto w = "hello"s dbl;
```

### Unary

The (messy) unique_ptr `mov` unary operator can be defined and used like this:

```C++
OPEX_MAKE_UNARY_OP(mov, std::unique_ptr<std::string> const&) {
    return static_cast<std::unique_ptr<std::string>&&>(const_cast<std::unique_ptr<std::string>&>(rhs));
}
#define mov_new 0 <_mov_new_>
```

```C++
auto ptr2 = std::make_unique<std::string>("a unique string");
test_function_3(mov ptr2);

```

## Builtins

### Casting

The `as` macro can be used to cast numbers between integral and floating point types, mimicking Rust's `as` keyword:

```C++
auto y = 5 as F64; // y is 5.0f
```

### Error propagation

The `try` macro can be used to propagate errors in functions that return `std::optional` or `std::expected`, like Rust's
`?` operator:

```C++
auto test_function_2() -> std::expected<int, Error> {
    const auto x = try(test_function_1());
    return x + 1;
}
```

## Limitations

- Generic types cannot have operators defined over (but specializations can).
