// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"

Array::Array (void)//:data_(), cur_size_(0), max_size_(0)
{ 
    //declare
    data_ = nullptr;
    cur_size_ = 0;
    max_size_ = 0;
}

Array::Array (size_t length)//: cur_size_(length), max_size_(length)
{
    cur_size_ = 0;
    max_size_ = length;
    ///char * data_[length];
    //todo initialize array
}

Array::Array (size_t length, char fill)//: cur_size_(length), max_size_(length)
{
    cur_size_ = length;
    max_size_ = length;
    ///char * data_ = new char [length] {fill};
    //todo intialize array and fill array
}


Array::Array (const Array & array)
{

}

Array::~Array (void)
{

}

const Array & Array::operator = (const Array & rhs)
{

}

char & Array::operator [] (size_t index)
{

}

const char & Array::operator [] (size_t index) const
{

}

char Array::get (size_t index) const
{
    return data_[index];
    //todo: throw an exception if its out of range below 0 or above max value

}

void Array::set (size_t index, char value)
{
    //setting the char value at the location index in the array data_
    data_[index] = value;
    // TODO: throw an exception if it is out of range
}

void Array::resize (size_t new_size)
{
    //destroy the array save values and add the values to a new array of size new_size
}

int Array::find (char ch) const
{

}

int Array::find (char ch, size_t start) const
{

}

bool Array::operator == (const Array & rhs) const
{

}

bool Array::operator != (const Array & rhs) const
{

}

void Array::fill (char ch)
{

}

void Array::shrink (void)
{
  
}

void Array::reverse (void)
{
  
}

Array Array::slice (size_t begin) const
{
  
}

Array Array::slice (size_t begin, size_t end) const
{
  
}