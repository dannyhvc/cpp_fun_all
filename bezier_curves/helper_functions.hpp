#pragma once
#include "types.hpp"
#include <vector>
#include <memory>
#include <cassert>

/**
* range functor (function object)
* basic replica to the range in python but uses a heap vector instead of a pipe approach.
*/
class Range
{
    using value_type = std::vector<i64>;
    using pointer = std::shared_ptr<std::vector<i64>>;
    using const_type = const std::vector<i64>;

private:
    i64 start_ = 0;
    i64 end_;
    u64 step_ = 1;

public:
    Range(const i64 start, const i64 end, const u64 step = 1)
        : start_(start), end_(end), step_(step) {
        assert(step_ != 0);
    }
    ~Range() = default;

    inline value_type* operator()() const
    {
        pointer return_vec{ new value_type() };
        if (this->step_ > 0)
        {
            assert(this->start_ < this->end_ &&
                "step is normal but start is still less greater than end"
                "next time make sure start < end if step > 0"
            );
            for (i64 i = this->start_; i < this->end_;) {
                return_vec->push_back(i);
                i += this->step_;
            } // for
        }
        else
        {
            assert(this->start_ > this->end_ &&
                "step is negated but start is still less than end"
                "next time make sure start > end if step < 0"
            );
            for (i64 i = this->start_; i > this->end_;) {
                return_vec->push_back(i);
                i += this->step_;
            } // for
        } // ife
        return return_vec.get();
    }// call-op to make functor
};