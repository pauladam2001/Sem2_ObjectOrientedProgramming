#include <iostream>
#include "SmartPointer.h"
#include "Vector.h"


void function(){
    SmartPointer<int> i1{new int{1}};
    SmartPointer<int> i2{new int{2}};
    SmartPointer<int> i3{new int{3}};

    Vector<SmartPointer<int>> v1{};

    v1.add(i1).add(i2).add(i3);
    for(auto e : v1)
        cout << *e << ", ";

    SmartPointer<string> s1{new string{"A"}};
    SmartPointer<string>& s2 = s1;
    SmartPointer<string> s3{new string{"C"}};

    Vector<SmartPointer<string>> v2{};
    v2.add(s2).add(s1);


//    v2.add(s2).add(s1).add(s3);
//
//    for(auto e : v2)
//        cout << *e << ", ";


    try{
        v2 = v2 - s2;
        v2 = v2 - s3;
    }
    catch(std::exception& ex){
        cout<<ex.what();
    }

//    for(auto e : v2)
//        cout << *e << ", ";
}

int main() {
    function();

    return 0;
}
