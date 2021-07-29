cmake_minimum_required(VERSION 3.17)
project(Sale_UML_Diagram_Written)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sale_UML_Diagram_Written
        main.cpp
        sale/Sale.h
        sale/Sale.cpp
        sale/SaleItem.h
        sale/SaleItem.cpp
        discount/Discount.h
        discount/ItemDiscount.cpp
        discount/ItemDiscount.h
        discount/SumDiscount.cpp
        discount/SumDiscount.h)