#include "goods_and_money.h"

void Money::Init() {
    hryvnia = 0;
    kopiyky = 0;
}

void Money::InitFromDouble(double amount) {
    hryvnia = static_cast<long>(amount);
    kopiyky = static_cast<unsigned char>((amount - hryvnia) * 100);
}

void Money::Read() {
    
}

void Money::Display() {
   
}

double Money::toDouble() const {
    return hryvnia + static_cast<double>(kopiyky) / 100;
}

Money Money::operator+(const Money& other) const {
    Money result{};
    result.hryvnia = this->hryvnia + other.hryvnia;
    result.kopiyky = this->kopiyky + other.kopiyky;
    return result;
}

Money Money::operator-(const Money& other) const {
    Money result{};
    result.hryvnia = this->hryvnia - other.hryvnia;
    result.kopiyky = this->kopiyky - other.kopiyky;
    return result;
}

Money Money::operator/(int divisor) const {
    Money result{};
    result.hryvnia = this->hryvnia / divisor;
    result.kopiyky = this->kopiyky / divisor;
    return result;
}

Money Money::operator/(double divisor) const {
    Money result{};
    double amount = this->toDouble() / divisor;
    result.hryvnia = static_cast<long>(amount);
    result.kopiyky = static_cast<unsigned char>((amount - result.hryvnia) * 100);
    return result;
}

Money Money::operator*(double multiplier) const {
    Money result{};
    double amount = this->toDouble() * multiplier;
    result.hryvnia = static_cast<long>(amount);
    result.kopiyky = static_cast<unsigned char>((amount - result.hryvnia) * 100);
    return result;
}

bool Money::operator==(const Money& other) const {
    return (this->hryvnia == other.hryvnia && this->kopiyky == other.kopiyky);
}

bool Money::operator<(const Money& other) const {
    return (this->toDouble() < other.toDouble());
}

bool Money::operator>(const Money& other) const {
    return (this->toDouble() > other.toDouble());
}

long Money::getHryvnia() const {
    return hryvnia;
}

unsigned char Money::getKopiyky() const {
    return kopiyky;
}

void Money::setHryvnia(long newHryvnia) {
    hryvnia = newHryvnia;
}

void Money::setKopiyky(unsigned char newKopiyky) {
    kopiyky = newKopiyky;
}

// toString implementation
std::string Money::toString() const {
    std::string result = std::to_string(hryvnia) + "." + std::to_string(kopiyky);
    return result;
}
