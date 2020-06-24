#include "String.hpp"
#include <iostream>
#include <cstring>

template class String<char>;
template std::ostream& operator<< (std::ostream& a_out, const String<char>& a_string);

template <typename T>
String<T>::String(const T* a_data)
{
		std::cout << "Created String by const T*" << typeid(T).name() << std::endl;
		m_size = strlen(a_data);
		m_data = new T [m_size];
		std::memcpy(m_data, a_data, m_size);
};

template<typename T>
String<T>::String(const String<T>& a_string)
{
	std::cout << "Created String with const String<T>" << typeid(T).name() << std::endl;
	m_size = a_string.m_size;
	m_data = new T [m_size];
	std::memcpy(m_data, a_string.m_data, m_size);
}
template<typename T>
String<T>::String(String<T>&& a_string)
{
		std::cout << "Created String with String<T>&&, when T = " << typeid(T).name() << std::endl;
		m_size = a_string.m_size;
		m_data = a_string.m_data;
		a_string.m_data = nullptr;
		a_string.m_size = 0;
}
template <typename T>
String<T>::~String()
{
		std::cout << "Destroying String<T>, where T = " << typeid(T).name() << std::endl;
		delete[] m_data;
}
template <typename U>
std::ostream& operator<< (std::ostream& a_out, const String<U>& a_string)
{
		for(int i = 0; i < a_string.m_size; i++)
				a_out << a_string.m_data[i];
		a_out << std::endl;
		return a_out;
}

template <typename T>
inline T* String<T>::GetData() const 
{
		return m_data;
}

template <typename T>
void String<T>::SetData(const T* a_data)
{
		delete[] m_data;
		m_size = strlen(a_data);
		m_data = new T [m_size];
		std::memcpy(m_data, a_data, m_size);
}

template <typename T>
inline int String<T>::GetSize() const
{
		return m_size;
}


