/* Copyright (c) 2017, Hans Erik Thrane */

#pragma once

#include <quinclas/tradingapi.h>
#include <limits>

namespace examples {
namespace your {

class Strategy : public quinclas::common::Strategy {
 public:
  explicit Strategy(quinclas::common::Strategy::Dispatcher& dispatcher);

 protected:
  void on(const quinclas::common::TimerEvent&) override;
  void on(const quinclas::common::IdleEvent&) override;
  void on(const quinclas::common::GatewayStatusEvent&) override;
  void on(const quinclas::common::ReferenceDataEvent&) override;
  void on(const quinclas::common::MarketStatusEvent&) override;
  void on(const quinclas::common::MarketByPriceEvent&) override;
  void on(const quinclas::common::SessionStatisticsEvent&) override;
  void on(const quinclas::common::DailyStatisticsEvent&) override;
  void on(const quinclas::common::CreateOrderAckEvent&) override;
  void on(const quinclas::common::ModifyOrderAckEvent&) override;
  void on(const quinclas::common::CancelOrderAckEvent&) override;
  void on(const quinclas::common::OrderUpdateEvent&) override;
  void on(const quinclas::common::TradeUpdateEvent&) override;

 private:
  quinclas::common::Strategy::Dispatcher& _dispatcher;
};

}  // namespace strategy
}  // namespace examples