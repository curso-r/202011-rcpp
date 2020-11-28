#include <unordered_set>
#include "cpp11.hpp"
using namespace cpp11;
namespace writable = cpp11::writable;

[[cpp11::register]]
logicals duplicated_cpp(integers x) {
  std::unordered_set<int> seen;
  int n = x.size();
  writable::logicals out(n);
  for (int i = 0; i < n; ++i) {
    out[i] = !seen.insert(x[i]).second;
  }
  return out;
}
