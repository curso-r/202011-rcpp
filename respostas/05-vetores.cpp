#include <Rcpp.h>
using namespace Rcpp;

// Crie uma uma função em Rcpp que seja equivalente à função abaixo.

/*** R
transformar <- function(v) {
  
  v2 <- v
  v2 <- append(v2, 1)
  v2 <- append(-1, v2)
  v2[3] <- 0
  v2 <- sort(v2)
  
  list(
    "length" = length(v),
    "names"  = names(v),
    "resto"  = v2
  )
}
*/

// [[Rcpp::export]]
Rcpp::List cpp_transformar (NumericVector v)
{
  NumericVector v2 = v;
  v2.push_back(1);
  v2.push_front(-1);
  v2[2] = 0;
  v2.sort();
  return List::create(
    _["length"] = v.size(),
    _["names"] = v.names(),
    _["resto"] = v2
  );
}

/*** R
cpp_transformar(c(1,2,3))
*/

// Crie uma uma função em Rcpp que seja equivalente à função abaixo.

/*** R
selecionar <- function(v, s) {
  v[s]
}
*/

// [[Rcpp::export]]
double cpp_selecionar (NumericVector v, int s)
{
  return v[s-1];
}

/*** R
cpp_selecionar(1:10, 5)
*/

// Crie uma função equivalente à função `rep` do R

/*** R
rep(c(1,2,3), 3)
*/

// [[Rcpp::export]]
NumericVector cpp_rep (NumericVector v, int n)
{
  NumericVector out (v.size() * n);
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j < n; j++)
    {
     out[i + j*n] = v[i];
    }
  }
  return out;
}

/*** R
cpp_rep(c(1,2,3), 3)
*/