
/*
  08/May/2022
  This is an example of the Decorator Design Pattern
  The decorator is a wrapper around an object that allows to add behavior to an
  object during runtime using composition instead of inheritance.

  Pizza defines the generic behavior
  PizzaWithTopping wraps a Pizza object
  All specialities pizzas inherit from PizzaWithTopping and as it receive a
  Pizza object as constructor argument the different specialities can be
  chained.

  Pizza interface remain as it was originally designed

  A new wrapping interface PizzaWithTopping is created that inherit the Pizza interface
  and receive a Pizza object as a constructor argument and relays to it all the
  Pizza methods.

  All new specialities needed inherit from the wrapper class PizzaWithTopping
*/
#include <iostream>
#include <memory>
#include <string>

class Pizza {
public:
  virtual std::string getDescription() = 0;
  virtual float getCost() = 0;
};

class PlainPizza : public Pizza {
public:
  std::string getDescription() override { return "Base dought"; }
  float getCost() override { return 2.0f; }
};

class PizzaWithToppings : public Pizza {
protected:
  std::unique_ptr<Pizza> _pizza;

public:
  PizzaWithToppings(Pizza *newPizza) { _pizza.reset(newPizza); }
  virtual std::string getDescription() = 0 { return _pizza->getDescription(); }
  virtual float getCost() = 0 { return _pizza->getCost(); }
};

class Motzarella : public PizzaWithToppings {
public:
  Motzarella(Pizza *newPizza) : PizzaWithToppings(newPizza) {}
  std::string getDescription() {
    return _pizza->getDescription() + " Motzarrella";
  }
  float getCost() { return _pizza->getCost() + 0.5f; }
};

class Mexican : public PizzaWithToppings {
public:
  Mexican(Pizza *newPizza) : PizzaWithToppings(newPizza) {}
  std::string getDescription() { return _pizza->getDescription() + " Mexican"; }
  float getCost() { return _pizza->getCost() + 1.0f; }
};

int main() {
  std::unique_ptr<PizzaWithToppings> pizzaTop =
      std::make_unique<Mexican>((new Motzarella(new PlainPizza())));
  std::cout << pizzaTop->getDescription() << "\n";
  std::cout << pizzaTop->getCost() << "\n";

  return 0;
}