#include <iostream>
#include "goods_and_money.h"

int main() {
    Goods goods;
    goods.Init();

    std::string goodsName;
    std::cout << "Enter the name of the goods: ";
    std::cin >> goodsName;
    goods.setName(goodsName);

    std::string goodsDate;
    std::cout << "Enter the date (in format DD/MM/YYYY): ";
    std::cin >> goodsDate;
    goods.setDate(goodsDate);

    std::cout << "Enter the price: ";
    double priceAmount;
    std::cin >> priceAmount;
    Money goodsPrice{};
    goodsPrice.InitFromDouble(priceAmount);
    goods.setPrice(goodsPrice);

    std::cout << "Enter the quantity: ";
    int goodsQuantity;
    std::cin >> goodsQuantity;
    goods.setQuantity(goodsQuantity);

    std::cout << "Enter the invoice number: ";
    int invoiceNumber;
    std::cin >> invoiceNumber;
    goods.setInvoiceNumber(invoiceNumber);

    Money totalPrice = goods.calculateTotalPrice();
    std::cout << "Total price: " << totalPrice.toDouble() << std::endl;

    std::cout << goods.toString() << std::endl;

    return 0;
}
