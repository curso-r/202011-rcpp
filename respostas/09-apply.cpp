#include <Rcpp.h>
using namespace Rcpp;

// Crie uma função que aplique uma função arbitrária 
// para cada linha de uma matriz.
// Essa função será parecida com que a função `apply` do R
// Faça com que essa função seja *interrompível* caso esteja
// demorando muito.

/*** R
x <- matrix(runif(1e6), ncol = 10)
res <- apply(x, 1, mean)
*/

// [[Rcpp::export]]
NumericVector cpp_apply (NumericMatrix x, Function f)
{
  NumericVector out(x.nrow());
  for (int i = 0; i < x.nrow(); i++)
  {
    out[i] = Rcpp::as<double>(f(x(i,_)));
  }
  return out;
}

/*** R
x <- matrix(runif(100), ncol = 10)
cpp_apply(x, max)
*/