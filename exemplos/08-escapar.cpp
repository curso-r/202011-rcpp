// # Escapar de um loop

#include <unistd.h>
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
void forever()
{
  for (int i = 0; ; i++)
  {
    Rcout << "Iteration: " << i << std::endl;
    ::sleep(1);
  }
}

/*** R
# forever()
*/

// [[Rcpp::export]]
void forever2()
{
  for (int i = 0; ; i++)
  {
    Rcout << "Iteration: " << i << std::endl;
    ::sleep(1);
    checkUserInterrupt();
  }
}

/*** R
# forever2()
*/
