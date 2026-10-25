#include <iostream>
#include "PizzaStore.h"
#include "SimplePizzaFactory.h"

int main() {
    SimplePizzaFactory factory;
    PizzaStore store(factory);

    store.orderPizza("cheese");
    std::cout << "----\n";
    store.orderPizza("clam");
    std::cout << "----\n";
    store.orderPizza("sushi");  // 未知の種類
        std::cout << "----\n";
    store.orderPizza("hawaiian"); //追加したハワイアンピザ
}