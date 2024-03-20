#pragma once

#include <string>

class Money {
private:
    long hryvnia;
    unsigned char kopiyky;

public:
    void Init();
    void InitFromDouble(double amount);
    void Read();
    void Display();
    double toDouble() const;
    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;
    Money operator/(int divisor) const;
    Money operator/(double divisor) const;
    Money operator*(double multiplier) const;
    bool operator==(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator>(const Money& other) const;

    long getHryvnia() const;
    unsigned char getKopiyky() const;

    void setHryvnia(long newHryvnia);
    void setKopiyky(unsigned char newKopiyky);

    std::string toString() const;
};

class Goods {
private:
    std::string name;
    std::string date;
    Money price;
    int quantity;
    int invoiceNumber;

public:
    void Init();
    void Read();
    void Display();
    std::string toString() const;
    Money calculateTotalPrice() const;
    void changePrice(const Money& newPrice);
    void changeQuantity(int newQuantity);

    std::string getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    std::string getDate() const { return date; }
    void setDate(const std::string& newDate) { date = newDate; }

    Money getPrice() const { return price; }
    void setPrice(const Money& newPrice) { price = newPrice; }

    int getQuantity() const { return quantity; }
    void setQuantity(int newQuantity) { quantity = newQuantity; }

    int getInvoiceNumber() const { return invoiceNumber; }
    void setInvoiceNumber(int newInvoiceNumber) { invoiceNumber = newInvoiceNumber; }
};
