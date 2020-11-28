// Escreva uma função em C++ que seja equivalente à função 
// em R abaixo:

/*** R
soma_n <- function(n) {
  total <- 0
  for (i in seq_len(n)) {
    total <- total + i
  }
  total
}

soma_n(10)
*/

#include<Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export]]
int cpp_soma_n (int n)
{
  int total = 0;
  for (int i = 1; i <= n; i++)
  {
    total = total + i;
  }
  return total;
}

/*** R
cpp_soma_n(10)
*/
