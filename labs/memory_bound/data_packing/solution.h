
#include <array>

// Assume those constants never change
constexpr int N = 10000;
constexpr int minRandom = 0;
constexpr int maxRandom = 100;

// FIXME: this data structure can be reduced in size
#if 0
struct S {
  long long l;
  double d;
  int i;
  short s;
  bool b;

  bool operator<(const S &s) const { return this->i < s.i; }
};
#endif

struct S {
  float d;
  long long l:15;
  bool b:1;
  int i:8;
  short s:8;
  
  bool operator<(const S &s) const { return this->i < s.i; }
};
#if 0
template <int N>
class TD;
TD<sizeof(S)> td;
#endif

void init(std::array<S, N> &arr);
S create_entry(int first_value, int second_value);
void solution(std::array<S, N> &arr);
