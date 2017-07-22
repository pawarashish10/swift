# swift
Swift_aplication_rest

Software, Product, and Embedded Engineering Candidates
In the programming language of your choice, write a program generating the first n Fibonacci numbers F(n), printing

- "Buzz" when F(n) is divisible by 3.

- "Fizz" when F(n) is divisible by 5.

- "FizzBuzz" when F(n) is divisible by 15.

- "BuzzFizz" when F(n) is prime.

- the value F(n) otherwise.

Two versions of program are uploaded one need GMP libraries another dont need any but it fails to detect prime number.

version 1:- Swift_code challenge_without_GMP.c-->(calculate and check fibonecci upto 500 digit but doesn't work for prime number)

version 2:- Swift_Code_challange_using_GMP.c-->(Works fine for all test cases, please check attached test cases file)

Program needs GMP libraries to run.

To install GMP libraries on your Machine Follow instructions 
 step 1:
    Download "gmp-6.1.2.tar.xz" from https://gmplib.org/
 step 2:
    Unzip this file
 step 3:
  GMP has an autoconf/automake/libtool based configuration system. On a Unix-like system a basic build can be done with
  run following highlighted commands 
    >./configure 
    >make
  Some self-tests can be run with
    >make check
  And you can install (under /usr/local by default) with
    >make install


Install gmp libraries and you are ready to go....

 
