/**
 * @file geometry/distance.hpp
 * @author zozibush (zozibush88@gmail.com)
 * @brief Distance class declaration
 * @version 1.0.0
 * @date 2023-12-20
 * @copyright Copyright (c) 2023 zozibush, All Rights Reserved.
 */

// Copyright (c) 2023 zozibush, All RIghts Reserved
// Authors: zozibush

#ifndef ZOZIBUSH__GEOMETRY_DISTANCE_HPP_
#define ZOZIBUSH__GEOMETRY_DISTANCE_HPP_

namespace zozibush::geometry {
/**
 * @brief Distance class
 */
class Distance {
 public:
  /**
   * @brief The enum class for distance type.
   */
  enum class Type {
    kKilometer = 0,   ///< Kilometer
    kMeter = 1,       ///< Meter
    kCentimeter = 2,  ///< Centimeter
    kMillimeter = 3,  ///< Millimeter
    kMicrometer = 4,  ///< Micrometer
    kNanometer = 5,   ///< Nanometer
  };

 protected:
 private:
};

}  // namespace zozibush::geometry

#endif  // ZOZIBUSH__GEOMETRY_DISTANCE_HPP_