#include <iostream>
#include "fraction.h"

Fraction::Fraction()
	: numerator_(0), denominator_(1) {
}

Fraction::Fraction(int numerator)
	: numerator_(numerator), denominator_(1) {
}
Fraction::Fraction(int numerator, int denominator) {
		numerator_ = numerator;
		denominator_ = denominator;
		reduction();
	}

void Fraction::reduction() {
	int nod = gcd(std::abs(numerator_), std::abs(denominator_));
	numerator_ /= nod;
	denominator_ /= nod;
}

int Fraction::gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

bool Fraction::operator == (const Fraction & fr) const
{
	return numerator_ == fr.numerator_ && denominator_ == fr.denominator_;
}
bool Fraction::operator > (const Fraction & fr) const
{
	return((double)(this->numerator_ / this->denominator_) > (double)(fr.numerator_ / fr.denominator_)) ? true : false;
}
bool Fraction::operator != (const Fraction & fr) const
{
	return !(*this == fr);
}
bool Fraction::operator < (const Fraction & fr) const
{
	return !((*this > fr) || (*this == fr));
}
bool Fraction::operator >= (const Fraction & fr) const
{
	return !(*this < fr);
}
bool Fraction::operator <= (const Fraction & fr) const
{
	return !(*this > fr);
}

Fraction Fraction::operator++() {
	numerator_ += denominator_;
	reduction();
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction old_value(*this);
	++ *this;
	return old_value;
}

Fraction Fraction::operator--() {
	numerator_ -= denominator_;
	reduction();
	return *this;
}

Fraction Fraction::operator--(int) {
	Fraction old_value(*this);
	--* this;
	return old_value;
}

Fraction Fraction::operator+(const Fraction& fr) const {
	int a = numerator_, b = denominator_,
		c = fr.numerator_, d = fr.denominator_;

	Fraction result(a * d + b * c, b * d);
	return result;
}

Fraction operator+(const int fl, const Fraction& fr) {
	return Fraction(fl) + fr;
}

Fraction Fraction::operator-() const {
	return Fraction(-numerator_, denominator_);
}

Fraction Fraction::operator-(const Fraction& fr) const {
	return *this + (-fr);
}

Fraction operator-(const int fl, const Fraction& fr) {
	return Fraction(fl) - fr;
}

Fraction operator*(const int fl, const Fraction & fr) {
	return Fraction(fl) * fr;
}

Fraction operator/(const int fl, const Fraction& fr) {
	return Fraction(fl) / fr;
}

Fraction Fraction::operator*(const Fraction & fr) const {
	int a = numerator_, b = denominator_,
		c = fr.numerator_, d = fr.denominator_;
	Fraction result(a * c, b * d);
return result;
}

Fraction Fraction::operator/(const Fraction& fr) const {
	int a = numerator_, b = denominator_,
		c = fr.numerator_, d = fr.denominator_;
	Fraction result(a * d, b * c);
	return result;
}

Fraction Fraction::operator+=(const Fraction& fr) {
	*this = *this + fr;
	return *this;
}

std::ostream& operator<<(std::ostream& ost, const Fraction& value) {
	ost << value.numerator_ << "/" << value.denominator_;
	return ost;
}