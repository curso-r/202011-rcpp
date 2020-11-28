#include <Rcpp.h>
using namespace Rcpp;

// Crie uma função em RcppArmadillo que seja exatamente equivalente à função
// sample() do R. Procure na documentação se já existe algo parecido e que você
// possa aproveitar.

/*** R
sample(letters[1:10], size = 3, replace = TRUE, prob = rep(1/10, 10))
*/
