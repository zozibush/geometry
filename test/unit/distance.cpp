// Copyright (c) 2023 zozibush, All Rights Reserved.
// Authors: zozibush
#include "geometry/distance.hpp"

#include "gtest/gtest.h"

namespace {
constexpr uint32_t kTestCount = 1000U;
}

namespace zozibush::geometry {
TEST(GeometryDistance, Constructor) {
  Distance distance1;
  Distance distance2(distance1);
  Distance distance3(std::move(Distance()));
}
TEST(GeometryDistance, ConstructorWithInputValue) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    Distance distance1(static_cast<double>(std::rand()));
    Distance distance2(static_cast<double>(std::rand()),
                       Distance::Type::kKilometer);
    Distance distance3(static_cast<double>(std::rand()),
                       Distance::Type::kMeter);
    Distance distance4(static_cast<double>(std::rand()),
                       Distance::Type::kCentimeter);
    Distance distance5(static_cast<double>(std::rand()),
                       Distance::Type::kMillimeter);
    Distance distance6(static_cast<double>(std::rand()),
                       Distance::Type::kMicrometer);
    Distance distance7(static_cast<double>(std::rand()),
                       Distance::Type::kNanometer);
  }
}
TEST(GeometryDistance, Assignment) {
  Distance distance1;
  auto distance2 = distance1;
  auto distance3 = std::move(Distance());
}
}  // namespace zozibush::geometry
