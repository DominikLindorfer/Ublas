/*
 * main.cpp
 *
 *  Created on: 09.03.2018
 *      Author: dl
 */

#include <iostream>
#include "ublas.hpp"
#include <list>
#include <vector>
#include <boost/assign/std/vector.hpp> // for 'operator+=()'
#include <boost/assert.hpp>;
#include <initializer_list>

using namespace boost::assign; // bring 'operator+=()' into scope

using namespace std;

//template<class T>
//struct S {
//    std::vector<T> v;
//    S(std::initializer_list<T> l) : v(l) {
//         std::cout << "constructed with a " << l.size() << "-element list\n";
//    }
//    void append(std::initializer_list<T> l) {
//        v.insert(v.end(), l.begin(), l.end());
//    }
//    std::pair<const int*, size_t> c_arr() const {
//        return {&v[0], v.size()};  // list-initialization in return statement
//    }
//};


//template <typename T>
//class make_vector {
//public:
//  typedef make_vector<T> my_type;
//  my_type& operator<< (const T& val) {
//    data_.push_back(val);
//    return *this;
//  }
//  operator std::vector<T>() const {
//    return data_;
//  }
//private:
//  std::vector<T> data_;
//};


int main(){

	Vektor<double> s_vec;
	vec_append(s_vec, {1,2,3});

	cout << "s_vec: " << s_vec << endl;


	Matrix<double> s_mat;
	mat_append(s_mat, { {1,2,3} , {3,4,5} } );
	cout << "smat : " << s_mat << endl;


	return 0;
}
