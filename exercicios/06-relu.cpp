#include <Rcpp.h>
using namespace Rcpp;

// Crie uma função com Rcpp que faça o ReLU de um vetor de números.
// No R essa função seria algo do tipo:

/*** R
relu <- function(x) {
  ifelse(x > 0, x, 0)
}
*/
