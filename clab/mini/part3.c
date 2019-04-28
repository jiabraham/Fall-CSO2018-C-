#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// initialize_array is given an array "arr" of "n" elements.
// It initializes the array by setting all elements to be "true" (any non-zero value).
void
initialize_array(int *arr, int n)
{
	// TODO: Your code here.
	//for loop goes through all elements of array and sets them to 1
	for (int i = 0; i < n; i++) {
			*(arr + i) = 1;
	}
}

// mark_multiples is given an array "arr" of size n and a (prime) number "p" less than "n" 
// It assigns "false" (the zero value) to elements at array indexes 2*p, 3*p, 4*p,.., x*p (where x*p <= n-1)
// For example, given arr=[1, 1, 1, 1, 1, 1], n = 6  and p = 2
// mark_multiples set arr=[1, 1, 1, 1, 0, 1]
void
mark_multiples(int *arr, int n, int p) 
{
	// TODO: Your code here.
	//Traverses array onward from element 2
	for (int i = 2; i < n; i++) {
		//checks if the product of the index and the prime is less than amount of elements
		if (i * p < n) {
			*(arr + i * p) = 0;
		} else {
			break;
		}
	}
}

// prime_number_sieves finds all prime numbers less than n by constructing a "sieve of Eratosthenes"
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// A pre-allocated, un-initialized, array "arr" of "n" elements is passed to the function 
// When the function returns, the element at index i of "arr" should be "true" (any non-zero value) if i is a prime, 
// and "false" (the zero value) if i is a composite number
// You need not care about the values of the 0-th and 1-st elements.
// You are expected to use the previous two functions, initialize_array and mark_multiples
// 
// For example, given arr with n=6, the resulting sieve should be arr=[*, *, 1, 1, 0, 1] 
// "*" means the corresponding element can be either 0 or 1. The seive at indexes 2,3,5 are marked "1" 
// because 2,3,5 are primes
void
prime_number_sieves(int *arr, int n)
{
	// TODO: Your code here
	//Initializes array filled with 1's
	initialize_array(arr, n);
	//loop to hit all possible composite numbers under the n
	for (int i = 2; i < n; i++) {
		mark_multiples(arr, n, i);
	}
}

/* find_smallest_divisor finds the smallest prime divisor (>1) of "n". It assigns the value 
 * of the smallest divisor to the integer variable pointed to by "divisor".  
 * If "n" is composite, the function returns true.  Otherwise (i.e. "n" is a prime number), 
 * the function returns false.  For example, in the following code snippet:
 int d;
 ret = find_smallest_divisor(21, &d)
 //ret should contains "true" and d should be 3

 You are expected to first use prime_number_sieves to first find all primes smaller than n. 
 Then, test if any prime found by prime_number_sieves divide n and return the smallest one.
 Note that you'll need to allocate the integer array to pass to prime_number_sieves.
*/
int
find_smallest_divisor(int n, int *divisor)
{
	// TODO: Your code here
	//Allocate array
	int arraysize = n + 1;
	int *sieve = malloc(sizeof(int)* arraysize);

	//Call to prime number sieves to determine prime numbers less than n
	prime_number_sieves(sieve, arraysize);

	//Loop to see if any of the prime numbers are will evenly divide into n

	for (int i = 2; i < n; i++) {

			if (sieve[i] == 1 && n % i == 0) {
				*divisor = i;
				break;
				
			}
	}
	if (sieve[n] == 0)
		return 1;	
	return 0;
}




