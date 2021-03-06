/* Copyright (c) 2017-2021, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <fmt/format.h>

#include <cassert>
#include <string_view>
#include <type_traits>

#include "roq/compat.h"

namespace roq {

//! Enumeration of error types
struct ROQ_PACKED Error final {
  //! helper
  enum type_t : uint8_t {
    UNDEFINED = 0,
    UNKNOWN,
    GATEWAY_NOT_READY,
    INVALID_ACCOUNT,
    INVALID_EXCHANGE,
    INVALID_SYMBOL,
    INVALID_ORDER_TYPE,
    INVALID_TIME_IN_FORCE,
    INVALID_POSITION_EFFECT,
    INVALID_ORDER_TEMPLATE,
    NETWORK_ERROR,
    UNKNOWN_ERROR_ID,
    UNKNOWN_EXCHANGE_ORDER_ID,
    MODIFY_ORDER_NOT_SUPPORTED,
    INVALID_ORDER_ID,
    EXECUTION_INSTRUCTION_NOT_SUPPORTED,
    MAX = EXECUTION_INSTRUCTION_NOT_SUPPORTED
  };

  Error() = default;

  // cppcheck-suppress noExplicitConstructor
  inline Error(type_t type)  // NOLINT
      : type_(type) {}

  inline explicit Error(uint8_t type) : type_(validate(type)) {}

  inline operator type_t() const { return type_; }

  inline std::string_view name() const {
    constexpr std::string_view UNDEFINED("UNDEFINED");
    constexpr std::string_view UNKNOWN("UNKNOWN");
    constexpr std::string_view GATEWAY_NOT_READY("GATEWAY_NOT_READY");
    constexpr std::string_view INVALID_ACCOUNT("INVALID_ACCOUNT");
    constexpr std::string_view INVALID_EXCHANGE("INVALID_EXCHANGE");
    constexpr std::string_view INVALID_SYMBOL("INVALID_SYMBOL");
    constexpr std::string_view INVALID_ORDER_TYPE("INVALID_ORDER_TYPE");
    constexpr std::string_view INVALID_TIME_IN_FORCE("INVALID_TIME_IN_FORCE");
    constexpr std::string_view INVALID_POSITION_EFFECT("INVALID_POSITION_EFFECT");
    constexpr std::string_view INVALID_ORDER_TEMPLATE("INVALID_ORDER_TEMPLATE");
    constexpr std::string_view NETWORK_ERROR("NETWORK_ERROR");
    constexpr std::string_view UNKNOWN_ERROR_ID("UNKNOWN_ERROR_ID");
    constexpr std::string_view UNKNOWN_EXCHANGE_ORDER_ID("UNKNOWN_EXCHANGE_ORDER_ID");
    constexpr std::string_view MODIFY_ORDER_NOT_SUPPORTED("MODIFY_ORDER_NOT_SUPPORTED");
    constexpr std::string_view INVALID_ORDER_ID("INVALID_ORDER_ID");
    constexpr std::string_view EXECUTION_INSTRUCTION_NOT_SUPPORTED(
        "EXECUTION_INSTRUCTION_NOT_SUPPORTED");
    switch (type_) {
      case type_t::UNDEFINED:
        break;
      case type_t::UNKNOWN:
        return UNKNOWN;
      case type_t::GATEWAY_NOT_READY:
        return GATEWAY_NOT_READY;
      case type_t::INVALID_ACCOUNT:
        return INVALID_ACCOUNT;
      case type_t::INVALID_EXCHANGE:
        return INVALID_EXCHANGE;
      case type_t::INVALID_SYMBOL:
        return INVALID_SYMBOL;
      case type_t::INVALID_ORDER_TYPE:
        return INVALID_ORDER_TYPE;
      case type_t::INVALID_TIME_IN_FORCE:
        return INVALID_TIME_IN_FORCE;
      case type_t::INVALID_POSITION_EFFECT:
        return INVALID_POSITION_EFFECT;
      case type_t::INVALID_ORDER_TEMPLATE:
        return INVALID_ORDER_TEMPLATE;
      case type_t::NETWORK_ERROR:
        return NETWORK_ERROR;
      case type_t::UNKNOWN_ERROR_ID:
        return UNKNOWN_ERROR_ID;
      case type_t::UNKNOWN_EXCHANGE_ORDER_ID:
        return UNKNOWN_EXCHANGE_ORDER_ID;
      case type_t::MODIFY_ORDER_NOT_SUPPORTED:
        return MODIFY_ORDER_NOT_SUPPORTED;
      case type_t::INVALID_ORDER_ID:
        return INVALID_ORDER_ID;
      case type_t::EXECUTION_INSTRUCTION_NOT_SUPPORTED:
        return EXECUTION_INSTRUCTION_NOT_SUPPORTED;
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
      case type_t::UNKNOWN:
      case type_t::GATEWAY_NOT_READY:
      case type_t::INVALID_ACCOUNT:
      case type_t::INVALID_EXCHANGE:
      case type_t::INVALID_SYMBOL:
      case type_t::INVALID_ORDER_TYPE:
      case type_t::INVALID_TIME_IN_FORCE:
      case type_t::INVALID_POSITION_EFFECT:
      case type_t::INVALID_ORDER_TEMPLATE:
      case type_t::NETWORK_ERROR:
      case type_t::UNKNOWN_ERROR_ID:
      case type_t::UNKNOWN_EXCHANGE_ORDER_ID:
      case type_t::MODIFY_ORDER_NOT_SUPPORTED:
      case type_t::INVALID_ORDER_ID:
      case type_t::EXECUTION_INSTRUCTION_NOT_SUPPORTED:
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
struct std::is_enum<roq::Error> : std::true_type {};

template <>
struct std::underlying_type<roq::Error> {
  using type = uint8_t;
};

template <>
struct fmt::formatter<roq::Error> {
  template <typename Context>
  constexpr auto parse(Context &context) {
    return context.begin();
  }
  template <typename Context>
  auto format(const roq::Error &value, Context &context) {
    return format_to(context.out(), "{}", value.name());
  }
};
