/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: hsalahal <hsalahal@student.42abudhabi.ae> #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 10:58:37 by hsalahal         #+#    #+#              */
/*   Updated: 2026/11/14 10:58:37 by hsalahal        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	int	ret1, ret2;

	printf("=== 1. CHAR (%%c) & PERCENT (%%%%) ===\n");
	// Test 1: Standard character
	ret1 = printf("Standard: [%c]\n", 'a');
	ret2 = ft_printf("Custom:   [%c]\n", 'a');
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	// Test 2: Null character
	ret1 = printf("Standard: [%c]\n", '\0');
	ret2 = ft_printf("Custom:   [%c]\n", '\0');
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	// Test 3: Percent sign literal
	ret1 = printf("Standard: [%%]\n");
	ret2 = ft_printf("Custom:   [%%]\n");
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	printf("=== 2. STRINGS (%%s) ===\n");
	// Test 4: Standard string
	ret1 = printf("Standard: [%s]\n", "Hello 42!");
	ret2 = ft_printf("Custom:   [%s]\n", "Hello 42!");
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	// Test 5: Empty string
	ret1 = printf("Standard: [%s]\n", "");
	ret2 = ft_printf("Custom:   [%s]\n", "");
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	// Test 6: NULL string pointer (should print (null))
	ret1 = printf("Standard: [%s]\n", (char *) NULL);
	ret2 = ft_printf("Custom:   [%s]\n", (char *) NULL);
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	printf("=== 3. INTEGERS (%%d & %%i) ===\n");
	// Test 7: Positive number
	ret1 = printf("Standard: [%d]\n", 42);
	ret2 = ft_printf("Custom:   [%d]\n", 42);
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	// Test 8: Negative number
	ret1 = printf("Standard: [%d]\n", -42);
	ret2 = ft_printf("Custom:   [%d]\n", -42);
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	// Test 9: Integer limits (INT_MIN and INT_MAX)
	ret1 = printf("Standard: [%d] | [%d]\n", INT_MIN, INT_MAX);
	ret2 = ft_printf("Custom:   [%d] | [%d]\n", INT_MIN, INT_MAX);
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	// Test 10: %i format specifier
	ret1 = printf("Standard: [%i]\n", -12345);
	ret2 = ft_printf("Custom:   [%i]\n", -12345);
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	printf("=== 4. UNSIGNED INT (%%u) ===\n");
	// Test 11: Normal unsigned value
	ret1 = printf("Standard: [%u]\n", 42);
	ret2 = ft_printf("Custom:   [%u]\n", 42);
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	// Test 12: Negative cast to unsigned (%u of -1)
	ret1 = printf("Standard: [%u]\n", -1);
	ret2 = ft_printf("Custom:   [%u]\n", -1);
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	// Test 13: UINT_MAX limit
	ret1 = printf("Standard: [%u]\n", UINT_MAX);
	ret2 = ft_printf("Custom:   [%u]\n", UINT_MAX);
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	printf("=== 5. HEXADECIMAL (%%x & %%X) ===\n");
	// Test 14: Lowercase hex (%x)
	ret1 = printf("Standard: [%x]\n", 42576);
	ret2 = ft_printf("Custom:   [%x]\n", 42576);
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	// Test 15: Uppercase hex (%X)
	ret1 = printf("Standard: [%X]\n", 42576);
	ret2 = ft_printf("Custom:   [%X]\n", 42576);
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	// Test 16: Zero in hex
	ret1 = printf("Standard: [%x] | [%X]\n", 0, 0);
	ret2 = ft_printf("Custom:   [%x] | [%X]\n", 0, 0);
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	printf("=== 6. POINTERS (%%p) ===\n");
	int	a = 42;

	// Test 17: Valid pointer address
	ret1 = printf("Standard: [%p]\n", (void *) & a);
	ret2 = ft_printf("Custom:   [%p]\n", (void *) & a);
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	// Test 18: NULL pointer address
	ret1 = printf("Standard: [%p]\n", (void *) NULL);
	ret2 = ft_printf("Custom:   [%p]\n", (void *) NULL);
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	printf("=== 7. MIXED & STACKED ARGUMENTS ===\n");
	// Test 19: Multiple specifiers combined in a sentence
	ret1 = printf("Standard: Hello %s, number is %d and hex is %x %% done!\n", "Student", 42, 255);
	ret2 = ft_printf("Custom:   Hello %s, number is %d and hex is %x %% done!\n", "Student", 42, 255);
	printf("Returns -> std: %d | ft: %d\n\n", ret1, ret2);
	return (0);
}
