#include <Rcpp.h>
using namespace Rcpp;

// Crie uma uma função em Rcpp que seja equivalente à função abaixo e compare os
// seus desempenhos. Dica: tente entender como a função Rcpp::is() funciona.

/*** R
media <- function(df) {
  dplyr::summarise_if(df, is.double, mean)
}
*/

// [[Rcpp::export]]
NumericVector media_cpp(DataFrame df) {
  NumericVector out(df.size());
  out.names() = df.names();
  
  for (int i = 0; i < df.size(); i++) {
    if (is<NumericVector>(df[i]))
      out[i] = mean(as<NumericVector>(df[i]));
    else
      out[i] = NA_REAL;
  }
  
  return out;
}

/*** R
media_cpp(na.omit(dplyr::starwars))
media(na.omit(dplyr::starwars))
*/

// [[Rcpp::export]]
NumericVector media_certa_cpp(DataFrame df) {
  NumericVector out;
  
  for (int i = 0; i < df.size(); i++) {
    if (is<NumericVector>(df[i]))
      out.push_back(mean(as<NumericVector>(df[i])), std::string(as<StringVector>(df.names())[i]));
  }
  
  return out;
}

/*** R
media_certa_cpp(na.omit(dplyr::starwars))
*/
