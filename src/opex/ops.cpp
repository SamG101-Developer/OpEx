export module opex.ops;
import std;


export namespace opex::bin_op {
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
