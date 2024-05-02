#include<stdio.h>

int main(){
    int x;
    scanf("%d",x);
    printf("%d\n",x);
    return 0;
}
//C is very powerful language - but is also very dangerous. It is very easy to make mistakes in C.
//The above code is a simple example of a mistake in C. The scanf function requires the address of the variable to store the input. The correct code should be:
//C is also memory unsafe. It is very easy to access memory that you are not supposed to access. for example: you can also go out of bounds of an array in C. 
