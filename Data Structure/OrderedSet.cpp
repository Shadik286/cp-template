#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Fix go to the dir -> C:\MinGW\lib\gcc\mingw32\8.2.0\include\c++\ext\pb_ds\detail\resize_policy

//There u will see a file similar to -> "hash_standard_resize_policy_imp.hpp0000644"

//Rename it to hash_standard_resize_policy_imp.hpp
// find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
//   Let us assume we have a set s : {1, 5, 6, 17, 88}, then :  
//   *(s.find_by_order(2)) : 3rd element in the set i.e. 6
//   *(s.find_by_order(4)) : 5th element in the set i.e. 88
// order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
//   Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
//   s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
//   s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.

for multi order set -> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
                                                              less changes to less_equal
Upper_bound becomes lower_bound and vice versa

int FirstIdx(ordered_set<int> &s,int x){ //this function returns the first index of the value (x)..(0 indexing).
    return (s.order_of_key(x));
}
int LastIdx(ordered_set<int> &s,int x){ //this function returns the last index of the value (x)..(0 indexing).
    if(*s.find_by_order((int)s.size() - 1) == x) return (int)s.size() - 1;
    return FirstIdx(s,*s.lower_bound(x))-1;
}
int Count(ordered_set<int> &s,int x) { // this function will return number of x.
    return LastIdx(s, x) - FirstIdx(s, x) + 1;
}
ro erase -> s.erase(s.upper_bound(x));
