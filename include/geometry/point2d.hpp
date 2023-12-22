/**
 * @file geometry/point2d.hpp
 * @author zozibush (zozibush88@gmail.com)
 * @brief Point class declaration with 2-dimesion
 * @version 1.0.0
 * @date 2023-12-20
 * @copyright Copyright (c) 2023 zozibush, All Rights Reserved.
 */

// Copyright (c) 2023 zozibush, All RIghts Reserved
// Authors: zozibush

#ifndef ZOZIBUSH__GEOMETRY_POINT_2D_HPP_
#define ZOZIBUSH__GEOMETRY_POINT_2D_HPP_

namespace programmers::geometry {

/**
 * @brief Point class with 2-dimension
 */
class Point2D {
 public:
  /**
   * @brief Construct a new Point2D object
   */
  Point2D() = default;
  /**
   * @brief Construct a new Point2D object with x, y, value
   * @param x Double type x coordinate value
   * @param y Double type y coordinate value
   */
  Point2D(double x, double y);

  /**
   * @brief Copy construct a new Point2D object with other Point2D object
   * @param other Point2D object
   */
  Point2D(const Point2D& other) = default;
  /**
   * @brief Move construct a new Point2D object with other Point2D object
   * @param other Point2D object
   */
  Point2D(Point2D&& other) noexcept = default;

  /**
   * @brief Destroy the Point2D object
   */
  virtual ~Point2D() = default;

  /**
   * @brief Copy assignment operator
   * @param other Point2D object
   * @return Point2D& Reference of Point2D object
   */
  auto operator=(const Point2D& other) -> Point2D& = default;
  /**
   * @brief Move assignment operator
   * @param other Point2D object
   * @return Point2D& Reference of Point2D object
   */
  auto operator=(Point2D&& other) -> Point2D& = default;

  /**
   * @brief Calculate distance between this point and target point
   * @param target Other Point2D object
   * @return double Euclidean Distance between this point and target point
   */
  auto CalculateDistance(const Point2D& target) const -> double;

  /**
   * @brief Calculate distance between lhs point and rhs point
   * @param lts left hand size Point2D object
   * @param rts right hand size Point2D object
   * @return double Euclidean Distance between lts point and lts point
   */
  [[nodiscard]] static auto CalculateDistance(const Point2D& lts,
                                              const Point2D& rts) -> double;
  /**
   * @brief Set x coordinate value
   * @param x Double type input x coordinate value
   */
  void SetX(double x);
  /**
   * @brief Set y coordinate value
   * @param y Double type input y coordinate value
   */
  void SetY(double y);

  /**
   * @brief Get x coordinate value of this point
   * @return double x coordinate value of this point
   */
  [[nodiscard]] auto GetX() const -> double;
  /**
   * @brief Get y coordinate value of this point
   * @return double y coordinate value of this point
   */
  [[nodiscard]] auto GetY() const -> double;

  /**
   * @brief Add assignment operator
   * @param other Piont2D object
   * @return Point2D Calculated Point2D object
   */
  auto operator+(const Point2D& other) const -> Point2D;
  /**
   * @brief Subtract assignment operator
   * @param other Piont2D object
   * @return Point2D Calculated Point2D object
   */
  auto operator-(const Point2D& other) const -> Point2D;

  /**
   * @brief Add and accumulate assigment operator
   * @param other Reference of Point2D object
   * @return Point2D& Reference of Point2D object
   */
  auto operator+=(const Point2D& other) -> Point2D&;
  /**
   * @brief Subtract and accumulate assigment operator
   * @param other Reference of Point2D object
   * @return Point2D& Reference of Point2D object
   */
  auto operator-=(const Point2D& other) -> Point2D&;

  /**
   * @brief Multiply assigment operator
   * @param scalar int
   * @return Point2D Calculated Point2D object
   */
  auto operator*(double scalar) const -> Point2D;
  /**
   * @brief Devide assigment operator
   * @param scalar Int value
   * @return Calculated Point2D object
   * @throw If scalar==0, don't divide
   */
  auto operator/(double scalar) const -> Point2D;

  /**
   * @brief Same Compare assigment operator
   * @param other Reference of Point2D object
   * @return true Same this point and other point
   * @return false Different this point and other point
   */
  auto operator==(const Point2D& other) const -> bool;
  /**
   * @brief Different Compare assigment operator
   * @param other Reference of Point2D object
   * @return true Different this point and other point
   * @return false Same this point and other point
   */
  auto operator!=(const Point2D& other) const -> bool;

 protected:
 private:
  double x_{0.00};  ///< x coordinate
  double y_{0.00};  ///< y coordinate
};

}  // namespace programmers::geometry

#endif
