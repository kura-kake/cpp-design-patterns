#include "CaliforniaPizzaStore.h"
#include "CaliforniaStylePizzas.h"   // カリフォルニアのピザを知っているのはここだけ

// 店ごとに作れるピザの種類が違ってもかまいません。この店には clam と pepperoni がなく、bbqchicken があります。
// これも、ピザの種類を決めるのがサブクラスだから可能になります。
std::unique_ptr<Pizza> CaliforniaPizzaStore::createPizza(const std::string& type) const {
    if (type == "cheese")      return std::make_unique<CaliforniaStyleCheesePizza>();
    if (type == "veggie")      return std::make_unique<CaliforniaStyleVeggiePizza>();
    if (type == "bbqchicken")  return std::make_unique<CaliforniaStyleBBQChickenPizza>();
    return nullptr;
}