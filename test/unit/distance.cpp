// Copyright (c) 2023 zozibush, All Rights Reserved.
// Authors: zozibush
#include "geometry/distance.hpp"

#include "gtest/gtest.h"

namespace zozibush::geometry {
TEST(GeometryDistance, Constructor) {
  Distance distance1;
  Distance distance2(distance1);
  Distance distance3(std::move(Distance()));
}
TEST(GeometryDistance, Assignment) {
  Distance distance1;
  auto distance2 = distance1;
  auto distance3 = std::move(Distance());
}
}  // namespace zozibush::geometry
