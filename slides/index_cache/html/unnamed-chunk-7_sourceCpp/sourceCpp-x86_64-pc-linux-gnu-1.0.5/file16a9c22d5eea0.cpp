#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector f1(Function f) {
  return f(1);
}
