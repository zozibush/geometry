// Copyright (c) 2023 zozibush, All Rights Reserved.
// Authors: zozibush

#include <cstdint>

#include "gtest/gtest.h"

auto main(int32_t argc, char **argv) -> int32_t {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}