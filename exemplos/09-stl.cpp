#include <Rcpp.h>
#include <unordered_set>
using namespace Rcpp;

// [[Rcpp::export]]
LogicalVector cpp_in (NumericVector x, NumericVector conjunto) {
  
  std::unordered_set<double> set;
  int size = conjunto.size();
  for (int i = 0; i < size; i++)
  {
    set.insert(conjunto.at(i));
  }
  
  size = x.size();
  LogicalVector outputs(size);
  for (int i = 0; i < size; i++)
  {
    outputs[i] = !(set.find(x[i]) == set.end());
  }
  
  return outputs;
}

/*** R
cpp_in(c(0,2,3), 1:10)
*/

/*** R
x <- sample(1:1e6, size = 1e6, replace = TRUE)
conjunto <- sample(50:2000, size = 1e6, replace = TRUE)

bench::mark(
  cpp_in(x, conjunto),
  x %in% conjunto
)
*/