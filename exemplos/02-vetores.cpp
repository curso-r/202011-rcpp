// # Vetores

// ## Criando um vetor

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector vec(int n)
{
  NumericVector v(n);
  return v;
}


/*** R
vec(10)
*/

// ## Dando nomes para elementos

// [[Rcpp::export]]
NumericVector vec2()
{
  NumericVector v = NumericVector::create(Named("x") = 1 , _["y"] = 2);
  return v;
}

/*** R
vec2()
*/

// ## Vetores de strings

// [[Rcpp::export]]
StringVector vec3(int n)
{
  StringVector v(n);
  return v;
}

/*** R
vec3(3)
*/

// ## Inicialização

// [[Rcpp::export]]
StringVector vec4(int n, char c)
{
  StringVector v(n, c);
  return v;
}

/*** R
vec4(5, "k")
*/

// ## Acessar elementos

// [[Rcpp::export]]
List elementos()
{
  // Vetor com nomes (nova sintaxe!)
  NumericVector v = {10, 20, 30, 40, 50};
  v.names() = CharacterVector({"A", "B", "C", "D", "E"});
  
  // Vetores de acesso
  NumericVector   numeric = {1, 3};
  IntegerVector   integer = {1, 3};
  CharacterVector character = {"B", "D"};
  LogicalVector   logical = {false, true, false, true, false};
  
  // Acessando valores
  double x1          = v[0];
  double x2          = v["A"];
  NumericVector res1 = v[numeric];
  NumericVector res2 = v[integer];
  NumericVector res3 = v[character];
  NumericVector res4 = v[logical];
  
  // Vetor de atribuição
  NumericVector v2{200, 400};
  
  // Atribuindo valores
  v[0]         = 100;
  v["A"]       = 100;
  v[numeric]   = v2;
  v[integer]   = v2;
  v[character] = v2;
  v[logical]   = v2;
  
  return List::create(Named("x1")   = x1,
                      Named("x2")   = x2,
                      Named("res1") = res1,
                      Named("res2") = res2,
                      Named("res3") = res3,
                      Named("res4") = res4,
                      Named("v")    = v);
}

/*** R
elementos()
*/

// ## Funções membras

// [[Rcpp::export]]
List membras()
{
  // Vetor com nomes
  NumericVector v{10, 20, 30, 40, 50};
  v.names() = CharacterVector({"A", "B", "C", "D", "E"});
  
  // Outras funções
  NumericVector v2 = v;
  v2.fill(0);
  v2.push_back(-1);
  v2.push_front(1);
  v2.sort();
  
  return List::create(Named("length") = v.length(),
                      Named("size")   = v.size(),
                      Named("names")  = v.names(),
                      Named("resto")  = v2);
}

/*** R
membras()
*/

