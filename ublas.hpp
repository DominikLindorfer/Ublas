///////////////////////////////////////////////
//  ublas.hpp
//	Created by Dominik Lindorfer 11.10.2016
//	Implements a simple Boost::Vector Template
///////////////////////////////////////////////

#ifndef FEMSchroed_ublas_hpp
#define FEMSchroed_ublas_hpp


#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/banded.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

//-----This stuff is for LU Decomposition-----
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/lu.hpp>

#include <boost/numeric/ublas/operations.hpp>
#include <boost/numeric/ublas/assignment.hpp>

#include <list>
#include <vector>
#include <boost/assign/std/vector.hpp> // for 'operator+=()'
#include <boost/assert.hpp>;
#include <initializer_list>

template <typename T>
using Vektor = boost::numeric::ublas::vector<T>;

template <typename T>
using Matrix = boost::numeric::ublas::matrix<T>;

namespace ublas = boost::numeric::ublas;

//-----Push_Back Routine for UBLAS Vektor-----
template <typename T, typename A>
void push_back(Vektor<T>& vec, A item) {

	vec.resize((int)vec.size() + 1);
	vec(vec.size() - 1) = item;
}

//-----Initialize Ublas-Vektor by initializer list-----
template<typename T, typename A>
void vec_append(Vektor<A>& v, std::initializer_list<T> l) {

	for(auto it = l.begin(); it != l.end(); ++it) {
	    push_back(v, *it);
	}
}

//-----Initialize Ublas-Matrix by initializer lists-----
template<typename T, typename A>
void mat_append(Matrix<A>& mat, std::initializer_list< std::initializer_list<T> > st) {

//	std::cout << "st size: " << st.size() << std::endl;
//	std::cout << "st (st) size: " << st.begin()->size()  << std::endl;

	//-----Resize Matrix to initializer_list sizes & fill matrix after-----
	mat.resize((int)st.size(), (int)st.begin()->size());


	int i = 0;
	int j = 0;

	for (const auto& l : st) {
		j = 0;
		for (const auto& v : l) {

			mat(i, j) = v;
			j++;
		}
		i++;
	}
}



//template <typename T, typename U>
//ublas::vector<T> operator/(ublas::vector<T>& v, U& var)
//{
//    push_back(v,var);
//    return v;
//}


/*
template <typename T>
void push_back(Vektor<T>& vec, double item) {

	vec.resize((int)vec.size() + 1);
	vec(vec.size() - 1) = item;
}

template <typename T>
void push_back(Vektor<T>& vec, int item) {

	vec.resize((int)vec.size() + 1);
	vec(vec.size() - 1) = item;
}

template <typename T>
void push_back(Vektor<T>& vec, char* item) {

	vec.resize((int)vec.size() + 1);
	vec(vec.size() - 1) = item;
}
*/




#endif
