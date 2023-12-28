// Copyright (c) 2023 zozibush, All RIghts Reserved
// Authors: zozibush

#include "geometry/distance.hpp"

#include <cstdint>
#include <tuple>

namespace {
constexpr int64_t kKilometerToNanometer{static_cast<int64_t>(1.0e+12)};
constexpr int64_t kMeterToNanometer{static_cast<int64_t>(1.0e+9)};
constexpr int64_t kCentimeterToNanometer{static_cast<int64_t>(1.0e+7)};
constexpr int64_t kMillimeterToNanometer{static_cast<int64_t>(1.0e+6)};
constexpr int64_t kMicrometerToNanometer{static_cast<int64_t>(1.0e+3)};

constexpr double kNanometerToKilometer{1.0e-12};
constexpr double kNanometerToMeter{1.0e-9};
constexpr double kNanometerToCentimeter{1.0e-7};
constexpr double kNanometerToMillimeter{1.0e-6};
constexpr double kNanometerToMicrometer{1.0e-3};

auto ScaleDistanceToNanometer(double input_value,
                              zozibush::geometry::Distance::Type input_type)
    -> int64_t {
  int64_t result{static_cast<int64_t>(input_value)};
  if (input_type == zozibush::geometry::Distance::Type::kKilometer) {
    result = static_cast<int64_t>(input_value * kKilometerToNanometer);
  } else if (input_type == zozibush::geometry::Distance::Type::kMeter) {
    result = static_cast<int64_t>(input_value * kMeterToNanometer);
  } else if (input_type == zozibush::geometry::Distance::Type::kCentimeter) {
    result = static_cast<int64_t>(input_value * kCentimeterToNanometer);
  } else if (input_type == zozibush::geometry::Distance::Type::kMillimeter) {
    result = static_cast<int64_t>(input_value * kMillimeterToNanometer);
  } else if (input_type == zozibush::geometry::Distance::Type::kMicrometer) {
    result = static_cast<int64_t>(input_value * kMicrometerToNanometer);
  }
  return result;
}
}  // namespace

namespace zozibush::geometry {
Distance::Distance(double input_value, Type input_type)
    : nanometer_(ScaleDistanceToNanometer(input_value, input_type)) {}

auto Distance::GetValue(const Type &input_type) const -> double {
  auto result{static_cast<double>(nanometer_)};
  if (input_type == zozibush::geometry::Distance::Type::kKilometer) {
    result = result * kNanometerToKilometer;
  } else if (input_type == zozibush::geometry::Distance::Type::kMeter) {
    result = result * kNanometerToMeter;
  } else if (input_type == zozibush::geometry::Distance::Type::kCentimeter) {
    result = result * kNanometerToCentimeter;
  } else if (input_type == zozibush::geometry::Distance::Type::kMillimeter) {
    result = result * kNanometerToMillimeter;
  } else if (input_type == zozibush::geometry::Distance::Type::kMicrometer) {
    result = result * kNanometerToMicrometer;
  }
  return result;
}

auto Distance::SetValue(double input_value, const Type &input_type) -> void {
  nanometer_ = ScaleDistanceToNanometer(input_value, input_type);
}

auto Distance::operator==(const Distance &other) const -> bool {
  return (nanometer_ == other.nanometer_);
}
auto Distance::operator!=(const Distance &other) const -> bool {
  return (nanometer_ != other.nanometer_);
}

auto Distance::operator<(const Distance &other) const -> bool {
  return (nanometer_ < other.nanometer_);
}
auto Distance::operator<=(const Distance &other) const -> bool {
  return (nanometer_ <= other.nanometer_);
}
auto Distance::operator>(const Distance &other) const -> bool {
  return (nanometer_ > other.nanometer_);
}
auto Distance::operator>=(const Distance &other) const -> bool {
  return (nanometer_ >= other.nanometer_);
}

auto Distance::operator+(const Distance &other) const -> Distance {
  return Distance(static_cast<double>(nanometer_ + other.nanometer_),
                  Type::kNanometer);
}
auto Distance::operator-(const Distance &other) const -> Distance {
  return Distance(static_cast<double>(nanometer_ - other.nanometer_),
                  Type::kNanometer);
}
auto Distance::operator*(double scale) const -> Distance {
  return Distance(static_cast<double>(nanometer_) * scale, Type::kNanometer);
}
}  // namespace zozibush::geometry