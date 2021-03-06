/* Copyright (c) 2017-2021, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <fmt/format.h>

#include <cassert>
#include <string_view>
#include <type_traits>

#include "roq/compat.h"

namespace roq {

//! Enumeration of the side of a trade
struct ROQ_PACKED Side final {
  //! helper
  enum type_t : uint8_t { UNDEFINED = 0, BUY, SELL, MAX = SELL };

  Side() = default;

  // cppcheck-suppress noExplicitConstructor
  inline Side(type_t type)  // NOLINT
      : type_(type) {}

  inline explicit Side(uint8_t type) : type_(validate(type)) {}

  inline operator type_t() const { return type_; }

  inline std::string_view name() const {
    constexpr std::string_view UNDEFINED("UNDEFINED");
    constexpr std::string_view BUY("BUY");
    constexpr std::string_view SELL("SELL");
    switch (type_) {
      case type_t::UNDEFINED:
        break;
      case type_t::BUY:
        return BUY;
      case type_t::SELL:
        return SELL;
      default:
        assert(false);
    }
    return UNDEFINED;
  }

  inline operator std::string_view() const { return name(); }

 protected:
  inline type_t validate(uint8_t type) {
    auto result = static_cast<type_t>(type);
    switch (result) {
      case type_t::UNDEFINED:
      case type_t::BUY:
      case type_t::SELL:
        return result;
      default:
        assert(false);
        return type_t::UNDEFINED;
    }
  }

 private:
  type_t type_ = type_t::UNDEFINED;
};

}  // namespace roq

template <>
struct std::is_enum<roq::Side> : std::true_type {};

template <>
struct std::underlying_type<roq::Side> {
  using type = uint8_t;
};

template <>
struct fmt::formatter<roq::Side> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return context.begin();
  }
  template <typename Context>
  auto format(const roq::Side &value, Context &context) {
    return format_to(context.out(), "{}", value.name());
  }
};
