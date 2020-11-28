#include <Rcpp.h>
#include <unordered_set>
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::XPtr<std::unordered_set<double>> create_set(NumericVector conjunto)
{
  std::unordered_set<double>* set = new std::unordered_set<double>;
  for (int i = 0; i < conjunto.size(); i++)
  {
    set->insert(conjunto.at(i));
  }
  
  return Rcpp::XPtr<std::unordered_set<double>>(set);
}

// [[Rcpp::export]]
LogicalVector cpp_in (NumericVector x, Rcpp::XPtr<std::unordered_set<double>> conjunto) {
  
  LogicalVector outputs(x.size());
  for (int i = 0; i < x.size(); i++)
  {
    if (conjunto->find(x[i]) == conjunto->end())
    {
      outputs[i] = false;
    }
    else
    {
      outputs[i] = true;
    }
    
  }
  
  return outputs;
}

/*** R
set <- create_set(50:1e6)
set
cpp_in(1:1e6, set)
*/

/*** R
x <- sample(1:1e6, size = 1e6, replace = TRUE)
conjunto <- sample(50:2000, size = 1e6, replace = TRUE)

set_cpp <- create_set(conjunto)
set_r <- unique(conjunto)

bench::mark(
  cpp_in(x, set_cpp),
  x %in% set_r
)
*/