#ifndef OUT_HH_
#define OUT_HH_

#include <algorithm>
#include <vector>


template <typename Iterator>
void
outContainer(Iterator begin, Iterator end) 
{
  std::cout << "[ ";
  auto print = [](const int& i) { std::cout << i << " " ; };
  std::for_each(begin, end, print);
  std::cout << "]" << std::endl;
}

/** create a vector which is identical to [begin, end) but with first
 *  occurrence of arg removed.  Output vector elements within [ ],
 *  separated by spaces.
 */
template <typename Iterator>
void
loopFn(Iterator begin, Iterator end, int arg)
{
  std::vector<int> vec;
  //@TODO
  outContainer(vec.begin(), vec.end());
}

/** Exactly like loopFn() but no loops should be used */
template <typename Iterator>
void noLoopFn(Iterator begin, Iterator end, int arg)
{
  //@TODO
}

#endif //ifndef OUT_HH_
