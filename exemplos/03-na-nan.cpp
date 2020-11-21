#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
LogicalVector cpp_is_na (NumericVector x)
{
  LogicalVector out(x.size());
  for(int i = 0; i < x.size(); i ++)
  {
    out[i] = NumericVector::is_na(x[i]);
  }
  return out;
}

// [[Rcpp::export]]
LogicalVector cpp_is_nan (NumericVector x)
{
  LogicalVector out(x.size());
  for(int i = 0; i < x.size(); i ++)
  {
    out[i] = R_IsNaN(x[i]);
  }
  return out;
}

// [[Rcpp::export]]
NumericVector cpp_retorna_na ()
{
  NumericVector ret(1);
  ret[0] = NA_REAL; // usamos NA_REAL pq é vetor numerico!
  return ret;
}

/*** R
x <- c(1, NA, NaN, 2)
cpp_is_na(x)
is.na(x)

cpp_is_nan(x)
is.nan(x)

cpp_retorna_na()
*/
