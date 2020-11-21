#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
void hello_world() {
  Rcout << "Hello World" << std::endl;
}

/*** R
hello_world()
*/
