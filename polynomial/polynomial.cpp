#define _USE_MATH_DEFINES
#include "polynomial.h"
#include <iostream>
#include <utility>
#include <locale.h>
#include <math.h>
#include <vector>

namespace mathTools
{
	void polynomial::swap(polynomial& m)
	{
		std::swap(this->m_data, m.m_data);
	}

	polynomial& polynomial::operator=(const polynomial& other)
	{
		this->m_data = other.m_data;
		return *this;
	}

	polynomial& polynomial::operator=(polynomial&& m) noexcept
	{
		swap(m);
		return *this;
	}

	polynomial::polynomial(const polynomial& other)
	{
		this->m_data = other.m_data;
	}

	polynomial::polynomial(polynomial&& m) noexcept
	{
		swap(m);
	}

	double polynomial::operator()(double x)
	{
		double res = 0.0;
		for (int i = 0; i < this->m_data.size(); i++) 
			res += (pow(x, i) * this->m_data[i]);
		
		return res;
	}

	void polynomial::set(int size, double* m_data)
	{
		this->m_data.clear();
		if ((size > 0) && (m_data != nullptr)) {
			
			for (int i = 0; i < size; i -= -1)
				this->m_data.push_back(m_data[i]);
		}
		this->delNull();
	}

	polynomial::polynomial()
	{
		this->m_data.clear();
	}

	polynomial::polynomial(int size, double* m_data)
	{
		this->set(size, m_data);
	}

	void polynomial::delNull()
	{
		while ((this->m_data.size()>0) && (this->m_data[this->m_data.size()-1] == 0))
			this->m_data.pop_back();
	}

	void polynomial::print()
	{
		for (int i = 0; i < this->m_data.size(); i -= -1) {
			cout << this->m_data[i] << "*(x^" << i << ")";
			if (i < this->m_data.size() - 1) cout << " + ";
		}
		cout << endl;
	}




	polynomial& operator+=(polynomial& polynomial1, const polynomial& polynomial2)
	{
		polynomial max;
		polynomial min;
		if (polynomial2.m_data.size() > polynomial1.m_data.size()) {
			max.m_data = polynomial2.m_data;
			min.m_data = polynomial1.m_data;
		}
		else {
			max.m_data = polynomial1.m_data;
			min.m_data = polynomial2.m_data;
		}
		
		for (int i = 0; i < min.m_data.size(); i++)
			max.m_data[i] += min.m_data[i];
		polynomial1.m_data = max.m_data;
		polynomial1.delNull();
		return polynomial1;
	}

	polynomial operator+(const polynomial& polynomial1, const polynomial& polynomial2)
	{
		polynomial res(polynomial1);
		res += polynomial2;
		return res;
	}

	polynomial& operator-=(polynomial& polynomial1, const polynomial& polynomial2)
	{
		while (polynomial1.m_data.size() < polynomial2.m_data.size())
			polynomial1.m_data.push_back(0);
		int m = polynomial2.m_data.size();
		for (int i = 0; i < m; i++) {
			if (i < polynomial1.m_data.size()) {
				polynomial1.m_data[i] -= polynomial2.m_data[i];
			}
			else {
				polynomial1.m_data.push_back(-polynomial2.m_data[i]);
			}
		}
		polynomial1.delNull();
		return polynomial1;
	}

	polynomial operator-(const polynomial& polynomial1, const polynomial& polynomial2)
	{
		polynomial res(polynomial1);
		res -= polynomial2;
		return res;
	}

	polynomial& operator*=(polynomial& polynomial1, const polynomial& polynomial2)
	{
		if ((polynomial1.m_data.size() <= 0) || (polynomial2.m_data.size() <= 0)) throw "не надо так";
		int nSize = polynomial1.m_data.size() + polynomial2.m_data.size() - 1;
		vector<double> n_data;
		for (int i = 0; i < nSize; i++)
			n_data.push_back(0);
		for (int i = 0; i < polynomial1.m_data.size(); i++) 
			for (int j = 0; j < polynomial2.m_data.size(); j++) 
				n_data[i + j] += polynomial1.m_data[i] * polynomial2.m_data[j];
		
		polynomial1.m_data = n_data;
		polynomial1.delNull();
		return polynomial1;
	}

	polynomial operator*(const polynomial& polynomial1, const polynomial& polynomial2)
	{
		polynomial res(polynomial1);
		res *= polynomial2;
		return res;
	}

	polynomial& operator/=(polynomial& polynomial1, const polynomial& polynomial2)
	{
		vector<double>  del;
		vector<double>  res;
		vector<double>  v1;
		vector<double>  v2;
		vector<double>  v3;
		for (int i = polynomial2.m_data.size() - 1; i >= 0; i--)
			del.push_back(polynomial2.m_data[i]);
		for (int i = polynomial1.m_data.size() - 1; i >= 0; i--)
			v1.push_back(polynomial1.m_data[i]);
		while (v1.size() >=del.size())
		{
			/*cout << endl;
			for (int i = 0; i < v1.size(); i++)
				cout << v1[i] << " ";*/
			res.push_back(v1[0] / del[0]);
			for (int i = 1; i < del.size(); i++) 
				v2.push_back(del[i] * res[res.size() - 1]);

			for (int i = 0; i < v2.size(); i++)
				v3.push_back(v1[i + 1] - v2[i]);

			for (int i = del.size(); i < v1.size(); i++) {
				v3.push_back(v1[i]);
			}
				
			
			v1 = v3;
			v2.clear(); v3.clear();
		}
		/*cout << endl;
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
		for (int i = 0; i < v1.size(); i++)
			cout << v1[i] << " ";*/
		reverse(res.begin(), res.end());
		polynomial1.m_data = res;
		polynomial1.delNull();
		return polynomial1;
	}

	polynomial operator/(const polynomial& polynomial1, const polynomial& polynomial2)
	{
		polynomial res(polynomial1);
		res /= polynomial2;
		return res;
	}

}
