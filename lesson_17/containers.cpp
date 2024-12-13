#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

// https://en.cppreference.com/w/cpp/container/vector
// https://en.cppreference.com/w/cpp/container/list
// https://en.cppreference.com/w/cpp/algorithm/sort

// Let's create our own super implementation!
namespace my_own_wheel {

	// Make it template is a good idea
	template<typename T>
	struct vector {
		vector() { /* ... */ }
		vector(const vector&) { /* ... */ }
		vector(vector&&) { /* ... */ }

		void push_back(const T& value) { /* ... */ }
		size_t size() const { /* ... */ }

		T& operator[](size_t index) { /* ... */ }

		/* ... */
	};

	// Just check compilation
	void test() {
		std::cout << "my_own_wheel example" << std::endl;
		// Good! Container of ints!
		vector<int> ints;
		// Good also! Container of floats!
		vector<float> floats;
		// Oh! Container of containers of ints!
		vector<vector<int>> int_matrix;
	}

} // namespace my_own_wheel


namespace basics {

	template<typename T>
	void print_vector(const std::vector<T>& vec) {
		for(size_t i = 0; i < vec.size(); ++i) {
			if(i != 0) {
				std::cout << ' ';
			}
			std::cout << vec[i];
		}
		std::cout << std::endl;
	}

	// This implementation does not work :(
	template<typename T>
	void print_list(const std::list<T>& lst) {
		for(size_t i = 0; i < lst.size(); ++i) {
			if(i != 0) {
				std::cout << ' ';
			}
			// std::cout << lst[i]; // std::list does not have operator[] !
		}
		std::cout << std::endl;
	}

	void example() {
		std::cout << "basics example" << std::endl;

		std::vector<int> ints_vector;
		for(int i = 0; i < 10; ++i) {
			ints_vector.push_back(i); // append element
		}
		ints_vector[3] = 10;
		print_vector(ints_vector);
		// 0 1 2 10 4 5 6 7 8 9

		std::cout << "ints_vector.size() = " << ints_vector.size() << std::endl;
		// 10

		std::list<int> ints_list;
		for(int i = 0; i < 10; ++i) {
			ints_list.push_back(i); // append element
		}
		// ints_list[3] = 10; // Not allowed - std::list does not have operator[]
		print_list(ints_list);
		//           

		std::cout << "ints_list.size() = " << ints_list.size() << std::endl;
		// 10
	}

}


namespace iterators {

	template<typename Iterator>
	void print_range(Iterator begin, Iterator end) {
		Iterator current = begin;
		while(current != end) {
			if(current != begin) {
				std::cout << ' ';
			}
			std::cout << *current;
			++current;
		}
		std::cout << std::endl;
	}

	void example() {
		std::cout << "iterators example" << std::endl;

		std::vector<int> ints_vec{0, 1, 2, 2, 2, 5, 6, 7, 8, 9};
		std::cout << "ints_vec values:" << std::endl;
		print_range(ints_vec.cbegin(), ints_vec.cend());
		// 0 1 2 3 4 5 6 7 8 9

		std::list<int> ints_lst{0, 1, 2, 2, 2, 5, 6, 7, 8, 9};
		std::cout << "ints_lst values:" << std::endl;
		print_range(ints_lst.cbegin(), ints_lst.cend());
		// 0 1 2 3 4 5 6 7 8 9

		std::replace(ints_vec.begin(), ints_vec.end(), 2, 99);
		std::cout << "ints_vec values after replace:" << std::endl;
		print_range(ints_vec.cbegin(), ints_vec.cend());
		// 9 8 7 6 5 4 3 2 1 0

		std::replace(ints_lst.begin(), ints_lst.end(), 2, 99);
		std::cout << "ints_lst values after replace:" << std::endl;
		print_range(ints_lst.cbegin(), ints_lst.cend());
		// 9 8 7 6 5 4 3 2 1 0
	}

}


int main() {

	my_own_wheel::test();
	basics::example();
	iterators::example();

	return 0;
}