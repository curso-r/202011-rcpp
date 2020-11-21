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

// Crie uma uma função em Rcpp que seja equivalente à função abaixo.

/*** R
selecionar <- function(v, s) {
  v[s]
}
*/


// Crie uma função equivalente à função `rep` do R

/*** R
rep(c(1,2,3), 3)
*/