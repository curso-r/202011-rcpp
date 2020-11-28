#include <Rcpp.h>
using namespace Rcpp;

// ## Raíz quadrada

// [[Rcpp::depends(RcppParallel)]]
#include <RcppParallel.h>
using namespace RcppParallel;

// [[Rcpp::export]]
NumericVector vectorSqrt(NumericVector x) {
  NumericVector v(x.size());
  for (int i = 0; i < x.size(); i++) {
    v[i] = ::sqrt(x[i]);
  }
  return v;
}

// Esse é o chamado "tabalhador" que realizará a operação
struct SquareRoot : public Worker
{
  // Vetor de entrada (note que é uma template)
  // O tipo é const porque ele não pode ser modificado
  const RVector<double> input;
  
  // Vetor de saída
  RVector<double> output;
  
  // Inicializar a entrada e a saída como si próprias
  SquareRoot(const NumericVector input, NumericVector output) 
    : input(input), output(output) {}
  
  // Usar transform() para aplicar a transformação (na fatia autorizada)
  void operator()(std::size_t begin, std::size_t end) {
    std::transform(input.begin() + begin, 
                   input.begin() + end, 
                   output.begin() + begin, 
                   ::sqrt);
  }
};

// [[Rcpp::export]]
NumericVector parallelVectorSqrt(NumericVector x) {
  
  // Alocar o vetor de saída
  NumericVector v(x.size());
  
  // Inicializar o functor
  SquareRoot functor(x, v);
  
  // Chamar parallelFor() do início ao fim do vetor de entrada
  parallelFor(0, x.size(), functor);
  
  return v;
}

/*** R
v <- as.numeric(c(1:1000000))
bench::mark(sqrt(v), vectorSqrt(v), parallelVectorSqrt(v))
*/



// ## Soma do vetor

// [[Rcpp::export]]
double vectorSum(NumericVector x) {
  double total = 0;
  for (int i = 0; i < x.size(); i++) {
    total += x[i];
  }
  return total;
}

// Esse é o chamado "tabalhador" que realizará a operação
struct Sum : public Worker
{   
  // Vetor de entrada
  const RVector<double> input;
  
  // Valor de saída
  double value;
  
  // Construtures (inicializar a entrada e a saída)
  Sum(const NumericVector input) : input(input), value(0) {}
  Sum(const Sum& functor, Split) : input(functor.input), value(0) {}
  
  // Usar accumulate() para aplicar a soma (na fatia autorizada)
  void operator()(std::size_t begin, std::size_t end) {
    value += std::accumulate(input.begin() + begin, input.begin() + end, 0.0);
  }
  
  // Juntar os valores de uma soma com o resultado parcial
  void join(const Sum& functor) { 
    value += functor.value; 
  }
};

// [[Rcpp::export]]
double parallelVectorSum(NumericVector x) {
  
  // Inicializar o functor
  Sum functor(x);
  
  // Chamar parallelFor() do início ao fim do vetor de entrada
  parallelReduce(0, x.size(), functor);
  
  // return the computed sum
  return functor.value;
}

/*** R
v <- as.numeric(c(1:1000000))
bench::mark(sum(v), vectorSum(v), parallelVectorSum(v))
*/
