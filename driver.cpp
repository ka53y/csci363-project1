#include "Array.h"
#include "iostream"

void printArr(int index, Array *arr) {
	arr->get(index);
}
int main (int argc, char * argv [])
{
  // TODO Add code here to test your Array class.
  Array* array1 = new Array(5);
  Array* newA = new Array(9, 'a');
  Array* temp = new Array(9, 'a');
  Array* cop = new Array(*temp);
  array1->set(0, 'a');
  array1->set(1, 'b');
  array1->get(0);
  array1->get(1);
  array1->resize(1);
  array1->resize(6);
  //temp->slice(3);
  //newA->slice(2, 4);
  
  array1->fill('a');
  array1->set(1, 'b');
  array1->find('b');
  array1->set(3, 'b');
  array1->find('b', 2);
  array1->get(3);
  std::cout << "==============" << std::endl;
  std::cout << array1->size() << std::endl;
  for (size_t i = 0; i < array1->size(); i++)
  {
	  printArr(i, array1);
  }
  array1->shrink();
  for (size_t i = 0; i < array1->size(); i++)
  {
	  printArr(i, array1);
  }
  array1->reverse();
  for (size_t i = 0; i < array1->size(); i++)
  {
	  printArr(i, array1);
  }
  return 0;


}
