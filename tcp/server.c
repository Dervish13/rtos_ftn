#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#define MAX 20

char stack[25];
int top = -1;

void push(char item) {
   stack[++top] = item;
}

char pop() {
   return stack[top--];
}

//returns precedence of operators
int precedence(char symbol) {

   switch(symbol) {
      case '+':
      case '-':
         return 2;
         break;
      case '*':
      case '/':
         return 3;
         break;
      case '^':
         return 4;
         break;
      case '(':
      case ')':
      case '#':
         return 1;
         break;
   }
}

//check whether the symbol is operator?
int isOperator(char symbol) {

   switch(symbol) {
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':
      case '(':
      case ')':
         return 1;
      break;
         default:
         return 0;
   }
}

//converts infix expression to postfix
void convert(char infix[],char postfix[]) {
   int i,symbol,j = 0;
   stack[++top] = '#';

   for(i = 0;i<strlen(infix)-1;i++) {
      symbol = infix[i];

      if(isOperator(symbol) == 0) {
         postfix[j] = symbol;
         j++;
      } else {
         if(symbol == '(') {
            push(symbol);
         }else {
            if(symbol == ')') {

               while(stack[top] != '(') {
                  postfix[j] = pop();
                  j++;
               }

               pop();//pop out (.
            } else {
               if(precedence(symbol)>precedence(stack[top])) {
                  push(symbol);
               }else {

                  while(precedence(symbol)<=precedence(stack[top])) {
                     postfix[j] = pop();
                     j++;
                  }

                  push(symbol);
               }
            }
         }
      }
   }

   while(stack[top] != '#') {
      postfix[j] = pop();
      j++;
   }

  postfix[j]='\0';//null terminate string.
}

//int stack
int stack_int[MAX];
int top_int = -1;

void push_int(int item) {
   stack_int[++top_int] = item;
}

char pop_int() {
   return stack_int[top_int--];
}

//evaluates postfix expression
int evaluate(char *postfix){

   char ch;
   int i = 0,operand1,operand2;

   while( (ch = postfix[i++]) != '\0') {

      if(isdigit(ch)) {
	     push_int(ch-'0'); // Push the operand
      }else {
         //Operator,pop two  operands
         operand2 = pop_int();
         operand1 = pop_int();

         switch(ch) {
            case '+':
               push_int(operand1+operand2);
               break;
            case '-':
               push_int(operand1-operand2);
               break;
            case '*':
               push_int(operand1*operand2);
               break;
            case '/':
               push_int(operand1/operand2);
               break;
         }
      }
   }

   return stack_int[top_int];
}

void ObrisiRazmake(char* niz)
{
  char* i = niz;
  char* j = niz;
  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
      i++;
  }
  *i = 0;
}
int main() {
  // pravimo socket servera
  int server_socket;
  /* char jednacina[MAX] = {0}; */
  char postfix[MAX],infix[MAX];
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // adresa servera
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9494);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // vezi socket za IP i sin_port
  bind(server_socket, (struct sockaddr*)&server_address,
       sizeof(server_address));

  listen(server_socket, 1); // cekanje konekcije
  int client_socket1;
  client_socket1 = accept(server_socket, NULL, NULL);
  read(client_socket1, infix, sizeof(infix));
  printf("%s\n", infix);
  ObrisiRazmake(infix);
  float a;

  convert(infix,postfix);
  printf("Infix expression is: %s\n" , infix);
  printf("Postfix expression is: %s\n" , postfix);
  printf("Evaluated expression is: %d\n" , evaluate(postfix));
  a=evaluate(postfix);
  printf("%f",a);
  // posalji klijentu
  send(client_socket1, &a, sizeof(a), 0);
  // zatvori socket
  close(server_socket);
  return 0;
}
