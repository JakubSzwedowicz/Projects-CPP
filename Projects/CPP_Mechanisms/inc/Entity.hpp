#pragma once
#include "String.hpp"

template <typename T>
class Entity
{
		private:
				String<T> m_string;
		public:
			
			// Constructors
			Entity(const T* a_data) : m_string(a_data) {std::cout << "Creating Entity with const T*, where T = " << typeid(T).name() << std::endl;};
			Entity(const String<T>& a_string) : m_string(a_string) {std::cout << "Creating Entity with const String<T>&, where T =  " << typeid(T).name() << std::endl;};
			Entity(String<T>&& a_string) : m_string(std::move(a_string)) {std::cout << "Created Entity with String&&, where T = " << typeid(T).name() << std::endl;};
			
			inline void Print() { std::cout << m_string << std::endl;};
			
			// operator overloads
			inline Entity<T>& operator=(const Entity<T>& a_entity) {m_string = a_entity.m_string; return *this;};
			inline Entity<T>& operator=(Entity<T>&& a_entity) {std::swap(m_string, a_entity.m_string); return *this;};
};

