/*
 * Implementation of rational number type
 * CSE 374 HW7, Wi13
 */

/*
 * Yosef Habte
 * CSE 374 HW7, Wi13
 * 03/11/2014
 * Implementation of rational number type
 */
 
#include "rational.h"
#include "stdio.h"
#include "stdlib.h"
 
/* greatest common divisor helper functions */
int gcd(int a, int b);
Rational gcd_return(Rational* other);
 
/* replace this line with your implementation of the Rational type */
 
// constructors:
 
// Construct Rational 0/1
Rational::Rational()
{
    this->num = 0;
    this->denom = 1;
}
 
// Construct Rational n/1
Rational::Rational(int n)
{
    this->num = n;
    this->denom = 1;
}
 
// Construct Rational n/d
Rational::Rational(int n, int d)
{
    int i;
    i = gcd(n, d);
    this->num = n/i;
    this->denom = d/i;
}
 
// accessors: return the numerator and denominator of this Rational.
// Results are in lowest terms (i.e., for rational r, r.n() and r.d()
// have no common integer divisors greater than 1).
int Rational::n()
{
    return this->num;
}
int Rational::d()
{
    return this->denom;
}
 
// arithmetic: return a new Rational that results from combining
// this Rational with another.  Neither operand is changed.
 
// = this + other
Rational Rational::plus(Rational other)
{
    Rational temp;
    temp.num = num*other.denom + denom*other.num;
    temp.denom = denom*other.denom;
 
    temp = gcd_return(&temp);
 
    return temp;
}
 
// = this - other
Rational Rational::minus(Rational other)
{
    Rational temp;
    temp.num = num*other.denom - denom*other.num;
    temp.denom = denom*other.denom;
 
    temp = gcd_return(&temp);
 
    return temp;
}
 
// = this * other
Rational Rational::times(Rational other)
{
    Rational temp;
    temp.num = num*other.num;
    temp.denom = denom*other.denom;
 
    temp = gcd_return(&temp);
 
    return temp;
}
 
// = this / other
Rational Rational::div(Rational other)
{
    Rational temp;
    temp.num = num*other.denom;
    temp.denom = denom*other.num;
 
    temp = gcd_return(&temp);
 
    return temp;
}
 
/* This function takes in a pointer to a Rational object and returns it reformatted. */
Rational gcd_return(Rational* other)
{
    Rational temp;
    temp = *other;
 
    int num;
    int denom;
 
    int i;
    i = gcd(temp.n(), temp.d());
    num = temp.n()/i;
    denom = temp.d()/i;
 
    if(denom < 0)
    {
        num = num*(-1);
        denom = denom*(-1);
    }
 
    return Rational(num, denom);
}
 
/* This function takes in two numbers and returns the greatest common divisor. */
int gcd(int num, int denom)
{
    int a = num;
    int b = denom;
    if(num < 0)
    {
        a = a*(-1);
    }
    if(denom < 0)
    {
        b = b*(-1);
    }
    int c;
    while (a != 0)
    {
        c = a;
        a = b%a;
        b = c;
    }
    return b;
}