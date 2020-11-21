// # RcppArmadillo
// ## Um vetor simples

// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>
using namespace arma;

// [[Rcpp::export]]
vec arma_vec()
{
  vec v(3);
	
  return v;
}

/*** R
arma_vec()
*/

// ## Modelo linear

// [[Rcpp::export]]
Rcpp::List fast_lm(const vec & y, const mat & X) {

  int n = X.n_rows, k = X.n_cols;
 
  colvec coef  = solve(X, y); 
  colvec resid = y - X*coef; 
 
  double sig2 = as_scalar(trans(resid)*resid/(n-k));
  colvec stderrest = sqrt(sig2 * diagvec(inv(trans(X)*X)));
 
 return Rcpp::List::create(Rcpp::Named("coefficients") = coef,
                           Rcpp::Named("stderr")       = stderrest);
}

/*** R
y <- log(trees$Volume)
X <- cbind(1, log(trees$Girth))

bench::mark(fast_lm(y, X), lm(log(Volume) ~ log(Girth), data = trees), check = FALSE)
*/

