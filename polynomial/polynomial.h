#pragma once
#include <vector>
using namespace std;

namespace mathTools
{

    class polynomial {
    private:
        vector<double> m_data;
        void swap(polynomial& m);

    public:
        polynomial();
        polynomial(int size, double* m_data);

        polynomial(const polynomial& other);/*конструктор копирования*/
        polynomial& operator=(const polynomial& other); // присваивание

        polynomial& operator=(polynomial&& m) noexcept; //move
        polynomial(polynomial&& m) noexcept; //move

        double operator()(double x);

        void set(int size, double* m_data);

        void delNull();
        void print();
        polynomial delMod(const polynomial& polynomial1, const polynomial& polynomial2, polynomial& polynomial3);


        friend polynomial& operator+=(polynomial& polynomial1, const polynomial& polynomial2);
        friend polynomial operator+(const polynomial& polynomial1, const polynomial& polynomial2);
        friend polynomial& operator-=(polynomial& polynomial1, const polynomial& polynomial2);
        friend polynomial operator-(const polynomial& polynomial1, const polynomial& polynomial2);
        friend polynomial& operator*=(polynomial& polynomial1, const polynomial& polynomial2);
        friend polynomial operator*(const polynomial& polynomial1, const polynomial& polynomial2);
        
        
    };

}
