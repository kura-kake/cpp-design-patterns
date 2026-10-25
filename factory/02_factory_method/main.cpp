#include <iostream>
#include "NYPizzaStore.h"
#include "ChicagoPizzaStore.h"
#include "CaliforniaPizzaStore.h"   // 追加

void order(PizzaStore& store, const std::string& type) {
    // 変更なし
    auto pizza = store.orderPizza(type);
    if (pizza) {
        std::cout << "Ordered a " << pizza->name() << "\n";
    }
    std::cout << "----\n";
}

int main() {
    NYPizzaStore nyStore;
    ChicagoPizzaStore chicagoStore;
    CaliforniaPizzaStore californiaStore;   // 追加

    order(nyStore, "cheese");
    order(chicagoStore, "cheese");
    order(californiaStore, "cheese");       // 追加
    order(californiaStore, "bbqchicken");   // 追加
    order(californiaStore, "clam");         // 追加(この店にはない)
}