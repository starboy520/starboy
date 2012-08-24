// Given an unsorted array that contains even number of occurrences
// wfor all number excepet two numbers.
// Find the two number wich have odd occurrence in O(n) time complexity
// and O(1) extra space

// Odd: 
// Even: 偶数 
// Input {12, 23, 34, 12, 12, 23, 12, 45}
// OutPut 34, 45
//
// Solution:
//


void printTwoOdd(int* array, int size) {
  int xor2 = array[0];
  int set_bit_no;
  int i;
  int n = size - 2;
  
  for (int i = 1; i < size; i++) {
    xor2 = xor2^ array[i];
  }

  set_bit_no = xor2 & ~(xor2 - 1);

  for (int i = 0; i < size; i++) {
    if (array[i] & set_bit_no)
      x = x ^ array[i];
    else 
      y = y ^ array[i];
  }

  // printf x, y
  return 0;
}

