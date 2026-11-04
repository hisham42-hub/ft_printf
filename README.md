*This project has been created as part of the 42 curriculum by hsalahal.*

# ft_printf

## 1. Description

The **ft_printf** project is part of the 42 curriculum. The goal is to recode the standard C library function `printf()`.

The project introduces variadic functions in C and helps develop a better understanding of format strings, argument handling, data types, and output formatting.

The objective is to create a static library named `libftprintf.a` containing a custom implementation of `ft_printf()` that reproduces the behavior of the original `printf()` for the required conversions.

## 2. Features

### Mandatory Conversions

| Conversion | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal format. |
| `%d` | Prints a decimal (base 10) number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal number. |
| `%x` | Prints a hexadecimal number using lowercase letters. |
| `%X` | Prints a hexadecimal number using uppercase letters. |
| `%%` | Prints a percent sign. |

### Return Value

The function returns the total number of characters printed, following the behavior of the original `printf()` for the supported conversions.

## 3. Instructions

### Requirements

Before compiling the project, make sure you have:

- A C compiler (`cc`).
- The `make` utility.
- The `ar` command to create the static library.

### Compilation

Clone the repository:

```bash
git clone <repository_url>
cd ft_printf
```

Compile the library:

```bash
make
```

This generates:

```bash
libftprintf.a
```

### Makefile Rules

The Makefile provides the following rules:

| Rule | Description |
|---|---|
| `make` / `make all` | Compiles the project and creates the library. |
| `make clean` | Removes object files. |
| `make fclean` | Removes object files and the library. |
| `make re` | Rebuilds the project from scratch. |
| `make bonus` | Compiles the bonus part, if implemented. |

### Using the Library

Include the header file in your C program:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
cc main.c -L. -lftprintf -o program
```

Run the program:

```bash
./program
```

## 4. Usage Examples

### Example 1: Characters and Strings

```c
ft_printf("Hello %s!\n", "World");
ft_printf("Character: %c\n", 'A');
```

### Example 2: Integers

```c
ft_printf("Decimal: %d\n", 42);
ft_printf("Integer: %i\n", -42);
ft_printf("Unsigned: %u\n", 42);
```

### Example 3: Hexadecimal

```c
ft_printf("Lowercase: %x\n", 255);
ft_printf("Uppercase: %X\n", 255);
```

### Example 4: Pointers and Percentages

```c
int number = 42;

ft_printf("Pointer: %p\n", &number);
ft_printf("Percentage: 100%%\n");
```

## 5. Algorithm and Data Structures

### Algorithm

The main algorithm of `ft_printf()` consists of reading the format string character by character and identifying conversion specifiers.

The general process is:

1. Initialize the variadic argument list using `va_start()`.
2. Iterate through the format string.
3. If the current character is not `%`, print it using `write()`.
4. If `%` is encountered, inspect the following character to identify the conversion.
5. Retrieve the corresponding argument using `va_arg()`.
6. Call the appropriate helper function to print the argument in the required format.
7. Count the number of characters printed.
8. Continue until the end of the format string.
9. Finish the variadic argument list using `va_end()`.
10. Return the total number of characters printed.

### Data Structures

The project mainly uses:

- **Format string (`const char *`)**: Stores the format passed to `ft_printf()`.
- **Variadic argument list (`va_list`)**: Stores and provides access to the variable number of arguments.
- **Integer counter (`int`)**: Tracks the total number of characters printed.
- **Helper functions**: Handle the different conversion types independently.

### Algorithm Justification

A character-by-character parsing approach makes the implementation simple, organized, and easy to maintain.

Using variadic functions allows `ft_printf()` to accept a variable number of arguments, just like the original `printf()`.

Separating conversions into helper functions avoids unnecessary code duplication and makes it easier to add or modify functionality.

The project uses `write()` to display characters directly without implementing the original `printf()` buffer management.

*Note: Adapt this section to match the actual algorithm and data structures used in your implementation.*

## 6. Project Structure

Example project organization:

```text
ft_printf/
│
├── Makefile
├── ft_printf.h
├── libftprintf.a
│
├── ft_printf.c
├── ft_printf_utils.c
│
├── mandatory/
│   ├── ft_print_char.c
│   ├── ft_print_str.c
│   ├── ft_print_ptr.c
│   ├── ft_print_nbr.c
│   └── ft_print_hex.c
│
└── README.md
```

*The structure above is an example. Adjust it according to your actual repository.*

## 7. Bonus Part

The subject proposes the following optional features:

### Flags and Field Width

- Manage combinations of the following flags: `-`, `0`, `.` and minimum field width under all conversions.

### Additional Flags

- `#`: Alternative form.
- `+`: Always display the sign for signed conversions.
- Space: Display a leading space for positive signed numbers.

The bonus part is evaluated only if the mandatory part is completely implemented and works correctly.

## 8. Resources

The following resources are useful for understanding the concepts used in this project:

### C Documentation

- [Linux Manual – printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Linux Manual – stdarg](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [Linux Manual – write](https://man7.org/linux/man-pages/man2/write.2.html)
- [C Reference – Variadic Functions](https://en.cppreference.com/w/c/variadic.html)

### Concepts Studied

- Variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`).
- Pointers and memory addresses.
- Number conversion between decimal and hexadecimal.
- String manipulation.
- Static libraries and compilation.
- Makefiles and modular programming.

### AI Usage

AI tools were used for:

- [Describe whether and how AI helped you understand concepts.]
- [Describe any assistance with debugging or identifying errors.]
- [Describe any assistance with organizing documentation.]

All code and implementation decisions should be understood and explainable by the project author.

## 9. Testing

The implementation should be tested against the original `printf()` function to verify that both produce equivalent output and return values for the supported conversions.

Suggested tests:

- Characters (`%c`).
- Strings (`%s`).
- NULL strings.
- Pointers (`%p`).
- Positive and negative integers (`%d`, `%i`).
- Unsigned integers (`%u`).
- Lowercase and uppercase hexadecimal (`%x`, `%X`).
- Percentage signs (`%%`).
- Multiple conversions in the same format string.
- Empty strings and zero values.
- Minimum and maximum integer values.

## 10. General Rules and Constraints

The project must respect the common 42 requirements:

- The project must be written in C.
- All code must follow the 42 Norm.
- Compilation must use `-Wall -Wextra -Werror`.
- The project must not crash unexpectedly.
- All allocated memory must be freed when necessary.
- The Makefile must avoid unnecessary relinking.
- The static library must be created using `ar`.
- The library must be located at the root of the repository.
- The header file must be named `ft_printf.h`.
- The mandatory and bonus parts are evaluated separately.

## 11. Author

**Project:** ft_printf

**School:** 42

**Author:** &lt;your_login&gt;

**Language:** C

**Library:** libftprintf.a

**Version:** 1.0