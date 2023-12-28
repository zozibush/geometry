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

#include <cstdint>

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

  /**
   * @brief Construct a new Distance object.
   */
  Distance() = default;
  /**
   * @brief Construct with value
   * @param input_value The double type value
   * @param input_type The unit of distance
   */
  explicit Distance(double input_value, Type input_type = Type::kMeter);

  /**
   * @brief The copy constructor.
   * @param other The other  distance object.
   */
  Distance(const Distance& other) = default;
  /**
   * @brief The move constructor.
   * @param other The other distance object.
   */
  Distance(Distance&& other) noexcept = default;

  /**
   * @brief Destroy the Distance object.
   */
  virtual ~Distance() = default;

  /**
   * @brief The copy assignment operator.
   * @param other The other distance object.
   * @return The reference of distance object.
   */
  auto operator=(const Distance& other) -> Distance& = default;
  /**
   * @brief The move assignment operator.
   * @param other The other distance object.
   * @return The reference of distance object.
   */
  auto operator=(Distance&& other) -> Distance& = default;

  /**
   * @brief Get the distance value for distance type.
   * @param input_type The unit of distance scaling.
   * @return double The scaled distance.
   */
  [[nodiscard]] auto GetValue(const Type& input_type) const -> double;

  /**
   * @brief Set the distance value for distance type.
   * @param input_value The distance value
   * @param input_type The unit of distance scaling
   */
  auto SetValue(double input_value, const Type& input_type) -> void;

  /**
   * @brief Compare with other distance object for equality.
   * @param other The other distance object.
   * @return true If equal.
   * @return false If not equal.
   */
  auto operator==(const Distance& other) const -> bool;
  /**
   * @brief Compare not with other distance object for equality.
   * @param other The other distance object.
   * @return true If not equal.
   * @return false If equal
   */
  auto operator!=(const Distance& other) const -> bool;

  /**
   * @brief Compare with other distance object for scale.
   * @param other The other distance object.
   * @return true If this distance object is small.
   * @return false If other distance object is big.
   */
  auto operator<(const Distance& other) const -> bool;
  /**
   * @brief Compare with other distance object for scale and equality
   * @param other The other distance object.
   * @return true If this distance object is small or same.
   * @return false If other distance object is big.
   */
  auto operator<=(const Distance& other) const -> bool;

 protected:
 private:
  int64_t nanometer_{0};  ///< Nanometer
};

}  // namespace zozibush::geometry

#endif  // ZOZIBUSH__GEOMETRY_DISTANCE_HPP_