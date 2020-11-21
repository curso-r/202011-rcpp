/*** R
fib_r <- function(n) {
  a <- 0
  b <- 1
  
  if (n >= 3) {
    for (i in seq(from = 3, to = n)) {
      c <- a + b
      a <- b
      b <- c
    }
  }
  
  b
}
*/

// [[Rcpp::export]]
int fib_cpp (int n)
{
  int a = 0;
  int b = 1;
  int c;
  
  for(int i = 3; i <= n; i++)
  {
    c = a + b;
    a = b;
    b = c;
  }
  
  return b;
}


/*** R
b <- bench::mark(
  fib_r(40),
  fib_cpp(40)
)
plot(b)
*/
