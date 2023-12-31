// Copyright (c) 2023 zozibush, All Rights Reserved.
// Authors: zozibush
#include "geometry/distance.hpp"

#include <cmath>

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
TEST(GeometryDistance, SetValue) {
  const double kInputValue = static_cast<double>(2023.0);
  Distance distance1;
  distance1.SetValue(kInputValue, Distance::Type::kKilometer);
  EXPECT_DOUBLE_EQ(kInputValue, distance1.GetValue(Distance::Type::kKilometer));

  Distance distance2;
  distance2.SetValue(kInputValue, Distance::Type::kMeter);
  EXPECT_DOUBLE_EQ(kInputValue, distance2.GetValue(Distance::Type::kMeter));

  Distance distance3;
  distance3.SetValue(kInputValue, Distance::Type::kCentimeter);
  EXPECT_DOUBLE_EQ(kInputValue,
                   distance3.GetValue(Distance::Type::kCentimeter));

  Distance distance4;
  distance4.SetValue(kInputValue, Distance::Type::kMillimeter);
  EXPECT_DOUBLE_EQ(kInputValue,
                   distance4.GetValue(Distance::Type::kMillimeter));

  Distance distance5;
  distance5.SetValue(kInputValue, Distance::Type::kMicrometer);
  EXPECT_DOUBLE_EQ(kInputValue,
                   distance5.GetValue(Distance::Type::kMicrometer));

  Distance distance6;
  distance6.SetValue(kInputValue, Distance::Type::kNanometer);
  EXPECT_DOUBLE_EQ(kInputValue, distance6.GetValue(Distance::Type::kNanometer));
}
TEST(GeometryDistance, OperatorEqual) {
  const double kInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  EXPECT_TRUE(distance_by_kilo == distance);
  EXPECT_TRUE(distance_by_kilo == distance_by_nano);
  EXPECT_TRUE(distance == distance_by_nano);
}
TEST(GeometryDistance, OperatorNotEqual) {
  const double kInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  EXPECT_FALSE(distance_by_kilo != distance);
  EXPECT_FALSE(distance_by_kilo != distance_by_nano);
  EXPECT_FALSE(distance != distance_by_nano);
}
TEST(GeometryDistance, OperatorSmaller) {
  const double kInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  const double kBigInputValue = static_cast<double>(9999.0);
  Distance distance_big_by_kilo(kBigInputValue, Distance::Type::kKilometer);
  Distance distance_big(kBigInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_big_by_nano(kBigInputValue * 1.0e+12,
                                Distance::Type::kNanometer);

  EXPECT_TRUE(distance_by_kilo < distance_big_by_kilo);
  EXPECT_TRUE(distance < distance_big);
  EXPECT_TRUE(distance_by_nano < distance_big_by_nano);

  EXPECT_FALSE(distance_by_kilo < distance);
  EXPECT_FALSE(distance_by_kilo < distance_by_nano);
  EXPECT_FALSE(distance < distance_by_nano);
}
TEST(GeometryDistance, OperatorSmallerEqual) {
  const double kInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  const double kBigInputValue = static_cast<double>(9999.0);
  Distance distance_big_by_kilo(kBigInputValue, Distance::Type::kKilometer);
  Distance distance_big(kBigInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_big_by_nano(kBigInputValue * 1.0e+12,
                                Distance::Type::kNanometer);

  EXPECT_TRUE(distance_by_kilo <= distance_big_by_kilo);
  EXPECT_TRUE(distance <= distance_big);
  EXPECT_TRUE(distance_by_nano <= distance_big_by_nano);

  EXPECT_TRUE(distance_by_kilo <= distance);
  EXPECT_TRUE(distance_by_kilo <= distance_by_nano);
  EXPECT_TRUE(distance <= distance_by_nano);
}
TEST(GeometryDistance, OperatorBigger) {
  const double kInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  const double kSmallInputValue = static_cast<double>(100.0);
  Distance distance_small_by_kilo(kSmallInputValue, Distance::Type::kKilometer);
  Distance distance_small(kSmallInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_small_by_nano(kSmallInputValue * 1.0e+12,
                                  Distance::Type::kNanometer);

  EXPECT_TRUE(distance_by_kilo > distance_small_by_kilo);
  EXPECT_TRUE(distance > distance_small);
  EXPECT_TRUE(distance_by_nano > distance_small_by_nano);

  EXPECT_FALSE(distance_by_kilo > distance);
  EXPECT_FALSE(distance_by_kilo > distance_by_nano);
  EXPECT_FALSE(distance > distance_by_nano);
}
TEST(GeometryDistance, OperatorBiggerEqual) {
  const double kInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  const double kSmallInputValue = static_cast<double>(100.0);
  Distance distance_small_by_kilo(kSmallInputValue, Distance::Type::kKilometer);
  Distance distance_small(kSmallInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_small_by_nano(kSmallInputValue * 1.0e+12,
                                  Distance::Type::kNanometer);

  EXPECT_TRUE(distance_by_kilo >= distance_small_by_kilo);
  EXPECT_TRUE(distance >= distance_small);
  EXPECT_TRUE(distance_by_nano >= distance_small_by_nano);

  EXPECT_TRUE(distance_by_kilo >= distance);
  EXPECT_TRUE(distance_by_kilo >= distance_by_nano);
  EXPECT_TRUE(distance >= distance_by_nano);
}
TEST(GeometryDistance, OperatorAdd) {
  const double kInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  const auto distance1 = distance_by_kilo + distance;
  const auto distance2 = distance_by_kilo + distance_by_nano;
  const auto distance3 = distance + distance_by_nano;

  EXPECT_DOUBLE_EQ(distance1.GetValue(Distance::Type::kKilometer),
                   kInputValue * 2.0);
  EXPECT_DOUBLE_EQ(distance2.GetValue(Distance::Type::kKilometer),
                   kInputValue * 2.0);
  EXPECT_DOUBLE_EQ(distance3.GetValue(Distance::Type::kKilometer),
                   kInputValue * 2.0);
}
TEST(GeometryDistance, OperatorSubtract) {
  const double kInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  const auto distance1 = distance_by_kilo - distance;
  const auto distance2 = distance_by_kilo - distance_by_nano;
  const auto distance3 = distance - distance_by_nano;

  EXPECT_DOUBLE_EQ(distance1.GetValue(Distance::Type::kKilometer), 0.0);
  EXPECT_DOUBLE_EQ(distance2.GetValue(Distance::Type::kKilometer), 0.0);
  EXPECT_DOUBLE_EQ(distance3.GetValue(Distance::Type::kKilometer), 0.0);
}
TEST(GeometryDistance, OperatorMultiply) {
  const double kInputValue = static_cast<double>(2038.0);
  const double kScaleValue = static_cast<double>(2.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  const auto distance1 = distance_by_kilo * kScaleValue;
  const auto distance2 = distance * kScaleValue;
  const auto distance3 = distance_by_nano * kScaleValue;

  EXPECT_DOUBLE_EQ(distance1.GetValue(Distance::Type::kKilometer),
                   kInputValue * kScaleValue);
  EXPECT_DOUBLE_EQ(distance2.GetValue(Distance::Type::kKilometer),
                   kInputValue * kScaleValue);
  EXPECT_DOUBLE_EQ(distance3.GetValue(Distance::Type::kKilometer),
                   kInputValue * kScaleValue);
}
TEST(GeometryDistance, OperatorDivision) {
  const double kInputValue = static_cast<double>(2038.0);
  const double kScaleValue = static_cast<double>(2.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  const auto distance1 = distance_by_kilo / kScaleValue;
  const auto distance2 = distance / kScaleValue;
  const auto distance3 = distance_by_nano / kScaleValue;

  EXPECT_DOUBLE_EQ(distance1.GetValue(Distance::Type::kKilometer),
                   kInputValue / kScaleValue);
  EXPECT_DOUBLE_EQ(distance2.GetValue(Distance::Type::kKilometer),
                   kInputValue / kScaleValue);
  EXPECT_DOUBLE_EQ(distance3.GetValue(Distance::Type::kKilometer),
                   kInputValue / kScaleValue);

  EXPECT_THROW(distance / std::nan(""), std::invalid_argument);
  EXPECT_THROW(distance / std::numeric_limits<double>::infinity(),
               std::invalid_argument);
  EXPECT_THROW(distance / 0.0, std::invalid_argument);
  EXPECT_NO_THROW(distance / kScaleValue);
}
TEST(GeometryDistance, OperatorAddAccumulate) {
  const double kInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  distance += distance_by_kilo;
  EXPECT_DOUBLE_EQ(distance.GetValue(Distance::Type::kKilometer),
                   kInputValue * 2.0);
  distance += distance_by_nano;
  EXPECT_DOUBLE_EQ(distance.GetValue(Distance::Type::kKilometer),
                   kInputValue * 3.0);
}
TEST(GeometryDistance, OperatorSubtractAccumulate) {
  const double kInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  distance -= distance_by_kilo;
  EXPECT_DOUBLE_EQ(distance.GetValue(Distance::Type::kKilometer), 0.0);
  distance -= distance_by_nano;
  EXPECT_DOUBLE_EQ(distance.GetValue(Distance::Type::kKilometer),
                   kInputValue * -1.0);
}
TEST(GeometryDistance, OperatorMultiplyAccumulate) {
  const double kInputValue = static_cast<double>(2038.0);
  const double kScaleValue = static_cast<double>(2.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  distance_by_kilo *= kScaleValue;
  EXPECT_DOUBLE_EQ(distance_by_kilo.GetValue(Distance::Type::kKilometer),
                   kInputValue * kScaleValue);
  distance *= kScaleValue;
  EXPECT_DOUBLE_EQ(distance.GetValue(Distance::Type::kKilometer),
                   kInputValue * kScaleValue);
  distance_by_nano *= kScaleValue;
  EXPECT_DOUBLE_EQ(distance_by_nano.GetValue(Distance::Type::kKilometer),
                   kInputValue * kScaleValue);
}
TEST(GeometryDistance, OperatorDivideAccumulate) {
  const double kInputValue = static_cast<double>(2038.0);
  const double kScaleValue = static_cast<double>(2.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  distance_by_kilo /= kScaleValue;
  EXPECT_DOUBLE_EQ(distance_by_kilo.GetValue(Distance::Type::kKilometer),
                   kInputValue / kScaleValue);
  distance /= kScaleValue;
  EXPECT_DOUBLE_EQ(distance.GetValue(Distance::Type::kKilometer),
                   kInputValue / kScaleValue);
  distance_by_nano /= kScaleValue;
  EXPECT_DOUBLE_EQ(distance_by_nano.GetValue(Distance::Type::kKilometer),
                   kInputValue / kScaleValue);

  EXPECT_THROW(distance /= std::nan(""), std::invalid_argument);
  EXPECT_THROW(distance /= std::numeric_limits<double>::infinity(),
               std::invalid_argument);
  EXPECT_THROW(distance /= 0.0, std::invalid_argument);
  EXPECT_NO_THROW(distance /= kScaleValue);
}
}  // namespace zozibush::geometry
