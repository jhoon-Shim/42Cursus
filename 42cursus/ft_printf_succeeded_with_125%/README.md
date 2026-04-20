*This project has been created as part of the 42 curriculum by jshim.*

## 1. Overview
The `ft_printf` project is a fundamental exercise in C programming that requires recreating the behavior of the standard library's `printf()` function. It explores the use of variadic arguments and complex string formatting, which are crucial for building versatile tools in C.

## 2. Supported Conversions
The function handles the following conversion specifiers from the standard `printf()`:
* **%c**: Prints a single character.
* **%s**: Prints a string.
* **%p**: Prints a void pointer in hexadecimal format.
* **%d / %i**: Prints a signed decimal (base 10) integer.
* **%u**: Prints an unsigned decimal (base 10) number.
* **%x / %X**: Prints a number in hexadecimal (base 16) lowercase or uppercase.
* **%%**: Prints a literal percent sign.

## 3. Bonus Features (Full Implementation)
This library manages the following flags and field width combinations to match the original function's versatility :
* **- (Minus)**: Left-aligns the output within the specified field width.
* **0 (Zero)**: Pads the field with zeros instead of spaces.
* **. (Precision)**: Specifies the minimum number of digits for integers or maximum length for strings.
* **# (Hash)**: Prepends `0x` or `0X` to non-zero hexadecimal outputs.
* **+ (Plus)**: Always prints a sign (+ or -) for signed numbers.
* **' ' (Space)**: Adds a blank space before a positive number if no sign is printed.

## 4. Technical Architecture
### Data Structure
A dedicated struct `t_format` is used to store and pass flag states during the parsing process, ensuring clean and maintainable logic.
```c
typedef struct s_format {
    int minus;     // Left-alignment
    int zero;      // Zero-padding
    int hash;      // Alternate form (#)
    int space;     // Space flag
    int plus;      // Sign flag (+)
    int width;     // Minimum width
    int precision; // Precision (-1 if unset)
    char specifier; // Conversion type
} t_format;
```
### Logic flow
1. **Parser**: Iterates through the input string, collecting flags and widths into the struct when a % is found.
2. **Dispatcher**: Calls specific print functions (e.g., print_int, print_hex) based on the specifier.
3. **Formatter**: Applies the stored flags to calculate padding and prefixes before outputting the final result.

### Flag & Specifier Compatibility Matrix
| | % | d / i | u | x / X | p | c | s |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Precision (.)** | X | Min digits | Min digits | Min digits | Min digits | X | Max characters |
| **- (Minus)** | Left-justify | Left-justify | Left-justify | Left-justify | Left-justify | Left-justify | Left-justify |
| **0 (Zero)** | Zero padding | Zero padding | Zero padding | Zero padding | Zero padding | UB | UB |
| **+ (Plus)** | X | Force '+' sign | X | X | X | X | X |
| **# (Hash)** | X | X | X | Prepend 0x/0X | X | X | X |
| **(Space)** | X | Space for sign | X | X | X | X | X |

### Flag Priority & Conflict Resolution

| Flag A | Flag B | Priority / Result | Reason |
| :--- | :--- | :--- | :--- |
| **+ (Plus)** | **' ' (Space)** | **+** wins | Forced sign (+) takes precedence over optional space. |
| **- (Minus)** | **0 (Zero)** | **-** wins | Left-alignment (-) makes zero-padding (0) logically invalid. |
| **. (Precision)**| **0 (Zero)** | **.** wins | For integers, precision handles padding; width-based '0' is ignored. |

## 5. Instructions
### compliation
The project includes a comprehensive Makefile to build the static library libftprintf.a.
* To compile: `make`
* To remove objects: `make clean`
* To remove all generated files: `make fclean`
* To rebuild: `make re`
* To compile bonus files: `make bonus`

### usage information
```c
#include "ft_printf.h"

int main(void) {
    ft_printf("Hex: %#x\n", 42);       // Output: 0x2a
    ft_printf("Precision: %.5d\n", 7); // Output: 00007
    ft_printf("Width: %10d\n", 42);    // Output:         42
    return (0);
}
```
## 6. Resources & AI Disclosure
* **Documentation**: Standard C library references for printf and variadic functions.
* **Subject**: Official 42 School ft_printf manual .
* **AI Usage**: Gemini 3 Flash was used to refine the t_format structure and optimize flag priority logic (e.g., ensuring the - flag correctly overrides the 0 flag).