#include <Rcpp.h>
using namespace Rcpp;

// Crie uma função chamada cpp_all que receba um vetor booleano e retone TRUE
// se todos os valores forem TRUE e FALSE se pelo menos 1 não for.

/*** R
x <- c(TRUE, FALSE)
all(x)
*/

// [[Rcpp::export]]
bool cpp_all (LogicalVector x)
{
  bool out = true;
  for (int i = 0; i < x.size(); i++)
  {
    if (!x[i])
    {
      out = false;
      break;
    }
  }
  return out;
}

/*** R
cpp_all(c(TRUE, TRUE))
cpp_all(c(TRUE, FALSE))
*/