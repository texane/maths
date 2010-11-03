#include <cstdio>
#include <cmath>

static inline double dtor(double d)
{
  return ((2.f * M_PI) / 360.f) * d;
}

static inline double rtod(double r)
{
  return (360.f / (2.f * M_PI)) * r;
}

static inline double polar_to_cartesian
(double r, double rho, double& x, double &y)
{
  x = ::cos(rho) * r;
  y = ::sin(rho) * r;
}

int main(int ac, char** av)
{
  static const double step = dtor(0.01f);
  static const double a = 100.f;
  static const double aa = a * a;

  // cos(2x) > 0.f <=> 135.f < x < 225.f
  for (double rho = dtor(135.f) + step; rho < dtor(225.f); rho += step)
  {
    const double cos2rho = ::cos(2.f * rho);

    const double r = ::sqrt(aa * cos2rho);
    double x, y;

    polar_to_cartesian(r, rho, x, y);
    ::printf("%lf %lf\n", x, y);

    // polar_to_cartesian(-r, rho, x, y);
    ::printf("%lf %lf\n", -x, -y);
  }

  return 0;
}
