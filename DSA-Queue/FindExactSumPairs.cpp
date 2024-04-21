#include <cstddef>

using namespace std;
class FindExactSumPairs{
    //Find a pair of array elements with sum being exactly equal to x
    int* findPair(int* arr, int n, int x){
        //The idea is to apply binary search with key x / 2. When the binary search finishes, we start from that index and check left and right entries
        //to see if we have sum equal to x, if not we decide to either go to left or to right
        //You might want to have the mid element fixed, just search for the second element to sum with the mid element (RETHINK THIS)
    }
}
