#pragma once
#include <iostream>


template <typename T>
class String
{
		private:
			T* m_data = nullptr;
			int m_size = 0;
		public:
			String(const T* a_data);
			String(const String<T>& a_string);
			String(String<T>&& a_string);
			~String();
			inline T* GetData() const;
			void SetData(const T* a_data);
			inline int GetSize() const;
			String<T>& operator=(const String<T>& a_string);
			template <typename U>
			friend std::ostream& operator<<(std::ostream& a_out, const String<U>& a_string);			
};
