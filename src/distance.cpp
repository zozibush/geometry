// Copyright (c) 2023 zozibush, All RIghts Reserved
// Authors: zozibush

#include "geometry/distance.hpp"

#include <cstdint>

namespace {
auto ScaleDistanceToNanometer(double input_value,
                              zozibush::geometry::Distance::Type input_type)
    -> int64_t {
  int64_t result{static_cast<int64_t>(input_value)};
  if (input_type == zozibush::geometry::Distance::Type::kKilometer) {
    result = static_cast<int64_t>(input_value * 1.0e+12);
  } else if (input_type == zozibush::geometry::Distance::Type::kMeter) {
    result = static_cast<int64_t>(input_value * 1.0e+9);
  } else if (input_type == zozibush::geometry::Distance::Type::kCentimeter) {
    result = static_cast<int64_t>(input_value * 1.0e+7);
  } else if (input_type == zozibush::geometry::Distance::Type::kMillimeter) {
    result = static_cast<int64_t>(input_value * 1.0e+6);
  } else if (input_type == zozibush::geometry::Distance::Type::kMicrometer) {
    result = static_cast<int64_t>(input_value * 1.0e+3);
  }
  return result;
}
}  // namespace

namespace zozibush::geometry {
Distance::Distance(double input_value, Type input_type)
    : nanometer_(ScaleDistanceToNanometer(input_value, input_type)) {}
}  // namespace zozibush::geometry