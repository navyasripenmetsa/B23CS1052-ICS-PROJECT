This project is a matrix calculator implemented in C. Here's an overview:

Functionality: The program allows users to perform various operations on matrices including addition, subtraction, multiplication, scalar multiplication, transpose, and trace.

Input Handling: Users are prompted to select the operation they want to perform by entering symbols such as '+', '-', '*', 'ScalarMultiplication', 'Transpose', or 'Trace'. They are also prompted to enter the dimensions and elements of the matrices involved in the operation.

Matrix Operations:

Addition and Subtraction: Matrices A and B are added or subtracted element-wise. The result is displayed if the matrices have the same dimensions.
Multiplication: Matrices A and B are multiplied following matrix multiplication rules. The result is displayed if the number of columns in A matches the number of rows in B.
Scalar Multiplication: Each element of Matrix A is multiplied by a scalar value entered by the user.
Transpose: The transpose of Matrix A is computed and displayed.
Trace: The trace of Matrix A (sum of diagonal elements) is calculated and displayed.
Error Handling: The program checks for invalid dimensions of matrices and provides appropriate error messages.

Output: Results of operations are displayed to the user.

User Interface: The program provides a simple text-based interface where users can input their desired operation and matrices.

Modular Design: The code is divided into functions for each operation, enhancing readability and maintainability.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int r1,r2,c1,c2;
void transpose(int r1,int c1,int m1[r1][c1],int trans[c1][r1]) {
    printf("Matrix A after transpose\n");
    for (int i =0;i < r1;i++) {
        for (int j =0;j < c1;j++) {
            trans[j][i]=m1[i][j];
        }
    }
    for(int i=0; i < c1;i++) {
        for(int j=0;j<r1;j++) {
            printf("%d ",trans[i][j]);
        }
        printf("\n");
    }
}
void trace(int r1,int c1,int m1[r1][c1]) {
   int  trace=0;
    if(r1==c1) {
        for(int i=0;i<r1;i++) {
            trace=trace+m1[i][i];
        }
        printf("Trace of Matrix A:%d",trace);
    }
    else {
        printf("Trace does not exist for non square matrices");
    }
}
void scalarm(int r1,int c1,int m1[r1][c1],float k) {
    float res[r1][c1];
    printf("Matrix A after multipied with scalar:\n");
    for(int i=0;i<r1;i++) {
        for(int j=0;j<c1;j++) {
            res[i][j]=k*m1[i][j];
        }
    }
    for(int i=0;i<r1;i++) {
        for(int j=0;j<c1;j++) {
          printf("%.2f ",res[i][j]);
        }
        printf("\n");
    }
}
void addition(int r1,int r2,int c1,int c2,int m1[r1][c1],int m2[r2][c2]) {
   int res[r1][c1];
   if(r1==r2 && c1==c2)  {
       for(int i=0;i<r1;i++) {
       for(int j=0;j<c1;j++) {
           res[i][j]=m1[i][j]+m2[i][j];
       }
   }
   for(int i=0;i<r1;i++) {
       if(i==0) printf("Matrix A+Matrix B\n");
        for(int j=0;j<c1;j++) {
           printf("%d ",res[i][j]);
       }
       printf("\n");
   }
    }
    else {
         printf("Matrix A+Matrix B\n");
        printf("error\n");
        printf("because the order of both of them is not same\n");
    }
    return;
}
void subtraction(int r1,int r2,int c1,int c2,int m1[r1][c1],int m2[r2][c2]) {
   int res[r1][c1];
   if(r1==r2 && c1==c2)  {
       for(int i=0;i<r1;i++) {
       for(int j=0;j<c1;j++) {
           res[i][j]=m1[i][j]-m2[i][j];
       }
   }
   for(int i=0;i<r1;i++) {
       if(i==0) printf("Matrix A-Matrix B\n");
        for(int j=0;j<c1;j++) {
           printf("%d ",res[i][j]);
       }
       printf("\n");
   }
    }
    else {
         printf("Matrix A-Matrix B\n");
        printf("error\n");
         printf("because the order of both of them is not same\n");
    }
    return;
}
void Multiply(int r1,int r2,int c1,int c2,int m1[r1][c1],int m2[r2][c2]) {
    printf("Matrix A*Matrix B\n");
    int res[r1][c2];
    if(c1==r2) {
        for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0; 
            for (int k = 0; k < c1; k++) {
                res[i][j]+= m1[i][k] * m2[k][j];
            }
        }
    }
    for(int i=0;i<r1;i++) {
        for(int j=0;j<c2;j++) {
           printf("%d ",res[i][j]);
       }
       printf("\n");
   }
}
    else {
       printf("error\n");
     printf("the columns in matrix A not equal to rows in matrix B\n");
    }
}
int main() {
    printf("                # WELCOME TO MATRIX CALCULATOR #\n");
    printf("For Addition----->enter +\n");
    printf("For Subtraction------>enter -\n");
    printf("For Multiplication-------> enter *\n");
 printf("For scalar multiplication------> enter ScalarMultiplication\n");
    printf("For Transpose----------> enter Transpose\n");
    printf("For Trace----------> enter Trace\n");
   char c[20];
    printf("Operation to be performed:");
    scanf("%s",c);
   printf("enter no.of rows of Matrix A:");
   scanf("%d",&r1);
   printf("enter no.of columns of Matrix A:");
   scanf("%d",&c1);
   if (r1 <= 0 || c1 <= 0) {
        printf("Invalid dimensions\n");
        exit(1);
    }
if(strcmp(c,"+")==0||strcmp(c,"-")==0||strcmp(c,"*")==0) {
   printf("enter no.of rows of Matrix B:");
   scanf("%d",&r2);
   printf("enter no.of columns of Matrix B:");
   scanf("%d",&c2);
   if (r2 <= 0 || c2 <= 0) {
        printf("Invalid dimensions\n");
        exit(1);
    }
}
   int M1[r1][c1],M2[r2][c2];
   printf("Enter elements in A:\n");
   for(int i=0;i<r1;i++) {
       for(int j=0;j<c1;j++) {
           scanf("%d",&M1[i][j]);
       }
   }
if(strcmp(c,"+")==0||strcmp(c,"-")==0||strcmp(c,"*")==0) {
    printf("Enter elements in B:\n");
   for(int i=0;i<r2;i++) {
       for(int j=0;j<c2;j++) {
           scanf("%d",&M2[i][j]);
       }
   }
}
   for(int i=0;i<r1;i++) {
       if(i==0) {
           printf("Matrix A:\n");
       }
       for(int j=0;j<c1;j++) {
           printf("%d ",M1[i][j]);
       }
       printf("\n");
   }
if(strcmp(c,"+")==0||strcmp(c,"-")==0||strcmp(c,"*")==0) {
   for(int i=0;i<r2;i++) {
       if(i==0) {
           printf("Matrix B:\n");
       }
       for(int j=0;j<c2;j++) {
           printf("%d ",M2[i][j]);
       }
       printf("\n");
   }
}
   if(strcmp(c,"+")==0) {
   addition(r1,r2,c1,c2,M1,M2);
   }
  else if(strcmp(c,"-")==0) {
   subtraction(r1,r2,c1,c2,M1,M2);
   }
  else if(strcmp(c,"*")==0) {
   Multiply(r1,r2,c1,c2,M1,M2);
   }
  else if(strcmp(c,"ScalarMultiplication")==0) {
       float k;
       printf("enter the value of scalar:");
       scanf("%f",&k);
       scalarm(r1,c1,M1,k);
   }
  else if(strcmp(c,"Trace")==0) {
       trace(r1,c1,M1);
   }
  else if(strcmp(c,"Transpose")==0) {
       int trans[c1][r1];
       transpose(r1,c1,M1,trans);
       }
       else {
 printf("enter a operation which is included in the project\n");
       }
}
