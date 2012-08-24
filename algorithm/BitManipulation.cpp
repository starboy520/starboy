// Given an integer, 
// 1: print the next smaller and next larger number
// that have the same number of 1 bits in their binary representation


int greater(int num) {
  int lastSetBit = num & ~(num-1);
  int largerNum = num + lastSetBit;

  int fb = num^largerNum;
  int lastBit = fb/lastSetBit;
  lastSetBit >>= 2;
  largerNum |= lastSetBit;
  return largerNum;
}
