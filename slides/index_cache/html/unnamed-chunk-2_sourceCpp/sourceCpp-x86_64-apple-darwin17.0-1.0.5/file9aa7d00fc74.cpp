#include <Rcpp.h>
// [[Rcpp::export]]
void hello (std::string name)
{
  Rcpp::Rcout << 
    "hello " + name << 
      std::endl;
}
