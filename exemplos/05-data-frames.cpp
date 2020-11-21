// # Data frames
// ## Criando uma data frame

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
DataFrame df()
{
  NumericVector v = {1, 2};

  // Criando um data frame
  DataFrame df = DataFrame::create(Named("V1") = v,
                                   Named("V2") = clone(v));
  // Alterando o vetor v
  v = v * 2;
  return df;
}

/*** R
df()
*/

// ## Acessando colunas

// [[Rcpp::export]]
DataFrame df2()
{
  NumericVector v = {1, 2};

  // Criando um data frame
  DataFrame df = DataFrame::create(Named("V1") = clone(v),
                                   Named("V2") = clone(v));
  
  // Vai mudar o valor da coluna
  NumericVector v1 = df[0];
  v1 = v1 * 2;
  
  return df;
}

/*** R
df2()
*/

// ## Funções membras

// [[Rcpp::export]]
List membras()
{
  NumericVector v = {1, 2, 3};

  // Criando um data frame
  DataFrame df = DataFrame::create(Named("V1") = clone(v),
                                   Named("V2") = clone(v));
  
  // Outras funções
  DataFrame df2 = df;
  df2.fill(0);
  df2.push_back(v);
  df2.push_front(v);
  
  return List::create(Named("length") = df.length(),
                      Named("size")   = df.size(),
                      Named("nrow")   = df.nrow(),
                      Named("names")  = df.names(),
                      Named("resto")  = df2);
}

/*** R
str(membras())
*/

