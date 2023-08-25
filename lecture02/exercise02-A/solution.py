#!/usr/bin/env python3

import sys

# Functions

def count_with_find(numbers):
    total = 0
    for index, number in enumerate(numbers):
        if number in numbers[index + 1:]:
            total += 1
    return total

def count_with_set(numbers):
    total = 0
    seen  = set()
    for number in numbers:
        if number in seen:
            total += 1
        else:
            seen.add(number)
    return total

def count_with_sort(numbers):
    total = 0
    numbers.sort()
    for index, number in enumerate(numbers):
        if number == numbers[index - 1]:
            total += 1
    return total

# Main Execution

def main():
    numbers = [int(line) for line in sys.stdin]
    #print(count_with_find(numbers))
    print(count_with_set(numbers))
    #print(count_with_sort(numbers))

if __name__ == '__main__':
    main()

# vim: set sts=4 sw=4 ts=8 expandtab ft=python:
