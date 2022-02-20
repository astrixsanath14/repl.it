#include <iostream>
#include <math.h>
using namespace std;

int getIndexOfMostSignificantBit(int val)
{
  if (val == 0)
    return 0;
  return (int)log2(val);
}

void printIndexOfMostSignificantBit(int val)
{
  cout << "Index of MSB of " << val << " is: " << getIndexOfMostSignificantBit(val) << endl;
}

int printAndgetIndexOfMostSignificantBit(int val)
{
  int msbIndexOfVal = getIndexOfMostSignificantBit(val);
  cout << "Index of MSB of " << val << " is: " << msbIndexOfVal << endl;
  return msbIndexOfVal;
}

int getNumberOfBits(int val)
{
  int msbIndexOfVal = printAndgetIndexOfMostSignificantBit(val);
  int noOfBits = msbIndexOfVal + 1;
  return noOfBits;
}

void printLeftShift(int val, int noOfTimes)
{
  cout << "Left shift of " << val << " for " << noOfTimes << " times: " << (val << noOfTimes) << endl;
}

string printBinaryRepresentationOfNegativeNumber(int val, string binaryRepresentation, int noOfBits)
{
  int i, carry = 1;
  string one(noOfBits, '0'), two(noOfBits, '0');

  for (i = 0; i < noOfBits; i++)
  {
    one[i] = '1' - binaryRepresentation[i] + '0';
  }
  string extraSpace(19, ' ');
  cout << "Binary number " << val << " is" << extraSpace << "\t\t" << binaryRepresentation << "\n";
  cout << "1's complement of binary number " << val << " is \t\t" << one << "\n";
  for (i = noOfBits - 1; i >= 0; i--)
  {
    if (one[i] == '1' && carry == 1)
    {
      two[i] = '0';
    }
    else if (one[i] == '0' && carry == 1)
    {
      two[i] = '1';
      carry = 0;
    }
    else
    {
      two[i] = one[i];
    }
  }
  cout << "2's complement of binary number " << val << " is \t\t" << two << "\n";
  return two;
}

string getBinaryRepresentation(int val, int noOfBits)
{
  bool isNegative = val < 0;
  val = isNegative ? -val : val;
  int firstBit = getIndexOfMostSignificantBit(val);
  string s = "";
  for (int i = 0; i < noOfBits - firstBit - 1; i++)
    s += "0";
  for (int i = 1 << firstBit; i > 0; i = i >> 1)
  {
    if (val & i)
      s += "1";
    else
      s += "0";
  }

  if (isNegative)
    return printBinaryRepresentationOfNegativeNumber(-val, s, noOfBits);
  else
    return s;
}

string printBinaryRepresentationOfNegativeNumber(int val)
{
  int noOfBits = getNumberOfBits(-val);
  string bitRep = getBinaryRepresentation(-val, noOfBits);
  return printBinaryRepresentationOfNegativeNumber(val, bitRep, noOfBits);
}

string printAndGetBinaryRepresentation(int val, int noOfBits)
{
  string s = getBinaryRepresentation(val, noOfBits);
  cout << "Binary representation of " << val << " is " << s << " (" << noOfBits << " bit representation)" << endl;
  return s;
}

string printAndGetBinaryRepresentation(int val)
{
  bool isNegative = val < 0;
  int msbIndexOfVal = printAndgetIndexOfMostSignificantBit(isNegative ? -val : val);
  int noOfBits = msbIndexOfVal + 1;
  return printAndGetBinaryRepresentation(val, noOfBits);
}

int printAndGetValueOfBitAtGivenIndex(int val, int bitIndex)
{
  int mask = 1 << bitIndex;
  int maskAppliedVal = val & mask;
  int bitVal = maskAppliedVal >> bitIndex;
  cout << "Value of bit at index: " << bitIndex << " for value " << val << " is: " << bitVal << endl;
  return bitVal;
}

