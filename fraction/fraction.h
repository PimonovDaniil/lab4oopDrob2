#pragma once

namespace mathTools
{

    class fraction {
    private:
        int numerator;
        int denominator;

        unsigned gcd(unsigned a, unsigned b); //рекурсивный евклид
        void swap(fraction& m);
        bool isValid();
        void sokrDrop(); //сокращает дробь

    public:
        fraction(); //стандартный конструктор

        fraction(const fraction& other) ;/*конструктор копирования*/
        fraction(int numerator, int denominator); // конструктор с параметрами

        fraction(fraction&& m) noexcept; //move
        fraction& operator=(fraction&& m) noexcept; //move

        fraction& operator=(const fraction& other); // присваивание

        void setNumerator(int a);
        void setDenominator(int a);
        void set(int numerator, int denominator); //установка значений

        int getNumerator(); //вернуть числитель
        int getDenominator(); //вернуть знаменатель
        double get(); //вернуть десятичную дробь

        int divMode(int& a);
        void print(); // вывод на экран

        friend fraction& operator+=(fraction& fraction1, const fraction& fraction2);
        friend fraction operator+(const fraction& fraction1, const fraction& other);
        friend fraction& operator-=(fraction& fraction1, const fraction& fraction2);
        friend fraction operator-(const fraction& fraction1, const fraction& other);
        friend fraction& operator*=(fraction& fraction1, const fraction& fraction2);
        friend fraction operator*(const fraction& fraction1, const fraction& other);
        friend fraction& operator/=(fraction& fraction1, const fraction& fraction2);
        friend fraction operator/(const fraction& fraction1, const fraction& other);
    };

}
