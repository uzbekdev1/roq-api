/* Copyright (c) 2017-2021, Hans Erik Thrane */

#pragma once

#include <chrono>
#include <string_view>

#include "roq/span.h"

namespace roq {
namespace client {

class DataFrame {
 public:
  class Handler {
   public:
    virtual void add_series(
        const roq::span<std::string_view> &values,
        const std::string_view &name,
        bool index,
        bool category) = 0;
    virtual void add_series(
        const roq::span<uint32_t> &values,
        const std::string_view &name,
        bool index,
        bool category) = 0;
    virtual void add_series(
        const roq::span<double> &values,
        const std::string_view &name,
        bool index,
        bool category) = 0;
    virtual void add_series(
        const roq::span<std::chrono::nanoseconds> &values,
        const std::string_view &name,
        bool index,
        bool category) = 0;
  };
};

}  // namespace client
}  // namespace roq
