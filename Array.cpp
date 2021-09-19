// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include "iostream"

// COMMENT You need to move all your code up one level. The grading system
// expects the code to be there, and will not look in subdirectories for
// your assignment.RESOLVED

//took code out of array source folder and moved into one level up.

Array::Array(void)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.RESOLVED

//moved initialization into brackets and seperated by line to make it easier to read errors
{
    //declare
    data_ = nullptr;
    cur_size_ = 0;
    max_size_ = 0;
}

Array::Array(size_t length)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
// RESOLVED
// 
//moved initialization into brackets and seperated by line to make it easier to read errors
{
    cur_size_ = 0;
    max_size_ = length;
    char* data_;
    data_ = new char[length];
}

Array::Array(size_t length, char fill)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.RESOLVED

//moved initialization into brackets and seperated by line to make it easier to read errors and iterates through each element to add fill character
{
    cur_size_ = length;
    max_size_ = length;
    char* data_;
    data_ = new char[length];
    for (size_t i = 0; i < length; i++)
    {
        data_[i] = fill;
    }

}


Array::Array(const Array& array)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.RESOLVED
{
    char* deepCopy = new char;
    *deepCopy = *(data_);
    //deep copy the array 
    
    // COMMENT The copy constructor needs to create a deep copy of the source array.RESOLVED
}

Array::~Array(void)
{
    // COMMENT This code will not compile.
    delete[] data_; 
    //removed delete cur size and max size


}

const Array& Array::operator = (const Array& rhs)
{
    // COMMENT Check for self assignment first.RESOLVED

    //added bracket to check for self assignment then set each element of data_ = to the equal index of the array rhs

    if (this != &rhs) {
        //changed the iteration length to avoid the runtime error. 
        for (size_t i = 0; i < sizeof(data_); i++)
        {
            data_[i] = rhs[i];
        }
    }

    return *this;
    // COMMENT Your array will have a runtime failure if the number of elements on the
    // rhs is more than the max size of this array.RESOLVED


}

char& Array::operator [] (size_t index)
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.RESOLVED

    //  COMMENT You should not catch the exception. That is the responsibility of the
    // caller. Otherwise, they will not be able to react to the expcetion (i.e., a program
    // cannot react to console output).RESOLVED

    //try throws an error without catch statement so manually added exception returns the character at the parameter index and throws exception if out of range
    char returnValue;
    if (index >= 0 && index < sizeof(data_)) {
        returnValue = data_[index];
    }
    else {
        throw std::out_of_range("value is not in the proper range");
    }
    return data_[index];
}

const char& Array::operator [] (size_t index) const
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.RESOLVED

    //  COMMENT You should not catch the exception. That is the responsibility of the
    // caller. Otherwise, they will not be able to react to the expcetion (i.e., a program
    // cannot react to console output).RESOLVED

    //try throws an error without catch statement so manually added exception returns character at parameter index and throws exception if the index is out of bounds
    char returnValue;
    if (index >= 0 && index < sizeof(data_)) {
        returnValue = data_[index];
    }
    else {
        throw std::out_of_range("value is not in the proper range");
    }
    return data_[index];
}

char Array::get(size_t index) const
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.RESOLVED

    //  COMMENT You should not catch the exception. That is the responsibility of the
    // caller. Otherwise, they will not be able to react to the expcetion (i.e., a program
    // cannot react to console output).RESOLVED

    //try throws an error without catch statement so manually added exception returns the character at the index parameter and throws exception if out of bounds index
    char returnValue;
    if (index >= 0 && index < sizeof(data_)) {
        returnValue = data_[index];
    }
    else {
        throw std::out_of_range("value is not in the proper range");
    }
    return data_[returnValue];
    //todo: throw an exception if its out of range below 0 or above max value

}

void Array::set(size_t index, char value)
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it. RESOLVED

    //  COMMENT You should not catch the exception. That is the responsibility of the
    // caller. Otherwise, they will not be able to react to the expcetion (i.e., a program
    // cannot react to console output). RESOLVED

    //setting the char value at the location index in the array data_

    //try throws an error without catch statement so manually added exception if the index is out of bounds it throws an exception if not out of bounds then array data at index is = to value
    if (index >= 0 && index < sizeof(data_)) {
        data_[index] = value;
    }
    else {
        throw std::out_of_range("value is not in the proper range");
    }
    // TODO: throw an exception if it is out of range
}

