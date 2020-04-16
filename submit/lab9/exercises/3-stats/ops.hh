#ifndef OPS_HH_
#define OPS_HH_

/** sorting operations */
class Ops {
public:

    /** return < 0, == 0, > 0 if a < b, a == b, a > b */
  int compare(int a, int b){
      compareCount++;
        return a - b;
  }
  
  /** swap a[i] and a[j] */
  void swap(int a[], int i, int j){
      int t = a[i];
      a[i] = a[j];
      a[j] = t;
      swapCount++;
  }

  int swapCount = 0;
  int compareCount = 0;
};


#endif //ifndef OPS_HH_
