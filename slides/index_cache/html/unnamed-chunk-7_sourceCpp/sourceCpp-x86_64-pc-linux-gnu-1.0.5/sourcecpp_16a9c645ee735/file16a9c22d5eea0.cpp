#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector f1(Function f) {
  return f(1);
}


#include <Rcpp.h>
// f1
NumericVector f1(Function f);
RcppExport SEXP sourceCpp_3_f1(SEXP fSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Function >::type f(fSEXP);
    rcpp_result_gen = Rcpp::wrap(f1(f));
    return rcpp_result_gen;
END_RCPP
}
