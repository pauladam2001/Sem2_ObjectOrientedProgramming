////
//// Created by paula on 3/21/2021.
////
//
//#include "tests.h"
//#include "cassert"
//#include "trenchCoat.h"
//#include "validators.h"
//#include "dynamicArray.h"
//#include "service.h"
//#include "userService.h"
//#include "repository.h"
//
//
//void test_entity() {
//    trenchCoat newCoat("XS", "blue", 100, 50, "https://abc.ro");
//    assert(newCoat.getSize() == "XS");
//    assert(newCoat.getColor() == "blue");
//    assert(newCoat.getPrice() == 100);
//    assert(newCoat.getQuantity() == 50);
//    assert(newCoat.getPhotograph() == "https://abc.ro");
//    char string[100];
//    newCoat.to_string(string);
//}
//
//void test_validators() {
//    Validator* validator = new Validator();
//    assert(validator->validate_price_or_quantity("123") == 1);
//    assert(validator->validate_price_or_quantity("12a3") == 0);
//    assert(validator->validate_size("XXL") == true);
//    assert(validator->validate_size("X") == false);
//    assert(validator->validate_color("blue") == true);
//    assert(validator->validate_color("blu1e") == false);
//    assert(validator->validate_photograph("https://....ro") == true);
//    assert(validator->validate_photograph("https://.ro") == false);
//    assert(validator->validate_photograph("xxxxxxxxxxxxxxx") == false);
//    assert(validator->validate_photograph("https://xxxxx") == false);
//}
//
//void test_dynamic_array() {
//    dynamicArray<trenchCoat>* dynArray = new dynamicArray<trenchCoat>(1);
//    trenchCoat newCoat("XS", "blue", 100, 50, "https://abc.ro");
//    assert(dynArray->getSize() == 0);
//    dynArray->add(newCoat);
//    assert(dynArray->getSize() == 1);
//    dynArray->add(newCoat);
//    dynArray->delete_(0);
//    dynArray->getData();
//    assert(dynArray->getSize() == 1);
//    dynArray->add(newCoat);
//    trenchCoat newCoat2("XS", "blue", 500, 50, "https://abc.ro");
//    dynArray->update(0, newCoat2);
//    assert((*dynArray)[0].getPrice() == 500);
//    dynArray->empty();
//    assert(dynArray->getSize() == 0);
//    delete dynArray;
//}
//
//void test_repository() {
//    dynamicArray<trenchCoat>* dynArray = new dynamicArray<trenchCoat>(100);
//    Repository* repository = new Repository(dynArray);
//    repository->add_10_elements();
//    repository->getDynArr();
//    assert(repository->add_repo("XS", "blue", 120, 5, "https://bluexs.ro") == 0);
//    assert(repository->update_quantity_repo("XS", "blue", 0, "https://bluexs.ro") == 1);
//    assert(repository->delete_repo("XS", "blue", "https://bluexs.ro") == 1);
//    assert(repository->delete_repo("XS", "blue", "https://bluexs.ro") == 0);
//    assert(repository->update_quantity_repo("XS", "blue", 0, "https://bluexs.ro") == 0);
//    assert(repository->update_price_repo("S", "brown", 50, "https://browns.ro") == 1);
//    assert(repository->update_price_repo("XS", "blue", 0, "https://bluexs.ro") == 0);
//    delete repository;
//}
//
//void test_service_and_user_service() {
//    dynamicArray<trenchCoat>* dynArray = new dynamicArray<trenchCoat>(100);
//    Repository* repository = new Repository(dynArray);
//    repository->add_10_elements();
//    Service* service = new Service(repository);
//    UserService* userService = new UserService(repository);
//    service->getRepository();
//    assert(service->add_service("XS", "blue", 120, 5, "https://bluexs.ro") == 0);
//    assert(service->add_service("XS", "brown", 120, 5, "https://brownxs.ro") == 1);
//    assert(service->delete_service("XS", "brown", "https://brownxs.ro") == 0);
//    assert(service->update_quantity_service("XS", "brown", 0, "https://brownxs.ro") == 1);
//    assert(service->delete_service("XS", "brown", "https://brownxs.ro") == 1);
//    assert(service->update_quantity_service("XS", "brown", 15, "https://brownxs.ro") == 0);
//    assert(service->update_price_service("XS", "brown", 15, "https://brownxs.ro") == 0);
//    assert(service->update_price_service("XL", "orange", 70, "https://orangexl.ro") == 1);
////    dynamicArray<trenchCoat>* dynArray2;
////    dynArray2 = service->available_size_coats("XS");
////    assert(dynArray2->getSize() == 3);
////    dynamicArray<trenchCoat>* basket = new dynamicArray<trenchCoat>(100);
////    service->update_basket(basket, dynArray2, 0);
////    assert(basket->getSize() == 1);
////    assert(dynArray2->getData()[0].getQuantity() == 1);
////    service->update_basket(basket, dynArray2, 0);
////    assert(dynArray2->getData()[0].getQuantity() == 0);
////    service->delete_quantity_zero(dynArray2, 0);
////    assert(dynArray2->getSize() == 2);
//    assert(*userService->getTotalPrice() == 0);
//    userService->setTotalPrice(20);
//    assert(*userService->getTotalPrice() == 20);
//    userService->available_size_coats("");
//    assert(userService->getAvailableSizeCoats()->getSize() == 10);
//    userService->available_size_coats("XS");
//    assert(userService->getAvailableSizeCoats()->getSize() == 3);
//    userService->update_basket(2);
//    assert(userService->getBasket()->getSize() == 1);
//    userService->update_basket(2);
//    userService->delete_quantity_zero(2);
//    assert(userService->getAvailableSizeCoats()->getSize() == 2);
//    delete service;
//    delete userService;
//}
//
//void run_tests() {
//    test_entity();
//    test_validators();
//    test_dynamic_array();
//    test_repository();
//    test_service_and_user_service();
//}
