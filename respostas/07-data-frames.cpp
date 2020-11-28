#include <Rcpp.h>
using namespace Rcpp;

// Crie uma uma função em Rcpp que seja equivalente à função abaixo e compare os
// seus desempenhos. Dica: tente entender como a função Rcpp::is() funciona.

/*** R
media <- function(df) {
  dplyr::summarise_if(df, is.numeric, mean)
}
*/
