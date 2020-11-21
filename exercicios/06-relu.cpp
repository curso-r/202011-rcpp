#include <Rcpp.h>
using namespace Rcpp;

// Crie uma função com Rcpp que faça o ReLU de um vetor de números.
// No R essa função seria algo do tipo:

/*** R
relu <- function(x) {
  ifelse(x > 0, x, 0)
}
*/

// [[Rcpp::export]]
NumericVector cpp_relu(NumericVector x) {
  NumericVector out(x.size());
  for (int i = 0; i < x.size(); i++)
  {
    if (x[i] > 0)
      out[i] = x[i];
    else
      out[i] = 0;
  }
  return out;
}

/*** R
bench::mark(relu(-5000:5000), cpp_relu(-5000:5000))
*/

// [[Rcpp::export]]
NumericVector cpp_relu_errado(NumericVector x) {
  int n = x.length();
  for(int i = 0; i < n; i++) {
    if (x[i] < 0) {
      x[i] = 0; 
    }
  }
  return x;
}

// [[Rcpp::export]]
void dois_relu(NumericVector x) {
  
  NumericVector v1 = cpp_relu(x);
  Rcout << x[0] << std::endl;
  
  NumericVector v2 = cpp_relu_errado(x);
  Rcout << x[0] << std::endl;
}

/*** R
x <- -10:10
dois_relu(x)
*/
