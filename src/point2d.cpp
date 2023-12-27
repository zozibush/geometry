// Copyright (c) 2023 zozibush, All RIghts Reserved
// Authors: zozibush

#include "geometry/point2d.hpp"

#include <cmath>

namespace zozibush::geometry {
Point2D::Point2D(double input_x, double input_y) : x_(input_x), y_(input_y) {}

auto Point2D::CalculateDistance(const Point2D& target) const -> double {
  return Point2D::CalculateDistance(*this, target);
}

auto Point2D::CalculateDistance(const Point2D& lhs,
                                const Point2D& rhs) -> double {
  return std::sqrt(std::pow((lhs.x_ - rhs.x_), 2) +
                   std::pow((lhs.y_ - rhs.y_), 2));
}

auto Point2D::GetX() const -> double { return x_; }
auto Point2D::GetY() const -> double { return y_; }

auto Point2D::SetX(double input_x) -> void { x_ = input_x; }
auto Point2D::SetY(double input_y) -> void { y_ = input_y; }

auto Point2D::operator+(const Point2D& rhs) const -> Point2D{
  auto kX=this->GetX()+rhs.GetX();
  auto kY=this->GetY()+rhs.GetY();
  return Point2D(kX,kY);
}
auto Point2D::operator-(const Point2D& rhs) const -> Point2D{
  auto kX=this->GetX()-rhs.GetX();
  auto kY=this->GetY()-rhs.GetY();
  return Point2D(kX,kY);
}

}  // namespace zozibush::geometry