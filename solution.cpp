#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
using namespace sol940;
using namespace std;

/*takeaways
  - every time you identify an outermost pair of () you
    find a primitive decomposition as what's
    inside () can't be decomposed
*/

string Solution::remove(string S)
{
  /* start with a '('
     - idx will always points at
       the '(' of an outermost
       parentheses
  */
  auto stack = 1, idx = 0;

  string result;
  for (auto i = 1; i < S.size(); i++)
  {
    if (S[i] == '(')
      stack++;
    else
      stack--;
    /* i must be pointing at a ')' now
       - the size of the entire expression
         for s[idx..i] is i - idx + 1
       - we have to remove the outermost parentheses
         - so it comes to i - idx + 1 - 2
         - the start position of the primitive decomposition
           is idx + 1
    */
    if (stack == 0)
    {
      result += S.substr(idx + 1, i - idx + 1 - 2);
      idx = i + 1;
    }
  }

  return result;
}