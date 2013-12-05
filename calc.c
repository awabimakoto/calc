#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 1
#define ADD 2
#define SUB 3
#define MUL 4
#define DIV 5
#define LPAREN 6
#define RPAREN 7
#define ERROR 255
char *op;
char *expression;
int IsDigit(char ch);
int getop();
double term();
double expr();
double factor();
void main(int argc,char *argv[]){
  expression=(char *)malloc(sizeof(char));
  op=(char *)malloc(sizeof(char));
  if(argc>1)
    expression=argv[1];
  else
    scanf("%s",expression);
  printf("%g\n",expr());}
int IsDigit(char ch){
  if(ch>='0' && ch<='9' || ch=='.')
    return 1;
  return 0;}
int getop(){
  char *pop=op;
  while(*expression==' ' || *expression=='\t')
    expression++;
  switch(*expression){
  case '+':expression++;return ADD;
  case '-':expression++;return SUB;
  case '*':expression++;return MUL;
  case '/':expression++;return DIV;
  case '(':expression++;return LPAREN;
  case ')':expression++;return RPAREN;
  default:break;}
  if(IsDigit(*expression)){
    while(IsDigit(*expression)){
      *pop=*expression;
      expression++;
      pop++;}
    *pop='\0';
    return NUM;}
  return ERROR;}
double expr(){
  double temp=term();
  int optype;
  while(*expression == '+' || *expression == '-'){
    optype=getop();
    switch(optype){
    case ADD:temp+=term();break;
    case SUB:temp-=term();break;
    default:break;}}
  return temp;}
double term(){
  double temp=factor();
  int optype;
  while(*expression=='*' || *expression=='/'){
    optype=getop();
    switch(optype){
    case MUL:temp*=factor();break;
    case DIV:temp/=factor();break;
    default:break;}}
  return temp;}
double factor(){
  double number;
  switch(getop()){
  case NUM:number=atof(op);break;
  case LPAREN:number=expr();
    if(getop()!=RPAREN)
      printf("lost ')' in the expr.\n");
    break;
  default:break;}
  return number;}
