#include <Rcpp.h>
using namespace Rcpp;

// Crie uma função que aplique uma função arbitrária 
// para cada linha de uma matriz.
// Essa função será parecida com que a função `apply` do R
// Faça com que essa função seja *interrompível* caso esteja
// demorando muito.

/*** R
x <- matrix(runif(1e6), ncol = 10)
res <- apply(x, 1, mean)
*/