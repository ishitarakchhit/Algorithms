/*
PROBLEM STATEMENT:
Given an integer n, return the number of prime numbers that are strictly less than n.
 
Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:
Input: n = 0
Output: 0
Example 3:
Input: n = 1
Output: 0
 
Constraints:
0 <= n <= 5 * 106
*/



/* 
Approach: Sieve of eratosthenes
Consider a boolean array with indices representing the numbers. Mark all the numbers to be primes by storing the value 1/true. Then mark 0 and 1 to be non primes. Start from the number 2 and mark all its multiples non primes. Move to the next number (if it is marked prime) and carry forward the same procedure until you traverse all the numbers till the given limit.
Time Complexity: O(n loglogn)
*/

#include <bits/stdc++.h>
using namespace std;
//function for counting all primes using sieve algorithm
    int countPrimes(int n) {
        vector<bool> prime(n+1, 1);
        prime[0]= prime[1]=0;                    //marking 0 and 1 non primes

        int count =0;                            //counting all the primes while traversing the numbers
        for(int i=2; i<n; i++){                  //loop to traverse all the numbers till n
            if(prime[i]){
                count++;

                for(int j= i*2; j<n; j= j+i){    //marking all multiples of a prime no. as non prime
                    prime[j]= 0;
                }
            }
        }
        return count;
    }

//main function
    int main(){
        int num;
        cout<<"Enter the number";
        cin>>num;
        
        cout<<"Total number of primes less than "<<num<<"are: "<<countPrimes(num);
  
        return 0;
    }
