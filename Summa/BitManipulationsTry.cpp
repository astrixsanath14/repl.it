#include<iostream>
#include<math.h>
using namespace std;

int getIndexOfMostSignificantBit(int val)
{
  if(val==0)
    return 0;
  return (int)log2(val);
}

void printIndexOfMostSignificantBit(int val)
{
  cout<<"Index of MSB of "<<val<<" is: "<<getIndexOfMostSignificantBit(val)<<endl;
}

int printAndgetIndexOfMostSignificantBit(int val)
{
  int msbIndexOfVal = getIndexOfMostSignificantBit(val);
  cout<<"Index of MSB of "<<val<<" is: "<<msbIndexOfVal<<endl;
  return msbIndexOfVal;
}

void printLeftShift(int val, int noOfTimes)
{
  cout<<"Left shift of "<<val<<" for " << noOfTimes <<" times: "<<(val<<noOfTimes)<<endl;
}

string printBinaryRepresentation(int val, int noOfBits) {
  int firstBit = getIndexOfMostSignificantBit(val);
  string s = "";
  for(int i=0;i<noOfBits-firstBit-1;i++)
    s+="0";
  for (int i = 1 << firstBit; i > 0; i = i>>1)
  {
    if(val & i)
      s+="1";
    else
      s+="0";
  }
  cout<<"Binary representation of "<< val<<" is "<<s<<" ("<<noOfBits<<" bit representation)"<<endl;
  return s;
}

string printBinaryRepresentation(int val) {
  int msbIndexOfVal = printAndgetIndexOfMostSignificantBit(val);
  int noOfBits = msbIndexOfVal + 1;
  return printBinaryRepresentation(val, noOfBits);
}


int printAndGetValueOfBitAtGivenIndex(int val, int bitIndex)
{
  int mask = 1 << bitIndex;
  int maskAppliedVal = val & mask;
  int bitVal = maskAppliedVal >> bitIndex;
  cout<<"Value of bit at index: "<<bitIndex<<" for value "<< val<<" is: "<<bitVal<<endl;
  return bitVal;
}

void printAllBitsWithIndexNumber(int val)
{
  int msbIndexOfVal = printAndgetIndexOfMostSignificantBit(val);
  int noOfBits = msbIndexOfVal + 1;
  printBinaryRepresentation(val, noOfBits);
  for(int i=0;i<noOfBits;i++)
  {
    printAndGetValueOfBitAtGivenIndex(val, i);
  }
  printLeftShift(1, msbIndexOfVal);
}

void setBitAndPrintVal(int val, int bitPos)
{
  cout<<"-------------------"<<endl;
  cout<<"Going to set bit: " << bitPos << " in " << val<<endl;
  cout<<"\nBefore setting bit: "<<endl;
  printAllBitsWithIndexNumber(val);
  int mask = 1 << (bitPos - 1);
  val = val | mask;
  cout<<"\nAfter setting bit: "<<endl;
  printAllBitsWithIndexNumber(val);
  cout<<"-------------------"<<endl;
}

void unsetBitAndPrintVal(int val, int bitPos)
{
  cout<<"-------------------"<<endl;
  cout<<"Going to unset bit: " << bitPos << " in " << val<<endl;
  cout<<"\nBefore unsetting bit: "<<endl;
  printAllBitsWithIndexNumber(val);
  int msbIndexOfVal = getIndexOfMostSignificantBit(val);
  int noOfBits = msbIndexOfVal + 1;
  int mask = (1 << (noOfBits)) - 1;
  mask = mask ^ (1<<(bitPos-1));
  val = val & mask;
  cout<<"\nAfter unsetting bit: "<<endl;
  printAllBitsWithIndexNumber(val);
  cout<<"-------------------"<<endl;
}

void printFlippedBits(int val)
{
  cout<<"-------------------"<<endl;
  cout<<"Going to flip bits in: " << val<<endl;
  cout<<"\nBefore flipping bits: "<<endl;
  printAllBitsWithIndexNumber(val);
  int msbIndexOfVal = getIndexOfMostSignificantBit(val);
  int noOfBits = msbIndexOfVal + 1;
  int mask = (1 << (noOfBits)) - 1;
  val = val ^ mask;
  cout<<"\nAfter flipping bit: "<<endl;
  printAllBitsWithIndexNumber(val);
  cout<<"-------------------"<<endl;
}

bool checkIfBitIsSet(int val, int bitPos)
{
  return val&(1<<(bitPos - 1));
}

bool checkIfBitIsUnset(int val, int bitPos)
{
  return !checkIfBitIsSet(val, bitPos);
}

int main()
{
  printLeftShift(1, 0);
  printLeftShift(1, 1);
  printLeftShift(1, 10);
  printIndexOfMostSignificantBit(0);
  printIndexOfMostSignificantBit(1);
  printIndexOfMostSignificantBit(2);
  printIndexOfMostSignificantBit(3);
  printIndexOfMostSignificantBit(4);
  printIndexOfMostSignificantBit(8);
  printBinaryRepresentation(5);
  printBinaryRepresentation(123, 10);
  
  int val = 184;
  printAllBitsWithIndexNumber(val);

  setBitAndPrintVal(1, 5);
  unsetBitAndPrintVal(63, 3);
  unsetBitAndPrintVal(4095, 4);
  printFlippedBits(75);
  return 0;
}

/*
Summa/BitManipulationsTry.cpp
*/