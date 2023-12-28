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
}  // namespace zozibush::geometry
