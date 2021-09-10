// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include "iostream"

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
    char* arrData;
    arrData = new char[length];
}

Array::Array (size_t length, char fill)//: cur_size_(length), max_size_(length)
{
    cur_size_ = length;
    max_size_ = length;
    ///char * data_ = new char [length] {fill};
    //todo intialize array and fill array
    char* arrData;
    arrData = new char[length];
    for (size_t i = 0; i < length; i++)
    {
        arrData[i] = fill;
    }
    
}


Array::Array (const Array & array)
{
 
}

Array::~Array (void)
{

}

const Array & Array::operator = (const Array & rhs)
{
   for (size_t i = 0; i < cur_size_; i++)
   {
       data_[i] = rhs[i];
   }
   
}

char & Array::operator [] (size_t index)
{
   char returnValue;
   try
   {
       returnValue = data_[index];
   }
   catch(const std::exception& e)
   {
       std::cerr << e.what() << '\n';
   }
   return returnValue;
}

const char & Array::operator [] (size_t index) const
{

}

char Array::get (size_t index) const
{
    try
    {
        data_[index] = "x";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return data_[index];
    //todo: throw an exception if its out of range below 0 or above max value

}

void Array::set (size_t index, char value)
{
    //setting the char value at the location index in the array data_
    try
    {
        data_[index] = 10;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    data_[index] = value;
    // TODO: throw an exception if it is out of range
}

void Array::resize (size_t new_size)
{
    char newArr[new_size];
    for (size_t i = 0; i < new_size; i++)
    {
        newArr[i] = data_[i];
    }

    
    //destroy the array save values and add the values to a new array of size new_size
}

int Array::find (char ch) const
{
    for (size_t i = 0; i < cur_size_; i++)
    {
        if(data_[i] == ch){
            return i;
        }
    }
    return -1;
    
}

int Array::find (char ch, size_t start) const
{
    for (size_t i = start; i < cur_size_; i++)
    {
        if(data_[i] == ch){
            return i;
        }
    }
    return -1;
}

bool Array::operator == (const Array & rhs) const
{
    for (size_t i = 0; i < cur_size_; i++)
    {
        if(data_[i] != rhs[i]){
            return false;
        }
    }
    return true;
    
}

bool Array::operator != (const Array & rhs) const
{
    size_t i = 0;

    do{
        i++;
    } while(rhs[i] == data_[i]);

    if(i == max_size_){
        return false;
    } else{
        return true;
    }
    
}

void Array::fill (char ch)
{
    for (size_t i = 0; i < max_size_; i++)
    {
        data_[i] = ch;
    }
    
}

void Array::shrink (void)
{
  size_t newSize;
  for (size_t i = 0; i < cur_size_; i++)
  {
      if(data_[i] == NULL){
          newSize++;
      }
  }
  newSize = cur_size_ - newSize;
}

void Array::reverse (void)
{
  char tempdata[cur_size_];
  for (size_t i = cur_size_; i > 0; i--)
  {
      tempdata[i] = data_[i];
  }
  for (size_t i = 0; i < cur_size_; i++)
  {
      data_[i] = tempdata[i];
  }
  
   
}

Array Array::slice (size_t begin) const
{
  char slicedArr[cur_size_];
  char *pArr = slicedArr;
  for (size_t i = begin; i < cur_size_; i++)
  {
      slicedArr[i] = data_[i];
  }
  return pArr;
  
}

Array Array::slice (size_t begin, size_t end) const
{
  char * slicedArr = new char[cur_size_];
  for (size_t i = begin; i < end; i++)
  {
      slicedArr[i] = data_[i];
  }
  return slicedArr;
}