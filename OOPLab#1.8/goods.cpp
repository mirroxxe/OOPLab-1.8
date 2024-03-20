#include "goods_and_money.h"
#include <iostream>
#include <sstream>

void Goods::Init() {
    name = "";
    date = "";
    price.Init();
    quantity = 0;
    invoiceNumber = 0;
}

void Goods::Read() {
    std::cout << "Enter the name of the goods: ";
    std::cin >> name;

    std::cout << "Enter the date (in format DD/MM/YYYY): ";
    std::string inputDate
        ;
    std::cin >> date;

    std::cout << "Enter the price: ";
    price.Read();

    std::cout << "Enter the quantity: ";
    std::cin >> quantity;

    std::cout << "Enter the invoice number: ";
    std::cin >> invoiceNumber;
}

void Goods::Display() {
    // Implement Display method
    std::cout << "Name: " << name << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Price: " << price.toDouble() << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
    std::cout << "Invoice Number: " << invoiceNumber << std::endl;
}

std::string Goods::toString() const {
    std::string result = "Name: " + name + "\n";
    result += "Date: " + date + "\n";
    result += "Price: " + price.toString() + "\n";
    result += "Quantity: " + std::to_string(quantity) + "\n";
    result += "Invoice Number: " + std::to_string(invoiceNumber) + "\n";
    return result;
}

Money Goods::calculateTotalPrice() const {
    double total = price.toDouble() * quantity;
    Money totalPrice{};
    totalPrice.InitFromDouble(total);
    return totalPrice;
}

void Goods::changePrice(const Money& newPrice) {
    price = newPrice;
}

void Goods::changeQuantity(int newQuantity) {
    quantity = newQuantity;
}
