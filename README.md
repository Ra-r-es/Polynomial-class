# Polynom Class

The `Polynom` class represents a polynomial and provides various methods for polynomial manipulation. This class allows users to create, modify, and perform operations on polynomials.

## Overview

- **Constructor**: The class provides multiple constructors to create polynomials.
- **Destructor**: Proper memory management is ensured with the destructor.
- **Getter and Setter**: Methods to get and set the degree and coefficients of the polynomial.
- **Display**: Display the polynomial in a readable format.
- **Arithmetic Operations**: Supports addition, subtraction, and multiplication of polynomials.
- **Apply Transformation**: Apply a transformation to the polynomial.
- **Bonus Features**: Additional functionalities such as squaring the polynomial and overloaded operators are included.

## Usage

### Creating a Polynomial

```cpp
// Create a polynomial with default values (degree = 1, coefficients = {0, 1})
Polynom p1;

// Create a polynomial of a specific degree
Polynom p2(3);

// Create a polynomial with specified coefficients
double coef[] = {1, 2, 3, 4};
Polynom p3(3, coef);
