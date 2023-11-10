#ifndef MONEY_H
#define MONEY_H

class Money {
public:
    Money();
    int GetAmount() const;
    void SetAmount(int newAmount);
    void AddAmount(int value);
    void SubtractAmount(int value);

private:
    int amount;
};

#endif
