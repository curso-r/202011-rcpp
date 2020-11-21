#include <Rcpp.h>
// [[Rcpp::export]]
void hello (std::string name)
{
  Rcpp::Rcout << 
    "hello " + name << 
      std::endl;
}


#include <Rcpp.h>
// hello
void hello(std::string name);
RcppExport SEXP sourceCpp_1_hello(SEXP nameSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    hello(name);
    return R_NilValue;
END_RCPP
}
