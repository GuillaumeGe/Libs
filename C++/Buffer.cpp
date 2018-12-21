#include "Buffer.h"
#include "stdlib.h"
#include <iostream>

template <class GenericType>
Buffer::Buffer(const GenericType* data, uint16_t size)
{
	this->_size = data ? size : 0;
	this->_data = data ? malloc(this->_size * sizeof(GenericType)) : nullptr;
}

Buffer::Buffer(const Buffer<GenericType> &other)
{
	this = &other;
}

Buffer::~Buffer()
{
	free(this->_data);
}

template <class GenericType>
void Buffer::resize(uint16_t newSize, bool saveData)
{
	this->_size = newSize;
	if (_data != nullptr) {
		if (saveData) {
			this->_data = realloc(this->_data,this->size * sizeof GenericType);
		} else {
			this->_data = realloc(nullptr,this->_size * sizeof GenericType);
		}
	} else {
		this->_data = malloc(this->_size * sizeof(GenericType));
	}
}

uint16_t Buffer::getSize()
{
	return this->_size;
}

template <class GenericType>
void Buffer::setData(GenericType* newData, const uint16_t newSize)
{
	if (size != this->_size) {
		this->resize(size, false);
	} 
	this->_data = data;
}

template <class GenericType>
GenericType * Buffer::getData()
{
	return this->_data;
}

template <class GenericType>
void Buffer::append(GenericType value) {
	GenericType *tmp = {value};
	this->append(tmp, 1);
	// this->resize(this->_size + 1,true);
	// this->_data[this->_size - 1] = value;
}

template <class GenericType>
void Buffer::append(GenericType *extraData, uint16_t extraSize) {
	this->resize(this->_size + extraSize,true);
	for(uint16_t i = 0; i < extraSize; i++) {
		this->_data[this->_size - extraSize + i] = extraData[i];
	}
}

template <class GenericType>
void Buffer::append(Buffer<GenericType> &extraBuffer) {
	this->append(extraBuffer->_data, extraBuffer->size);
}

template <class GenericType>
GenericType Buffer::operator[](const uint16_t index)
{
	if (index < this->_size) {
		return _data[index];
	} else {
		throw -1;
	}
}

template <class GenericType>
Buffer Buffer::operator+(const Buffer<GenericType> &other);
{
	Buffer temp = *this;
	temp.append(other);
	return temp;
}

template <class GenericType>
void Buffer::crop(const uint16_t index)
{
	this->resize(index, true);
}

template <class GenericType>
void Buffer::fill(const GenericType value)
{
	for(uint16_t i = 0; i < this->_size; i++) {
		this->_data[i] = value;
	}
}
