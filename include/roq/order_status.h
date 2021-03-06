/* Copyright (c) 2017-2021, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <fmt/format.h>

#include <cassert>
#include <string_view>
#include <type_traits>

#include "roq/compat.h"

namespace roq {

//! Enumeration of order status types
struct ROQ_PACKED OrderStatus final {
  //! helper
  enum type_t : uint8_t {
    UNDEFINED = 0,
    SENT,
    REJECTED,
    ACCEPTED,
    PENDING,
    WORKING,
    COMPLETED,
    CANCELED,
    MAX = CANCELED
  };

  OrderStatus() = default;

  // cppcheck-suppress noExplicitConstructor
  inline OrderStatus(type_t type)  // NOLINT
      : type_(type) {}

  inline explicit OrderStatus(uint8_t type) : type_(validate(type)) {}

  inline operator type_t() const { return type_; }

  inline std::string_view name() const {
    constexpr std::string_view UNDEFINED("UNDEFINED");
    constexpr std::string_view SENT("SENT");
    constexpr std::string_view REJECTED("REJECTED");
    constexpr std::string_view ACCEPTED("ACCEPTED");
    constexpr std::string_view PENDING("PENDING");
    constexpr std::string_view WORKING("WORKING");
    constexpr std::string_view COMPLETED("COMPLETED");
    constexpr std::string_view CANCELED("CANCELED");
    switch (type_) {
      case type_t::UNDEFINED:
        break;
      case type_t::SENT:
        return SENT;
      case type_t::REJECTED:
        return REJECTED;
      case type_t::ACCEPTED:
        return ACCEPTED;
      case type_t::PENDING:
        return PENDING;
      case type_t::WORKING:
        return WORKING;
      case type_t::COMPLETED:
        return COMPLETED;
      case type_t::CANCELED:
        return CANCELED;
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
      case type_t::SENT:
      case type_t::REJECTED:
      case type_t::ACCEPTED:
      case type_t::PENDING:
      case type_t::WORKING:
      case type_t::COMPLETED:
      case type_t::CANCELED:
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
struct std::is_enum<roq::OrderStatus> : std::true_type {};

template <>
struct std::underlying_type<roq::OrderStatus> {
  using type = uint8_t;
};

template <>
struct fmt::formatter<roq::OrderStatus> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return context.begin();
  }
  template <typename Context>
  auto format(const roq::OrderStatus &value, Context &context) {
    return format_to(context.out(), "{}", value.name());
  }
};
