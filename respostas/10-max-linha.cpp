#include <Rcpp.h>
using namespace Rcpp;

// Crie uma função que receba uma matriz e retorne o índice do elemento com
// maior valor em cada linha.


double max_index (NumericVector x)
{
  NumericVector::iterator it = std::max_element(x.begin(),x.end());
  return std::distance(x.begin(), it);
}

// [[Rcpp::export]]
IntegerVector cpp_max_por_linha (NumericMatrix x)
{
  IntegerVector out(x.nrow());
  for (int i = 0; i < x.nrow(); i++)
  {
    out[i] = max_index(x(i,_));
  }
  return out;
}

/*** R
x <- matrix(runif(1000), ncol = 10)
cpp_max_por_linha(x)
*/