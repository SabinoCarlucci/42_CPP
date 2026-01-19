/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:13:07 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/19 19:09:15 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>

//constructors
template <typename T> //empty contructor
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T> //parametric constructor
Array<T>::Array(unsigned int n) : _data(NULL), _size(n)
{
	if (n > 0)
		_data = new T[n];
}

template <typename T> //copy constructor
Array<T>::Array(const Array &other) : _data(NULL), _size(other._size)
{
	if (_size > 0)
	{
		_data = new T[_size];
		for (unsigned int i = 0;i < _size; i++)
			_data[i] = other._data[i];
	}
}


//destructor
template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

//operators
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		_data = (_size > 0) ? new T[_size] : NULL;
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return *this;
}

// [] non const
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return _data[index];
}

// [] const
template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::exception();
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
