#pragma once

namespace mathTools
{

    class fraction {
    private:
        int numerator;
        int denominator;

        friend fraction& operator+=(fraction& fraction1, const fraction& fraction2);
        friend fraction operator+(const fraction& fraction1, const fraction& other);
        friend fraction& operator-=(fraction& fraction1, const fraction& fraction2);
        friend fraction operator-(const fraction& fraction1, const fraction& other);
        friend fraction& operator*=(fraction& fraction1, const fraction& fraction2);
        friend fraction operator*(const fraction& fraction1, const fraction& other);
        friend fraction& operator/=(fraction& fraction1, const fraction& fraction2);
        friend fraction operator/(const fraction& fraction1, const fraction& other);

        unsigned gcd(unsigned a, unsigned b); //рекурсивный евклид
        void swap(fraction& m);

        void sokrDrop(); //сокращает дробь

    public:

        int divMode(int &a);

        fraction(const fraction& other) ;/*конструктор копирования*/

        fraction(fraction&& m) noexcept; //move

        fraction& operator=(fraction&& m) noexcept; //move

        fraction(); //стандартный конструктор

        void set(int numerator, int denominator); //установка значений

        fraction(int numerator, int denominator); // конструктор с параметрами

        fraction& operator=(const fraction& other); // присваивание

        void print(); // вывод на экран

        int getNumerator(); //вернуть числитель

        int getDenominator(); //вернуть знаменатель

        double get(); //вернуть десятичную дробь
    };

}
