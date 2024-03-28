Floating-point : https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html

Main differences between floating-point and fixed-point numbers:

1. Representation:

Floating-point numbers have a part for the sign, a part for the exponent, and a part for the mantissa (or significand). This allows them to represent very large and very small numbers, but with varying precision. They are called "floating-point" because the decimal point can "float" around (i.e., the numbers are represented in scientific notation).

Fixed-point numbers have a fixed number of digits before and after the decimal point. They can represent numbers within a certain range with a fixed precision. They are called "fixed-point" because the decimal point is in a fixed position.
In a fixed-point number system, the number of digits (or bits in the case of binary representation) is divided between the integer part and the fractional part. The position of the "binary point" is fixed, hence the name "fixed-point".

Let's consider a 16-bit fixed-point number as an example. The distribution of bits might look like this:

| Integer Part | Fractional Part |
|--------------|-----------------|
| 8 bits       | 8 bits          |

In this case, 8 bits are used for the integer part and 8 bits for the fractional part. This allows you to represent numbers from -128 to 127 with a precision of 1/256 (since 2^8 = 256).

The exact distribution of bits between the integer and fractional parts can vary depending on the specific requirements of your application. If you need to represent larger numbers, you can use more bits for the integer part. If you need more precision, you can use more bits for the fractional part.

Note that the sign of the number is typically represented by the most significant bit (MSB) of the integer part, so the range of the integer part is actually from -2^(N-1) to 2^(N-1) - 1, where N is the number of bits in the integer part.

2. Precision and Range:

Floating-point numbers can represent a very wide range of values (both very large and very small), but the precision of the representation can vary. For numbers with a large absolute value, the precision can be quite low.

Fixed-point numbers have a fixed precision, but a limited range. They can represent numbers within a certain range with a fixed number of decimal places. The range and precision are determined by the number of bits used for the integer and fractional parts.

3. Performance:

Floating-point operations can be slower than fixed-point operations, especially on hardware without a floating-point unit (FPU). However, many modern CPUs have an FPU that can perform floating-point operations quickly.

Fixed-point operations can be faster than floating-point operations, especially on hardware without an FPU. Fixed-point operations are essentially integer operations, which are usually faster than floating-point operations.

4. Usage:

Floating-point numbers are used when the range of values is large or unpredictable, and when the exact precision of each operation is not critical. They are commonly used in scientific calculations, graphics, and machine learning.

Fixed-point numbers are used when the range of values is known and limited, and when a certain precision is required. They are commonly used in financial calculations, signal processing, and embedded systems.