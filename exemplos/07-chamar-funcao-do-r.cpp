// # Chamar uma função do R

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector cpp_bootstrap(NumericVector x, int n, Function stat)
{
  NumericVector stats;
  NumericVector tmp;
  NumericVector s;
  for (int i = 0; i < n; i ++)
  {
    tmp = Rcpp::sample(x, true);
    s = stat(tmp);
    stats.push_back(s.at(0));
  }
  
  return stats;
}

/*** R
x <- rnorm(1e5)
stats <- cpp_bootstrap(x, 100, mean)
hist(stats)
*/

