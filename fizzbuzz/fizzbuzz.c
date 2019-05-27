#include <stdio.h>

/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
    Don't forget to include newlines '\n' in your printf statements!
*/
int fizzbuzz(int n)
{
    char fizzbuzz[10] = "Fizzbuzz";
    char fizz[5] = "Fizz";
    char buzz[5] = "Buzz";
    int counter = 0;

    for (int i = 1; i <= n; i++) {
        if (i % 5 == 0 && i % 3 == 0) {
            printf("%s\n", fizzbuzz);
        }
        else if (i % 5 == 0) {
            printf("%s\n", buzz);
        }
        else if (i % 3 == 0) {
            printf("%s\n", fizz);
        } 
        else {
            counter++;
        }
    }
    printf("%d\n", counter);
    return counter;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