void printAllBitsWithIndexNumber(int val)
{
  int msbIndexOfVal = printAndgetIndexOfMostSignificantBit(val);
  int noOfBits = msbIndexOfVal + 1;
  printAndGetBinaryRepresentation(val, noOfBits);
  for (int i = 0; i < noOfBits; i++)
  {
    printAndGetValueOfBitAtGivenIndex(val, i);
  }
  printLeftShift(1, msbIndexOfVal);
}

void setBitAndPrintVal(int val, int bitPos)
{
  cout << "-------------------" << endl;
  cout << "Going to set bit: " << bitPos << " in " << val << endl;
  cout << "\nBefore setting bit: " << endl;
  printAllBitsWithIndexNumber(val);
  int mask = 1 << (bitPos - 1);
  val = val | mask;
  cout << "\nAfter setting bit: " << endl;
  printAllBitsWithIndexNumber(val);
  cout << "-------------------" << endl;
}

void unsetBitAndPrintVal(int val, int bitPos)
{
  cout << "-------------------" << endl;
  cout << "Going to unset bit: " << bitPos << " in " << val << endl;
  cout << "\nBefore unsetting bit: " << endl;
  printAllBitsWithIndexNumber(val);
  int msbIndexOfVal = getIndexOfMostSignificantBit(val);
  int noOfBits = msbIndexOfVal + 1;
  int mask = (1 << (noOfBits)) - 1;
  mask = mask ^ (1 << (bitPos - 1));
  val = val & mask;
  cout << "\nAfter unsetting bit: " << endl;
  printAllBitsWithIndexNumber(val);
  cout << "-------------------" << endl;
}

void printFlippedBits(int val)
{
  cout << "-------------------" << endl;
  cout << "Going to flip bits in: " << val << endl;
  cout << "\nBefore flipping bits: " << endl;
  printAllBitsWithIndexNumber(val);
  int msbIndexOfVal = getIndexOfMostSignificantBit(val);
  int noOfBits = msbIndexOfVal + 1;
  int mask = (1 << (noOfBits)) - 1;
  val = val ^ mask;
  cout << "\nAfter flipping bit: " << endl;
  printAllBitsWithIndexNumber(val);
  cout << "-------------------" << endl;
}

bool checkIfBitIsSet(int val, int bitPos)
{
  return val & (1 << (bitPos - 1));
}

bool checkIfBitIsUnset(int val, int bitPos)
{
  return !checkIfBitIsSet(val, bitPos);
}

void printDivisibilityOf2(int val)
{
  cout << "Val: " << val << "\n";
  printAndGetBinaryRepresentation(val);
  cout << "-Val: " << -val << "\n";
  // printBinaryRepresentationOfNegativeNumber(-val);
  printAndGetBinaryRepresentation(-val);
  cout << "Val & -Val: " << (val & -val) << "\n";
  printAndGetBinaryRepresentation(val & -val);
  cout << "Val / (Val & -Val): " << val / (val & -val) << "\n";
  printAndGetBinaryRepresentation(val / (val & -val));
  cout << "\n";
}

int main()
{
  // printLeftShift(1, 0);
  // printLeftShift(1, 1);
  // printLeftShift(1, 10);

  // printIndexOfMostSignificantBit(0);
  // printIndexOfMostSignificantBit(1);
  // printIndexOfMostSignificantBit(2);
  // printIndexOfMostSignificantBit(3);
  // printIndexOfMostSignificantBit(4);
  // printIndexOfMostSignificantBit(8);

  // printAndGetBinaryRepresentation(5);
  // printAndGetBinaryRepresentation(123, 10);

  // printAllBitsWithIndexNumber(184);

  // setBitAndPrintVal(1, 5);

  // unsetBitAndPrintVal(63, 3);
  // unsetBitAndPrintVal(4095, 4);

  // printFlippedBits(75);

  // printAndGetBinaryRepresentation(38);
  // printAndGetBinaryRepresentation(25);
  // printAndGetBinaryRepresentation(10);

  printDivisibilityOf2(24);
  printDivisibilityOf2(22);
  printDivisibilityOf2(108);
  return 0;
}

/*
Summa/BitManipulationsTry.cpp
*/