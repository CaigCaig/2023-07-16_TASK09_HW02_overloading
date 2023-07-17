#pragma once

class Fraction {
private:
	int numerator_;
	int denominator_;
	void reduction();
	int gcd(int a, int b);
public:
	Fraction();
	Fraction(int numerator);
	Fraction(int numerator, int denominator);


	bool operator== (const Fraction& fr) const;
	bool operator!= (const Fraction& fr) const;
	bool operator> (const Fraction& fr) const;
	bool operator< (const Fraction& fr) const;
	bool operator>= (const Fraction& fr) const;
	bool operator<= (const Fraction& fr) const;

	Fraction operator-() const;
	Fraction operator++();
	Fraction operator++(int);
	Fraction operator--();
	Fraction operator--(int);

	Fraction operator+(const Fraction& fr) const;
	Fraction operator-(const Fraction& fr) const;
	Fraction operator*(const Fraction& fr) const;
	Fraction operator/(const Fraction& fr) const;

	Fraction operator+=(const Fraction& fr);

	friend Fraction operator+(const int fl, const Fraction& fr);
	friend Fraction operator-(const int fl, const Fraction& fr);
	friend Fraction operator*(const int fl, const Fraction& fr);
	friend Fraction operator/(const int fl, const Fraction& fr);

	friend std::ostream& operator<<(std::ostream&, const Fraction& value);
};

