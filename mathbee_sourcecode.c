#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include <stdbool.h>
#include<windows.h>
#define EPSILON 0.0001 
int user_answer,actual_answer;
void generate_random_parameters(double parameters[]) {
    for (int i = 0; i <= 5; i++) {
        parameters[i] = rand() % 10; // Random parameters (0 to 9)
    }
}

double evaluate_expression(double parameters[], int value) {
    double result = 0;
    for (int i = 5; i >= 0; i--) {
        result += parameters[i] * pow(value, i);
    }
    return result;
}

double calculate_integral(double parameters[], int value) {
    double integral = 0;
    for (int i = 5; i >= 0; i--) {
        integral += parameters[i] / (i + 1) * pow(value, i + 1);
    }
    return integral;
}



void diff_question(int coefficients[]) {
   printf("Differentiate ");
    for (int i = 5; i >= 0; i--) {
        if (coefficients[i] != 0) {
            if (i == 0) {
                printf("%d", coefficients[i]);
            } else {
                printf("%dx^%d ", coefficients[i], i);
            }
            if (i > 0 && coefficients[i - 1] > 0) {
                printf("+ ");
            }
        }
    }
    printf("\n");
}
void calculate_derivative_coefficients(int coefficients[], int derivative[]) {
    for (int i = 5; i >= 1; i--) {
        derivative[i - 1] = i * coefficients[i];
    }
    derivative[5] = 0; 
}
double evaluate_polynomial(int coefficients[], int x) {
    double result = 0;
    for (int i = 5; i >= 0; i--) {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}
void generate_question(int *score) {
    int base = rand() % 9 + 1;
    int exponent = rand() % 20 + 1;
    long long result = 1; // Initialize result
    for (int i = 0; i < exponent; i++) {
        result *= base;
        result %= 10; // Keep only the last digit to prevent overflow
    }
    int last_digit = result;

    printf("What is the last digit of %d^%d?\n", base, exponent);
    int user_answer;
    printf("Enter your answer: ");
    scanf("%d", &user_answer);
    if (user_answer == last_digit) {
        printf("Correct!! \u263A\n");
        *score += 85;
    } else {
        printf("Wrong answer. Better luck next time.\n");
        Beep(500,1000);
         Beep(500,1000);
          Beep(500,1000);
        printf("The correct answer is %d\n", last_digit);
    }
}

void probabilty(int *score)  {
    srand(time(NULL));
    char* probability_questions[10] = {
        "Probability of drawing one red ball and one blue ball from a bagwith 5 red, 3 blue, and 2 green balls:", // Q1
        "Probability of forming a committee with 3 men and 2 women from a group of 8 men and 6 women:", // Q2
        "Probability of drawing exactly 2 blue marbles from a jar with 4 red, 3 blue, and 3 green marbles:", // Q3
        "Probability of choosing at least 2 dark chocolates from a box with 5 dark and 7 milk chocolates when 3 chocolates are chosen", // Q4
        "Probability of the sum of three dice being greater than 10:", // Q5
        "Probability of drawing two socks of different colors from a box with 6 red, 4 blue, and 2 black socks:", // Q6
        "A standard six-sided die is rolled once. What is the probability of rolling a number greater than 4?", // Q7
        "Probability of the sum of two dice being a prime number:", // Q8
        "Probability of drawing two balls of different colors from a bag with 8 red, 5 blue, and 3 green balls:", // Q9
        "Probability of the sum of two spins of a spinner being 6, where each spin results in a number from 1 to 5:"//Q10
    };

    int probabilty_index = rand() % 10;
    float probabilty_answers[10] = {0.26, 0.03, 0.22, 0.318, 0.421, 0.72, 0.33, 0.41, 0.53, 0.28};
    printf("%s\n", probability_questions[probabilty_index]);
    printf("Enter your answer:");
    
    float user_answer;
    scanf("%f", &user_answer);

    float epsilon = 0.001; // Define an acceptable tolerance
    if (fabs(user_answer - probabilty_answers[probabilty_index]) < epsilon) {
        printf("Correct!! \u263A\n");
        *score = *score + 85;
    } 
    else if(user_answer!=probabilty_answers[probabilty_index]) {
        printf("Wrong answer better luck next time\n");
         Beep(500,1000);
          Beep(500,1000);
           Beep(500,1000);
printf("The correct answer is %f\n",probabilty_answers[probabilty_index]);
switch(probabilty_index) {
            case 0:
                printf("Out of all possible pairs of balls drawn, there are 15 pairs that consist of one red and one blue ball.");
                break;
            case 1:
                printf("Out of all possible combinations of 5 people in the committee, 112 combinations include 3 men and 2 women.\n");
                break;
            case 2:
                printf("Out of all possible combinations of 3 marbles drawn, there are 9 combinations that include exactly 2 blue marbles.\n");
                break;
            case 3:
                printf("Out of all possible combinations of 3 chocolates chosen, there are 7 combinations that include at least 2 dark chocolates.\n");
                break;
            case 4:
                printf("Out of all possible outcomes when three dice are rolled, there are 91 outcomes where the sum is greater than 10.\n");
                break;
            case 5:
                printf("Out of all possible pairs of socks drawn, there are 48 pairs that consist of socks of different colors.\n");
                break;
            case 6:
                printf("Out of all possible combinations of 4 cards drawn, there are 4 combinations that consist of cards of the same suit.\n");
                break;
            case 7:
                printf("Out of all possible outcomes when two dice are rolled, there are 15 outcomes where the sum is a prime number\n");
                break;
            case 8:
                printf(" Out of all possible pairs of balls drawn, there are 75 pairs that consist of balls of different colors..\n");
                break;
            case 9:
                printf(" Out of all possible pairs of spins, there are 7 pairs that result in a sum of 6.\n");
                break;}
    }
}

void hoursToMinutes(int *score) {
    int hours = rand() % 24;
    int minutes = hours * 60;
    printf("Convert %d hours to minutes: ", hours);
    int answer;
    scanf("%d", &answer);
    if (answer == hours * 60) {
        printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %d minutes.\n", hours * 60);
         Beep(500,1000);
          Beep(500,1000);
           Beep(500,1000);
    }
}
void hoursToSeconds(int *score) {
    int hours = rand() % 24;
    int seconds = hours * 3600;
    printf("Convert %d hours to seconds: ", hours);
    int answer;
    scanf("%d", &answer);
    if (answer == hours * 3600) {
       printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %d seconds.\n", hours * 3600);
         Beep(500,1000);
          Beep(500,1000);
           Beep(500,1000);
    }
}
void daysToHours(int *score) {
    int days = rand() % 30 + 1; 
    int hours = days * 24;
    printf("Convert %d days to hours: ", days);
    int answer;
    scanf("%d", &answer);
    if (answer == days * 24) {
        printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %d hours.\n", days * 24);
         Beep(500,1000);
          Beep(500,1000);
           Beep(500,1000);
    }
}
void yearsToDays(int *score) {
    int years = rand() % 100 + 1; 
    int days = years * 365;
    printf("Convert %d years to days: ", years);
    int answer;
    scanf("%d", &answer);
    if (answer == years * 365) {
        printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %d days.\n", years * 365);
         Beep(500,1000);
          Beep(500,1000);
           Beep(500,1000);
    }
}
void yearsToHours(int *score) {
    int years = rand() % 100 + 1; 
    int hours = years * 8760; 
    printf("Convert %d years to hours: ", years);
    int answer;
    scanf("%d", &answer);
    if (answer == years * 8760) {
        printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %d hours.\n", years * 8760);
         Beep(500,1000);
          Beep(500,1000);
           Beep(500,1000);
    }
}
void decadesToMonths(int *score) {
    int decades = rand() % 10 + 1; 
    int months = decades * 120;
    printf("Convert %d decades to months: ", decades);
    int answer;
    scanf("%d", &answer);
    if (answer == decades * 120) {
        printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %d months.\n", decades * 120);
         Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    }
}
void decadesToWeeks(int *score) {
    int decades = rand() % 10 + 1; 
    int weeks = decades * 520;
    printf("Convert %d decades to weeks: ", decades);
    int answer;
    scanf("%d", &answer);
    if (answer == decades * 520) {
        printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %d weeks.\n", decades * 520);
        Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    }
}
void kilometersToMeters(int *score) {
    int kilometers = rand() % 100 + 1; 
    int meters = kilometers * 1000;
    printf("Convert %d kilometers to meters: ", kilometers);
    int answer;
    scanf("%d", &answer);
    if (answer == kilometers * 1000) {
       printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %d meters.\n", kilometers * 1000);
         Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    }
}
void metersToMillimeters(int *score) {
    int meters = rand() % 1000 + 1; 
    int millimeters = meters * 1000;
    printf("Convert %d meters to millimeters: ", meters);
    int answer;
    scanf("%d", &answer);
    if (answer == meters * 1000) {
        printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %d millimeters.\n", meters * 1000);
        Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    }
}
void decimetersToCentimeters(int *score) {
    int decimeters = rand() % 100 + 1; 
    int centimeters = decimeters * 10;
    printf("Convert %d decimeters to centimeters: ", decimeters);
    int answer;
    scanf("%d", &answer);
    if (answer == decimeters * 10) {
        printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %d centimeters.\n", decimeters * 10);
         Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    }
}
void kilogramsToMilligrams(int *score) {
    int kilograms = rand() % 100 + 1;
    int milligrams = kilograms * 1000000;
    printf("Convert %d kilograms to milligrams: ", kilograms);
    int answer;
    scanf("%d", &answer);
    if (answer == kilograms * 1000000) {
        printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %d milligrams.\n", kilograms * 1000000);
        Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    }
}
void rupeesToPaise(int *score) {
    int rupees = rand() % 1000 + 1; 
    int paise = rupees * 100;
    printf("Convert %d rupees to paise: ", rupees);
    int answer;
    scanf("%d", &answer);
    if (answer == rupees * 100) {
        printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %d paise.\n", rupees * 100);
         Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    }
}
void litresToMillilitres(int *score) {
    int litres = rand() % 100 + 1;
    int millilitres = litres * 1000;
    printf("Convert %d litres to millilitres: ", litres);
    int answer;
    scanf("%d", &answer);
    if (answer == litres * 1000) {
        printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %d millilitres.\n", litres * 1000);
        Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    }
}
void millimetersToNanometers(int *score) {
    int millimeters = rand() % 1000 + 1; 
    long long nanometers = millimeters * 1000000;
    printf("Convert %d millimeters to nanometers: ", millimeters);
    int answer;
    scanf("%d", &answer);
    if (answer == millimeters * 1000000) {
       printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %lld nanometers.\n", millimeters * 1000000);
         Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    }
}
void centuaryToYears(int *score) {
    int centuary = rand() % 100 + 1; 
    int years = centuary * 100;
    printf("Convert %d centuries to years: ", centuary);
    int answer;
    scanf("%d", &answer);
    if (answer == centuary * 100) {
        printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %d years.\n", centuary * 100);
         Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    }
}
void centuaryToDecades(int *score) {
    int centuary = rand() % 100 + 1; 
    int decades = centuary * 10;
    printf("Convert %d centuries to decades: ", centuary);
    int answer;
    scanf("%d", &answer);
    if (answer == centuary * 10) {
        printf("Correct!! \u263A \n");
        *score=*score+50;
    } else {
        printf("Incorrect. The correct answer is %d decades.\n", centuary * 10);
        Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    }
}
void print_square(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
void print_rectangle(int n, int m) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (i == 1 || i == n || j == 1 || j == m)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}
void print_triangle(int n) {
    int i, space, j;
 for (i = 0; i < n - 1; i++) {
        for (space = 1; space < n - i; space++) {
            printf(" ");
        }
        for (j = 0; j <= 2 * i; j++) {
            if (j == 0 || j == 2 * i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    for (i = 0; i < 2 * n - 1; i++) {
        printf("*");
    }
    printf("\n");
}
void print_parallelogram(int rows) {
    int i, j;
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= rows - i; j++)
            printf(" ");
        if (i == 1 || i == rows)
            for (j = 1; j <= rows; j++)
                printf("*");
        else
            for (j = 1; j <= rows; j++)
                if (j == 1 || j == rows)
                    printf("*");
                else
                    printf(" ");
        printf("\n");
    }
}
void print_rhombus(int n) {
    int rows, columns;
    for (rows = 1; rows <= n; rows++) {
        for (columns = n; columns > rows; columns--) {
            printf(" ");
        }
        printf("*");
        for (columns = 1; columns < (rows - 1) * 2; columns++) {
            printf(" ");
        }
        if (rows != 1) {
            printf("*");
        }
        printf("\n");
    }
    for (rows = n - 1; rows >= 1; rows--) {
        for (columns = n; columns > rows; columns--) {
            printf(" ");
        }
        printf("*");
        for (columns = 1; columns < (rows - 1) * 2; columns++) {
            printf(" ");
        }
        if (rows != 1) {
            printf("*");
        }
        printf("\n");
    }
}
void print_hexagon(int n) {
    int l = 2 * n - 1;
    for (int i = 0; i < n; i++) {
        int elem = i + n;
        for (int k = 0; k < elem; k++) {
            if ((k == n + i - 1) || (k == n - i - 1))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    for (int m = 0; m < n - 2; m++) {
        for (int j = 0; j < l; j++) {
            if (j == 0 || j == l - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    int r = n - 1;
    for (int h = r; h >= 0; h--) {
        int elem = h + n;
        for (int k = 0; k < elem; k++) {
            if ((k == n + h - 1) || (k == n - h - 1))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}
int calculate_square_area(int side) {
    return side * side;
}
int calculate_rectangle_area(int length, int width) {
    return length * width;
}
float calculate_triangle_area(int base, int height) {
    return 0.5 * base * height;
}
int calculate_parallelogram_area(int base, int height) {
    return base * height;
}
float calculate_rhombus_area(int diagonal1, int diagonal2) {
    return 0.5 * diagonal1 * diagonal2;
}
float calculate_hexagon_area(int side) {
    return 3 * sqrt(3) * pow(side, 2) / 2;
}
int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}
void riddles_3(int *score)  {
    srand(time(NULL));
    char *riddles[]={"A merchant can place 8 large boxes or 10 small boxes into a carton for shipping. In one shipment, he sent a total of 96 boxes. How many cartons did he ship if there are more large boxes than small boxes?","If there are four apples and you take away three of them, how many apples do you have?","How many times can you subtract five from twenty-five?","If 7 is transformed into 13 and 11 into 21, what does 16 become?","The head of a bird is 9 cm long. Its tail is equal to the size of its head plus half the size of its body. Also, its body is equal to the size of its head plus its tail. The length of the bird will be?","Find the next number in the series 7645, 5764, 4576,………","Suppose 1+9+8=1, then what can be 2+8+9?","Ram has 5 sons. Each of his sons has a sister. If so, how many children does Mr.Ram have?","What is half of two plus two?","What is 7 + 7 ÷ 7 + 7 x 7 – 7?"};
    int riddleindex=rand()%10;
    int actualanswer[]={11,3,1,31,72,6457,10,6,3,50};
    printf("%s\n",riddles[riddleindex]);
    printf("Enter your answer:");
    scanf("%d",&user_answer);
    if(user_answer==actualanswer[riddleindex]) {
        printf("Correct!!  \u263A \n");
       *score=*score+65;
    }
    else {
        printf("Wrong answer better luck next time\n");
        Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
        printf("The correct answer is %d\n",actualanswer[riddleindex]);
    }
    }
int selectRandomQuestion(char *questions[], char *solutions[], int numQuestions) {
    srand(time(NULL));
    int index = rand() % numQuestions;
    printf("Question: %s\n", questions[index]);
    return index;
}
void riddles_2(int *score) {
    char *questions[] = {
        "How many lockers are open after 100 people toggle every locker, starting from the first locker?",
        "What is the missing number in the sequence: 2, 5, 11, 23, ___?",
        "How old is a man who has celebrated only 4 birthdays but is 20 years old?",
        "How many triangles are there in a triangle with vertices at each point where the lines of a 4x4 grid intersect?",
        "What is the product of all the numbers on a standard telephone keypad (0-9)?",
        "The letter to add which makes it 72 from 98",
        "Three times what number is not larger than two times the same number?",
        "I am a number, but when you add \"G\" to me, I go away. What number am I?",
        "I am a three-digit number. My second digit is four times bigger than the third digit. My first digit is three less than my second digit. Who am I?",
        "If seven people meet each other and each shake hands only once with each of the others, how many handshakes happened?"
    };
    char *solutions[] = {"10", "47", "5", "20", "0", "x", "0", "1", "141", "21"};
    int numQuestions = sizeof(questions) / sizeof(questions[0]);

    int randomIndex = selectRandomQuestion(questions, solutions, numQuestions);

    char userAnswer[100];
    printf("Your Answer: ");
    scanf("%s", userAnswer);
    if (strcmp(userAnswer, solutions[randomIndex]) == 0) {
        printf("Correct!! \u263A \n");
       *score=*score+50;
    } else {
        printf("Wrong answer better luck next time\n");
        Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
        printf("The correct answer is %s\n",*solutions);
        return ;
    }
}
void equations(int *score) {
    srand(time(0)); 
    int a1 = rand() % 21 - 10;
    int b1 = rand() % 21 - 10;
    int a2 = rand() % 21 - 10;
    int b2 = rand() % 21 - 10;
    int x = rand() % 21 - 10;
    int y = rand() % 21 - 10;
 int c1 = a1 * x + b1 * y;
    int c2 = a2 * x + b2 * y;
    printf("Equation 1: %dx + %dy = %d\n", a1, b1, c1);
    printf("Equation 2: %dx + %dy = %d\n", a2, b2, c2);
    int userX, userY;
    printf("Enter your solution as two integers (x y): ");
    scanf("%d %d", &userX, &userY);
if ((a1 * userX + b1 * userY == c1) || (a2 * userX + b2 * userY == c2)) {
        printf("Correct! \u263A The solution is x = %d, y = %d\n", x, y);
        *score=*score+50;
    } else {
        printf("Incorrect. The correct solution is x = %d, y = %d\n", x, y);
        Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    }
 return;
}
void Quadratic(int *score)  {
    srand(time(NULL));
    int u1,u2,ac1,ac2;
        int a1, a2,b1,b2,c1,c2;
        int root1, root2;
       int min=1;
       int max=10;
       a1=1;
       root1=rand()%(max-min+1) + min;
      root2=rand()%(max-min+1) + min;
      b1=-(root1+root2);
      c1=(root1*root2);
      int k=rand()%(max-min+1)+min;
      a2=k*a1;
      b2=k*b1;
      c2=k*c1;
      int dis=sqrt(b2*b2-4*a2*c2);
      ac1= (-b2+(dis))/(2*a2);
      ac2=(-b2-(dis))/(2*a2);
      printf(" solve the quadratic equation %dx^2+%dx+%d=0\n",a2,b2,c2);
      printf("Enter the two roots x1 and x2 (x1>=x2)\n");
      printf("Enter  x1:");
      scanf("%d",&u1);
      printf("Enter x2:");
      scanf("%d",&u2);
      if(u1==ac1 && u2==ac2) {
          printf("Correct!!  \u263A \n");
          *score=*score+65;
      }
      else {
          printf("Wrong answer better luck next time\n");
          Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
          printf("x1=%d\n",ac1);
          printf("x2=%d\n",ac2);
      }
}
void GP(int *score)  {
    srand(time(NULL));
    int a,r,n;
    int min=1;
    int max=10;
    int nmin=4;
    a=rand()%(max-min+1)+min;
    r=rand() % (max - min + 1) + min;
    n=rand() % (max - nmin + 1) + nmin;
printf("what is the value of term %d when first term is %d and common ratio is %d\n",n,a,r);
printf("Enter your answer:");
scanf("%d",&user_answer);
actual_answer=a*pow(r,n-1);
if(actual_answer==user_answer)  {
    printf("correct!!  \u263A \n");
    *score=*score+65;
}
else {
    printf("wrong better luck next time\n");
    Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    printf("The correct answer is %d\n",actual_answer);
}
return;
}
void AP(int *score) {
   srand(time(NULL));
    int a,d;
    int  n;
    int min=4;
    int max=100;
    int dmin=1;
    a=rand() %(max-min+1)+min;
    n=rand() % (max - min + 1) + min;
    d=rand() % (max - dmin + 1) + dmin;
printf("what is the %dth term when first term is %d and common difference is %d\n",n,a,d);
printf("Enter your answer:");
scanf("%d",&user_answer);
actual_answer=a+(n-1)*d;
if(actual_answer==user_answer)  {
    printf("correct!!  \u263A \n");
    *score=*score+65;
}
else {
    printf("wrong better luck next time\n");
    Beep(500,1000);
    Beep(500,1000); 
    Beep(500,1000);
    printf("The correct answer is %d\n",actual_answer);
}
}
int generateRandomNumberDivisible(int min, int max, int divisor);
int calculateResult(int a, int b, int c, int d, int e, int f, int g, int h) {
    return (a / b) * c + d - (e / f) + g * h;
}
int generateRandomNumberDivisible(int min, int max, int divisor) {
    int num;
    do {
        num = min + rand() % (max - min + 1);
    } while (num % divisor != 0);
    return num;
}
void round1(int *score) {
    srand(time(NULL));
    char operators[] = {'+', '-', '*'};
    int num1=rand()%100;
    int num2=rand()%100;
    int index=rand()%3;
    if(index==0) {
         actual_answer=num1+num2;
    }
    if(index==1) {
         actual_answer=num1-num2;
    }
    if(index==2) {
         actual_answer=num1*num2;
    }
    printf("what is the value of %d%c%d=?\n",num1,operators[index],num2);
    printf("Enter your answer:");
    scanf("%d",&user_answer);
    if(user_answer==actual_answer) {
        printf("correct!! \u263A\n");
        *score+=30;
    }
    else {
        printf("wrong answer better luck next time\n");
        Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
        printf("The correct answer is %d\n",actual_answer);
        *score=*score+0;
}
}
void division(int *score) {
     srand(time(NULL));
     int min = 1;  
    int max = 100;
        int a,b;
        b=rand() % (max - min + 1) + min;
        a=b*(rand()%100);
        printf("what is %d/%d?\n",a,b);
        printf("Enter your answer:");
        scanf("%d",&user_answer);
     actual_answer=a/b;
     if(user_answer==actual_answer) {
         printf("correct!! \u263A\n");
         *score=*score+30;
     }
     else {
         printf("wrong answer better luck next time\n");
         Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
         printf("The correct answer is %d\n",actual_answer);
         *score=*score+0;
     }
    }
    void equation(int *score) {
        srand(time(NULL));
        int a,b,c;
        int min = 1;  
    int max = 50;
        a=rand()%(max - min + 1) + min;
    b=rand()%100;
    c=a*(rand()%50)-b;
    printf("what is the value of y in the equation %dy-%d=%d??\n",a,b,c);
    printf("enter your answer:");
    scanf("%d",&user_answer);
    actual_answer=(b+c)/a;
    if(user_answer==actual_answer) {
         printf("correct!! \u263A\n");
         *score=*score+30;
     }
     else {
         printf("wrong answer better luck next time\n");
         Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
         printf("The correct answer is %d\n",actual_answer);
         *score=*score+0;
     }
        }
char p1[50];
int score1;
int main() {
     {
   printf("\n                       :::::::::::::::::::::::::::::::::::::");
   printf("\n                       ::                                 ::");
   printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
   printf("\n                       ::     @                     @     ::");
   printf("\n                       ::     @      WELCOME TO     @     ::");
   printf("\n                       ::     @                     @     ::");
   printf("\n                       ::     @MATH-BEE CHAMPIONSHIP@     ::");
   printf("\n                       ::     @                     @     ::");
   printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
   printf("\n                       ::                                 ::");
   printf("\n                       :::::::::::::::::::::::::::::::::::::\n\n");
 }
  printf("\n");
  printf("INSTRUCTIONS TO BE NOTED\n\n");
  printf("1. For Easy Level Enter \"EASY\"\n");
  printf("2. For Medium Level Enter \"MEDIUM\"\n");
  printf("3. For Difficult Level Enter \"DIFFICULT\"\n");
  printf("4. For Expert Level Enter \"EXPERT\"\n\n");
    printf("Enter the Name of  the player:");
    scanf(" %[^\n]", p1);
    char level[10];
    printf("\n");
    printf("Enter your desired level:");
    scanf("%s",level);
if(strcmp(level,"EASY")==0) {
    printf("\n");
printf(" \u263A ------------------EASY LEVEL------------------ \u263A\n");
printf("\n");
    round1(&score1);
    printf("\n");
    round1(&score1);
    printf("\n");
    round1(&score1);
    printf("\n");
    division(&score1);
    printf("\n");
    equation(&score1);
    printf("\n");
    printf("%s score in easy level is:%d\n\n",p1,score1);
    printf("\u263A ------------------EASY LEVEL ENDED ------------------ \u263A");
}
if(strcmp(level,"MEDIUM")==0)  {
 printf(" \u263A ------------------MEDIUM LEVEL------------------ \u263A\n");
    srand(time(NULL));
    int b = generateRandomNumberDivisible(1, 20, 1);
    int a = generateRandomNumberDivisible(b, 20, b);
    int f = generateRandomNumberDivisible(1, 20, 1);
    int e = generateRandomNumberDivisible(1, 20, f);
    int c = generateRandomNumberDivisible(1, 20, 1);
    int d = generateRandomNumberDivisible(1, 20, 1);
    int g = generateRandomNumberDivisible(1, 20, 1);
    int h = generateRandomNumberDivisible(1, 20, 1);
int actual_answer = calculateResult(a, b, c, d, e, f, g, h);
printf("\n");
printf("Problem: i = (%d / %d * %d) + %d - (%d / %d) + %d * %d\n", a, b, c, d, e, f, g, h);
 printf("Your answer: ");
    int user_answer;
    scanf("%d", &user_answer);
if (user_answer == actual_answer ) {
        printf("Correct! \u263A \n");
        score1=score1+50;
    } else {
        printf("wrong answer better luck next time\n");
        Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
        printf("The correct answer is %d.\n", actual_answer);
    }
    printf("\n");
    equations(&score1);
    printf("\n");
    riddles_2(&score1);
    printf("\n");
    srand(time(NULL));
    int n = 4; // fixed value of n
int choice = rand() % 6 + 1;
    int side, length, width, base, height, diagonal1, diagonal2;
    float correct_area;
switch (choice) {
        case 1:
            side = random_int(2, 100);
            correct_area = calculate_square_area(side);
            printf("Find the area of a square with side length %d?\n", side);
            print_square(n);
            break;
        case 2:
            length = random_int(2, 100);
            width = random_int(2, 100);
            correct_area = calculate_rectangle_area(length, width);
            printf("Find the area of a rectangle with length %d and width %d?\n", length, width);
            print_rectangle(n, 2 * n - 1);
            break;
        case 3:
            base = random_int(2, 100);
            height = random_int(2, 100);
            correct_area = calculate_triangle_area(base, height);
            printf("Find the area of a triangle with base length %d and height %d?\n", base, height);
            print_triangle(n);
            break;
        case 4:
            base = random_int(2, 100);
            height = random_int(2, 100);
            correct_area = calculate_parallelogram_area(base, height);
            printf("Find the area of a parallelogram with base length %d and height %d?\n", base, height);
            print_parallelogram(n);
            break;
        case 5:
            diagonal1 = random_int(2, 100);
            diagonal2 = random_int(2, 100);
            correct_area = calculate_rhombus_area(diagonal1, diagonal2);
            printf("Find the area of a rhombus with diagonal lengths %d and %d?\n", diagonal1, diagonal2);
            print_rhombus(n);
            break;
        case 6:
            side = random_int(2, 100);
            correct_area = calculate_hexagon_area(side);
            printf("Find the area of a hexagon with side length %d?\n", side);
            print_hexagon(n);
            break;
    }
 float uanswer;
    printf("Answer(upto 2 decimals): ");
    scanf("%f", &uanswer);
if (roundf(uanswer * 100) == roundf(correct_area * 100)) {
        printf("Correct! \u263A \n");
        score1=score1+50;
    } else {
        printf("Oops! The correct answer is %.2f.\n", correct_area);
        Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    }
      choice = rand() % 16 + 1; 
      printf("\n");
    switch(choice) {
        case 1:
            hoursToMinutes(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
        case 2:
            hoursToSeconds(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
        case 3:
            daysToHours(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
        case 4:
            yearsToDays(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
        case 5:
            yearsToHours(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
        case 6:
            decadesToMonths(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
        case 7:
            decadesToWeeks(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
        case 8:
            kilometersToMeters(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
        case 9:
            metersToMillimeters(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
        case 10:
            decimetersToCentimeters(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
        case 11:
            kilogramsToMilligrams(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
        case 12:
            rupeesToPaise(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
        case 13:
            litresToMillilitres(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
        case 14:
            millimetersToNanometers(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
        case 15:
            centuaryToYears(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
        case 16:
            centuaryToDecades(&score1);
            printf("\n");
            printf("%s score in medium level is %d\n",p1,score1);
            break;
    }
    printf("\n");
printf("\u263A ---------------MEDIUM LEVEL ENDED------------------\u263A\n");
    }
if(strcmp(level,"DIFFICULT")==0)  {
printf(" \u263A ------------------DIFFICULT LEVEL------------------ \u263A\n"); 
printf("\n");
  AP(&score1);
  printf("\n");
  GP(&score1);
  printf("\n");
  Quadratic(&score1);
  printf("\n");
  riddles_3(&score1);
  printf("\n");
  printf("%s score in difficult level is %d\n",p1,score1);
  printf("\n");
 printf(" \u263A ------------------DIFFICULT LEVEL ENDED------------------ \u263A\n"); 
}
if(strcmp(level,"EXPERT")==0) {
 printf(" \u263A ------------------EXPERT LEVEL------------------ \u263A\n");
 printf("\n");
 probabilty(&score1);
 printf("\n");
 generate_question(&score1);
 printf("\n");
 srand(time(NULL));
int coefficients[6], derivative[6];
    int x, user_answer, correct_answer;
 for (int i = 0; i < 6; i++) {
        coefficients[i] = rand() % 10 + 1; 
    }
 calculate_derivative_coefficients(coefficients, derivative);
 x = (int)(rand() % 10) / 2.0; 
 diff_question(coefficients);
printf("Evaluate the derivative at x = %d\n", x);
correct_answer = evaluate_polynomial(derivative, x);
 printf("Enter your answer: ");
    scanf("%ld", &user_answer);
 if (fabs(user_answer - correct_answer) < 0.001) {
        printf("Correct! \u263A\n");
        score1=score1+85;
    } else {
        printf("Incorrect. The correct answer is %d\n", correct_answer);
        Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    }
    printf("\n");
    srand(time(NULL));
    double parameters[6];
    generate_random_parameters(parameters);
    int value = (int)(rand() % 100) / 10;

    printf("Expression: ");
    for (int i = 5; i >= 0; i--) {
        printf("%.0fx^%d ", parameters[i], i);
        if (i > 0) {
            printf("+ ");
        }
    }
    printf("\n");

    printf("Value of variable: %d\n", value);

    double integral = calculate_integral(parameters, value);

    printf("Enter your answer for the integral: ");
    double user_result;
    scanf("%lf", &user_result);

    if (fabs(user_result - integral) < EPSILON) {
        printf("Correct! \u263A\n");
        score1=score1+85;
    } else {
        printf("Wrong! The correct answer is approximately: %.2lf\n", integral);
        Beep(500,1000);
          Beep(500,1000); 
          Beep(500,1000);
    }
    printf("\n");
printf("%s score in expert level is %d\n",p1,score1);
printf("\n");
printf(" \u263A-------------EXPERT LEVEL ENDED-------------------\u263A\n");
 }
 return 0;
}
