//
//  main.cpp
//  FindDuplicate
//
//  Created by yangboz on 10/19/15.
//  Copyright (c) 2015 SMARTKIT.INFO. All rights reserved.
//
//Verify those geek methods and learn something from it.
//@http://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
//Geek thinking:
/*
Method 3 (Make two equations)
Let the numbers which are being repeated are X and Y. We make two equations for X and Y and the simple task left is to solve the two equations.
We know the sum of integers from 1 to n is n(n+1)/2 and product is n!. We calculate the sum of input array, when this sum is subtracted from n(n+1)/2, we get X + Y because X and Y are the two numbers missing from set [1..n]. Similarly calculate product of input array, when this product is divided from n!, we get X*Y. Given sum and product of X and Y, we can find easily out X and Y.
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* function to get factorial of n */
int fact(int n);

void printRepeating(int arr[], int size)
{
    int S = 0;  /* S is for sum of elements in arr[] */
    int P = 1;  /* P is for product of elements in arr[] */
    int x,  y;   /* x and y are two repeating elements */
    int D;      /* D is for difference of x and y, i.e., x-y*/
    int n = size - 2,  i;
    
    /* Calculate Sum and Product of all elements in arr[] */
    for(i = 0; i < size; i++)
    {
        S = S + arr[i];
        P = P*arr[i];
    }
    
    S = S - n*(n+1)/2;  /* S is x + y now */
    P = P/fact(n);         /* P is x*y now */
    
    D = sqrt(S*S - 4*P); /* D is x - y now */
    
    x = (D + S)/2;
    y = (S - D)/2;
    
    printf("The two Repeating elements are %d & %d", x, y);
}

int fact(int n)
{
    return (n == 0)? 1 : n*fact(n-1);
}

int main()
{
//    int arr[] = {4, 2, 4, 5, 2, 3, 1};//Valid results only.
    int arr[] = {44, 4,22, 2,4, 5, 2, 3, 1};//Invalid methods
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printRepeating(arr, arr_size);
    getchar();
    return 0;
}
