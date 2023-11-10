#include "money.h"

Money::Money() : amount(0) {}

int Money::GetAmount() const {
    return amount;
}

void Money::SetAmount(int newAmount) {
    amount = newAmount;
}

void Money::AddAmount(int value) {
    amount += value;
}

void Money::SubtractAmount(int value) {
    amount -= value;
}
