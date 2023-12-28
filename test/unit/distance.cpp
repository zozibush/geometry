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
TEST(GeometryDistance, GetValue) {
  const double kInputValue = static_cast<double>(2023.0);
  Distance distance1(kInputValue, Distance::Type::kKilometer);
  EXPECT_DOUBLE_EQ(kInputValue, distance1.GetValue(Distance::Type::kKilometer));

  Distance distance2(kInputValue, Distance::Type::kMeter);
  EXPECT_DOUBLE_EQ(kInputValue, distance2.GetValue(Distance::Type::kMeter));

  Distance distance3(kInputValue, Distance::Type::kCentimeter);
  EXPECT_DOUBLE_EQ(kInputValue,
                   distance3.GetValue(Distance::Type::kCentimeter));

  Distance distance4(kInputValue, Distance::Type::kMillimeter);
  EXPECT_DOUBLE_EQ(kInputValue,
                   distance4.GetValue(Distance::Type::kMillimeter));

  Distance distance5(kInputValue, Distance::Type::kMicrometer);
  EXPECT_DOUBLE_EQ(kInputValue,
                   distance5.GetValue(Distance::Type::kMicrometer));

  Distance distance6(kInputValue, Distance::Type::kNanometer);
  EXPECT_DOUBLE_EQ(kInputValue, distance6.GetValue(Distance::Type::kNanometer));
}
}  // namespace zozibush::geometry
