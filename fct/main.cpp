#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

///// In order for the function fct to work we need to overload the operator + because we may have different data types (TElem)
//template<typename TElem>
//TElem operator +(const TElem &sum, const TElem &elem) {
//    sum += elem;
//    return sum;
//}
//
///// This function adds (or concatenates) the elements from a given vector
///// \tparam TElem - the parameter can be string, double, int etc. so we need a template, TElem
///// \param data - the given std::vector containing data
///// \return - the sum (or the concatenation) of the elements
/////         - std::exception if the vector is empty
//template<typename TElem>
//TElem fct(vector<TElem> data) {
//    if (data.empty())
//        throw std::exception();
//    TElem sum;
//    for (auto &elem : data)
//        sum = sum + elem;
//    return sum;
//}
//
//void testFct() {
//    vector<int> v1 { 4, 2, 1, -4 };
//    assert(fct<int>(v1) == 3);
//    vector<int> v2;
//    try {
//        fct<int>(v2);
//        assert(false);
//    } catch (std::exception&) { assert(true); }
//
//    vector<double> v3{ 2, 10.5, 5, -10 };
//    assert(fct<double>(v3) == 7.5);
//
//    vector<string> v4{ "y", "q", "a", "m" };
//    assert(fct<string>(v4) == "yqam");
//}



/// This function finds the maximum element from a given vector
/// \tparam TElem - the parameter can be string, double, int etc. so we need a template, TElem
/// \param data - the given std::vector containing the data
/// \return - the maximum of the elements
///         - std::exception if the vector is empty
template<typename TElem>
TElem fct(vector<TElem> data) {
    if (data.empty())
        throw std::exception();
    TElem maximum;
    for (auto &elem : data)
        if (elem > maximum)
            maximum = elem;
    return maximum;
}

void testFct() {
    vector<int> v1 { 4, 2, 1, 6, 3, -4 };
    assert(fct<int>(v1) == 6);
    vector<int> v2;
    try {
        fct<int>(v2);
        assert(false);
    } catch (std::exception&) { assert(true); }

    vector<double> v3{ 2, 10.5, 6.33, -100, 9, 1.212 };
    assert(fct<double>(v3) == 10.5);

    vector<string> v4{ "y", "q", "a", "m" };
    assert(fct<string>(v4) == "y");
}

int main() {
    testFct();

    return 0;
}
