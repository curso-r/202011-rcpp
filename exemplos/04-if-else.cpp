#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector cpp_abs(NumericVector x) {
  NumericVector out(x.size());
  for (int i = 0; i < x.size(); i++)
  {
    if (x[i] > 0)
      out[i] = x[i];
    else
      out[i] = -x[i];
  }
  return out;
}

/*** R
cpp_abs(c(-1, -2, 1, 2))
*/
