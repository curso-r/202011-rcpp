#include <Rcpp.h>
using namespace Rcpp;

// Crie uma uma função que calcule a soma cumulativa. Equivalente a função 
// `cumsum` do R.

/*** R
cumsum(1:10)
*/

// [[Rcpp::export]]
NumericVector cpp_cumsum (NumericVector x)
{
  NumericVector out (x.size());
  for (int i = 0; i < x.size(); i++)
  {
    if (i > 0)
      out[i] = out[i-1] + x[i];
    else
      out[i] = x[i];
  }
  return out;
}

/*** R
cpp_cumsum(1:10)
*/