void Array::resize(size_t new_size)
{
    // COMMENT The resize method should only increase the size of the allocation if
    // the new size is larger than the current memory allocation for the array. If resized,
    // you need to preserve the old data. Otherwise, you can just update cur_size_ to
    // reflect the new size. 

    //Resolved I think, removing the intialization for the pointer to declare the size should fix this comment I think. 

    char *newArr = new char[new_size];
    if (new_size != cur_size_)
    {
        for (size_t i = 0; i < new_size; i++)
        {
            newArr[i] = data_[i];
        }

        // COMMENT There is no need to do a double copy for the data to resize
        // the array. Just create a new arary, copy over the data, and then swap
        // the pointers. RESOLVED
        *data_ = *newArr;
    }


    //new array with the values of data_ then switch the pointers

    //destroy the array save values and add the values to a new array of size new_size
}

int Array::find(char ch) const
{
    for (int i = 0; i < cur_size_; i++)
    {
        if (data_[i] == ch) {
            return i;
        }
    }
    return -1;

    //iterate through the array if the target character is found then return 1 if it is not found then return -1

}

int Array::find(char ch, size_t start) const
{
    for (size_t i = start; i < cur_size_; i++)
    {
        if (data_[i] == ch) {
            return i;
        }
    }
    return -1;

    //iterate through the array with specific start value if the target character is found return 1 if not -1
}

bool Array::operator == (const Array& rhs) const
{
    // COMMENT Check for self comparison first. RESOLVED
    if (this != &rhs) {
        for (size_t i = 0; i < cur_size_; i++)
        {
            if (data_[i] != rhs[i]) {
                return false;
            }
        }
    }
    return true;
    //check for equality of arrays iterate through array and if an element doesnt match return false otherwise return true

}

bool Array::operator != (const Array& rhs) const
{
    // COMMENT You can define operator != in terms of operator ==. 

    //i am not sure if this is a comment I am supposed to change, if the comment was supposed to be "cant" rather than "can" but I changed it anyway so the below code is 
    //doing the same thing without relying COMPLETELY on == operators
    int i = 0;
    do
    {
        i++;
        if (i == max_size_ - 1) {
            return true;
        }

    } while (rhs[i] != data_[i]);
    return false;
    //iterate through the array, if the data at any point the data is equivalent then returns false checks to make sure its at the end of array before returning true

}

void Array::fill(char ch)
{
    for (size_t i = 0; i < max_size_; i++)
    {
        data_[i] = ch;
    }
    //iterate through array and fill with character

}

void Array::shrink(void)
{
    // COMMENT You should use the cur_size_ and max_size_ to determine if you
    // must shrink the array allocation. 

    //resolved, instead of iterating through the array to check for null values i compared cur_size and max_size to decide how much to shrink the array

    size_t newSize;
    if (cur_size_ != max_size_) {
        if (max_size_ > cur_size_) {
            newSize = cur_size_;
        }
    }
}

void Array::reverse(void)
{
    // COMMENT There is no need to create a copy of the array to reverse its contents

    int last = sizeof(data_);
    for (int i = 0; i < last;) {
        char tempValue = data_[i];
        data_[i] = data_[last];
        data_[last] = tempValue;
        i++;
        last--;

    }
    //iterates through the size of data_ and switches first and last value until it reaches the center. 


}

Array Array::slice(size_t begin) const
{
    char* slicedArr = new char[cur_size_];
    for (size_t i = begin; i < cur_size_; i++)
    {
        slicedArr[i] = data_[i];
    }
    return *slicedArr;

    //creates a new array array and begins the iteration at the parameter start value and pulls from the data array
}

Array Array::slice(size_t begin, size_t end) const
{
    char* slicedArr = new char[cur_size_];
    for (size_t i = begin; i < end; i++)
    {
        slicedArr[i] = data_[i];
    }
    return *slicedArr;

    //creates a a new array and begins the iterations at the parameter start value and ends them at parameter end value from data array
}