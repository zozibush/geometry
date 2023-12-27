// Copyright (c) 2023 zozibush, All Rights Reserved.
// Authors: zozibush
#include "geometry/point2d.hpp"

#include <cmath>
#include <cstdint>
#include <stdexcept>

#include "gtest/gtest.h"

namespace {
constexpr uint32_t kTestCount = 1000U;
}

namespace zozibush::geometry {
TEST(GeometryPoint2D, Constructor) {
  Point2D point1;
  Point2D point2(0.0, 1.0);
  Point2D point3(point2);
  Point2D point4(std::move(Point2D()));
};
TEST(GeometryPoint2D, Assignment) {
  Point2D point1;
  auto point2 = point1;
  auto point3 = std::move(Point2D());
}
TEST(GeometryPoint2D, CalculateDistance) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const double kSourceX = static_cast<double>(std::rand());
    const double kSourceY = static_cast<double>(std::rand());
    const double kTargetX = static_cast<double>(std::rand());
    const double kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    EXPECT_FLOAT_EQ(std::sqrt((kSourceX - kTargetX) * (kSourceX - kTargetX) +
                              (kSourceY - kTargetY) * (kSourceY - kTargetY)),
                    source.CalculateDistance(target));
  }
}
TEST(GeometryPoint2D, StaticCalculateDistance) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    EXPECT_FLOAT_EQ(std::sqrt((kSourceX - kTargetX) * (kSourceX - kTargetX) +
                              (kSourceY - kTargetY) * (kSourceY - kTargetY)),
                    Point2D::CalculateDistance(source, target));
  }
}
TEST(GeometryPoint2D, GetX) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());

    Point2D source(kSourceX, 0.0);

    EXPECT_FLOAT_EQ(kSourceX, source.GetX());
  }
}
TEST(GeometryPoint2D, GetY) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceY = static_cast<double>(std::rand());

    Point2D source(0.0, kSourceY);

    EXPECT_FLOAT_EQ(kSourceY, source.GetY());
  }
}
TEST(GeometryPoint2D, SetX) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());

    Point2D source(0.0, 0.0);

    source.SetX(kSourceX);

    EXPECT_FLOAT_EQ(kSourceX, source.GetX());
  }
}
TEST(GeometryPoint2D, SetY) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceY = static_cast<double>(std::rand());

    Point2D source(0.0, 0.0);

    source.SetY(kSourceY);

    EXPECT_FLOAT_EQ(kSourceY, source.GetY());
  }
}
TEST(GeometryPoint2D, OperatorAdd) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    auto result = source + target;

    EXPECT_FLOAT_EQ(kSourceX + kTargetX, result.GetX());
    EXPECT_FLOAT_EQ(kSourceY + kTargetY, result.GetY());
  }
}
TEST(GeometryPoint2D, OperatorSubtract) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    auto result = source - target;

    EXPECT_FLOAT_EQ(kSourceX - kTargetX, result.GetX());
    EXPECT_FLOAT_EQ(kSourceY - kTargetY, result.GetY());
  }
}
TEST(GeometryPoint2D, OperatorAddAccumulate) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    source += target;

    EXPECT_FLOAT_EQ(kSourceX + kTargetX, source.GetX());
    EXPECT_FLOAT_EQ(kSourceY + kTargetY, source.GetY());
  }
}
TEST(GeometryPoint2D, OperatorSubtractAccumulate) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    source -= target;

    EXPECT_FLOAT_EQ(kSourceX - kTargetX, source.GetX());
    EXPECT_FLOAT_EQ(kSourceY - kTargetY, source.GetY());
  }
}
TEST(GeometryPoint2D, OperatorMultiply) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kScaleValue = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);

    auto result = source * kScaleValue;

    EXPECT_FLOAT_EQ(kSourceX * kScaleValue, result.GetX());
    EXPECT_FLOAT_EQ(kSourceY * kScaleValue, result.GetY());
  }
}
TEST(GeometryPoint2D, OperatorDivide) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kScaleValue = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);

    auto result = source / kScaleValue;

    EXPECT_FLOAT_EQ(kSourceX / kScaleValue, result.GetX());
    EXPECT_FLOAT_EQ(kSourceY / kScaleValue, result.GetY());
  }

  {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    Point2D source(kSourceX, kSourceY);

    auto kScaleValue = std::nan("");
    EXPECT_THROW(source / kScaleValue, std::invalid_argument);

    kScaleValue = std::numeric_limits<double>::infinity();
    EXPECT_THROW(source / kScaleValue, std::invalid_argument);

    kScaleValue = 0.0;
    EXPECT_THROW(source / kScaleValue, std::invalid_argument);

    kScaleValue = static_cast<double>(std::rand());
    EXPECT_NO_THROW(source / kScaleValue);
  }
}
TEST(GeometryPoint2D, OperatorEqual) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = kSourceY + 1.0;

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    EXPECT_TRUE(source == Point2D(kSourceX, kSourceY));
    EXPECT_FALSE(source == target);
  }
}
TEST(GeometryPoint2D, OperatorDiffer) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = kSourceY + 1.0;

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    EXPECT_FALSE(source != Point2D(kSourceX, kSourceY));
    EXPECT_TRUE(source != target);
  }
}
}  // namespace zozibush::geometry
