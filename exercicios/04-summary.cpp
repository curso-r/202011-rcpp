#include <Rcpp.h>
using namespace Rcpp;

// Crie uma uma função que calcule a média, minimo e máximo de um vetor e 
// retorne uma lista com esses valores.

/*** R
summary2 <- function(x) {
  list(
    media = mean(x),
    min = min(x),
    max = max(x)
  )
}

summary2(runif(100))
*/


// Desafio! Lide com NA's nessa função.

/*** R
summary2 <- function(x, na.rm = TRUE) {
  list(
    media = mean(x, nam.rm = na.rm),
    min = min(x, na.rm = na.rm),
    max = max(x, na.rm = na.rm)
  )
}

summary2(runif(100))
*/