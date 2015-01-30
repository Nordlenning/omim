#include "../../base/SRC_FIRST.hpp"
#include "../../testing/testing.hpp"
#include "equality.hpp"
#include "../point2d.hpp"

UNIT_TEST(Point_Rotate)
{
  m2::PointD p(1.0, 0.0);
  p.Rotate(math::pi / 6.0);
  TEST(test::is_equal(p.x, sqrt(3.0) / 2.0), ());
  TEST(test::is_equal(p.y, 1.0 / 2.0), ());
}

UNIT_TEST(PointInTriangle)
{
  m2::PointD const a(1, 0);
  m2::PointD const b(2, 0);
  m2::PointD const c(-1, 3);

  TEST(!m2::IsPointStrictlyInsideTriangle(a, a, a, a), ());

  TEST(!m2::IsPointStrictlyInsideTriangle(a, a, a, b), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(b, a, a, b), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(a, a, b, a), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(b, a, b, a), ());

  TEST(!m2::IsPointStrictlyInsideTriangle(a, a, b, c), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(a, a, c, b), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(b, a, b, c), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(b, a, c, b), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(c, a, b, c), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(c, a, c, b), ());

  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(0, 1), a, b, c), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(0, 1), a, c, b), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(0, 1.5), a, b, c), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(0, 1.5), a, c, b), ());
  TEST(m2::IsPointStrictlyInsideTriangle(m2::PointD(0, 1.77), a, b, c), ());
  TEST(m2::IsPointStrictlyInsideTriangle(m2::PointD(0, 1.77), a, c, b), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(0, 2), a, b, c), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(0, 2), a, c, b), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(1, 1), a, b, c), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(1, 1), a, c, b), ());
  TEST(m2::IsPointStrictlyInsideTriangle(m2::PointD(1, 0.5), a, b, c), ());
  TEST(m2::IsPointStrictlyInsideTriangle(m2::PointD(1, 0.5), a, c, b), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(100, 100), a, b, c), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(100, 100), a, c, b), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(5, 0), a, b, c), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(5, 0), a, c, b), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(-1, -1), a, c, b), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(0, 0.5), a, b, c), ());
  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(0, 0.5), a, c, b), ());
}

UNIT_TEST(PointInTriangle_EmptyTriangle)
{
  m2::PointD pt(27, 31);
  TEST(!m2::IsPointStrictlyInsideTriangle(m2::PointD(0, 16), pt, pt, pt), ());
}

/// @todo add more tests
UNIT_TEST(GetArrowPoints)
{
  array<m2::PointF, 3> arrPntsFlt;
  m2::GetArrowPoints(m2::PointF(0, 0), m2::PointF(1, 0), 1.f, 1.f, arrPntsFlt);
  TEST(m2::AlmostEqual(arrPntsFlt[0], m2::PointF(1.f, 1.f)), ());
  TEST(m2::AlmostEqual(arrPntsFlt[1], m2::PointF(2.f, 0.f)), ());
  TEST(m2::AlmostEqual(arrPntsFlt[2], m2::PointF(1.f, -1.f)), ());

  array<m2::PointD, 3> arrPntsDbl;
  m2::GetArrowPoints(m2::PointD(-1., 2.), m2::PointD(-1., 100.), 2., 5., arrPntsDbl);
  TEST(m2::AlmostEqual(arrPntsDbl[0], m2::PointD(-3.f, 100.f)), ());
  TEST(m2::AlmostEqual(arrPntsDbl[1], m2::PointD(-1.f, 105.f)), ());
  TEST(m2::AlmostEqual(arrPntsDbl[2], m2::PointD(1.f, 100.f)), ());
}

UNIT_TEST(PointAtSegment)
{
  TEST(m2::AlmostEqual(m2::PointAtSegment(m2::PointF(0, 0), m2::PointF(1, 0), 0.5f), m2::PointF(0.5f, 0.f)), ());
  TEST(m2::AlmostEqual(m2::PointAtSegment(m2::PointF(0, 0), m2::PointF(0, 1), 0.3f), m2::PointF(0.f, 0.3f)), ());
  TEST(m2::AlmostEqual(m2::PointAtSegment(m2::PointD(0., 0.), m2::PointD(30., 40.), 5.), m2::PointD(3., 4.)), ());
  TEST(m2::AlmostEqual(m2::PointAtSegment(m2::PointF(-3, -4), m2::PointF(-30, -40), 5.f), m2::PointF(-6.f, -8.f)), ());
  TEST(m2::AlmostEqual(m2::PointAtSegment(m2::PointD(14., -48.), m2::PointD(70., -240.), 25.), m2::PointD(21., -72.)), ());
}
