#include <iostream>
#include <stdlib.h>

using namespace std;


void print(int values[], int length)
{
  for (int i = 0; i < length; i++)
  {
    cout << "V [" << i <<"] : " << values[i] << endl;
  }
}

void insertion_sort(int values[], int n)
{
  if (n <= 1)
  {
    return;
  }

  insertion_sort(values, n - 1);

  int last = values[n - 1];
  int i = n - 2;

  while (last < values[i] && i >= 0)
  {
    values[i + 1] = values[i];
    i--;
  }

  values[i + 1] = last;
}

int main(int argc, char **argv)
{
  int values[] = {4,3,2,10,12,1,5,6};
  int num_of_elements = sizeof(values) / sizeof(int);

  print(values, num_of_elements);
  cout << "---------------------" << endl;  
  insertion_sort(values, num_of_elements);

  print(values, num_of_elements);



  return 0;
}