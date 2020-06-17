# BigInteger-Class-in-C-
various methods which can be used with BigInteger Object  
1> **BigInteger()**  
&nbsp;&nbsp;&nbsp;default constructor: it intializes the BigInteger to 0  
2> **BigInteger(string s)**	// parametrized constructor: it intializes the BigInteger with string passed as parameter  
3> **string getBigInteger()** // it returns BigInteger as string  
4> **int size()**				// returns size of the BigInteger  
5> **void putBigInteger(string s)** // it intializes the BigInteger with string passed as parameter  
6> **void copyBigInteger(BigInteger B)** // it copies the BigInteger passed as argument to the BigInteger calling the method  
7> **BigInteger addBigInteger(BigInteger B)** // it returns BigInteger which is sum of the BigInteger which calls the addBigInteger() function and the BigInteger which is passed as argument  
8> **BigInteger subtractBigInteger(BigInteger B)** //  it returns BigInteger which is diiference of the BigInteger which calls the subtractBigInteger() function and the BigInteger which is passed as argument  
9> **BigInteger absolute()** // it returns the absolute BigInteger i.e a BigInteger without any +ve or -ve sign  
10> **BigInteger multiplyBigInteger(BigInteger B)** // it returns the product as BigInteger of two BigIntegers  
11> **BigInteger removeTrailingZeros()** // it returns the BigInteger in which all the leading zeros are removed  
12> **char signInChar()**		// it returns the sign of BigInteger + for plus and - for minus  
13> **int signInInt()** 	// it returns the sign of BigInteger 1 for plus and 0 for minus  
14> **int lessThan(BigInteger B)** // it returns 1 (true) if BigInteger which is calling the lessThan() method is less than the BigInteger which is passed as argument.  
15> **int isEqual(BigInteger B)**	// it returns 1 (true) if two BigIntegers are equal else it returns 0 (false)  
16> **int isZero()**	// it returns 1 (true) if BigInteger represents 0  
17> **BigInteger divideBigInteger(BigInteger B)** // it returns the quotient of divison ( BigInteger which has called the function / BigInteger which is passed as argument )  
18> **BigInteger modulusBigInteger(BigInteger B)** // it returns the modulus of divison ( BigInteger which has called the function / BigInteger which is passed as argument )  
19> **BigInteger maxBigInteger(BigInteger A,BigInteger B)** // it returns the BigInteger which is maximum of the two ( BigInterger which has called the function and the BigInteger which is passed as argument )  
20> **BigInteger minBigInteger(BigInteger A,BigInteger B)** // it returns the BigInteger which is minimum of the two ( BigInterger which has called the function and the BigInteger which is passed as argument )  
