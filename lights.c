#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include "alt_types.h"
#include <string.h>

int main()
{
float a, b;
float add,sub,mul,div;
float sina, cosa;
float tana, loga;
float expa;
int oper;
float mem,mem_add_1, mem_add_2,mem_add_3,mem_add_4,mem_add_5;
float mem_add_6, mem_add_7, mem_add_8, mem_add_9;

unsigned char * SW;
unsigned char * LEDG;
unsigned char * sdram;
unsigned char * reset;
SW = (unsigned char *)0x01003000;
LEDG = (unsigned char *)0x01003010;
sdram = (unsigned char *)0x00800000;
reset = (unsigned char *)0x01001000;

printf("Beginning.\n");

FILE *fp;
fp = fopen("/dev/lcd", "w");

mem=0;

printf("test.\n");
while(1){

*LEDG=*SW;
oper= *SW;
float usr_input;
char operation,operation2,operation3;
float result;

switch(oper){
    case 0:
   
    break;
    
    case 1: //Operation
        printf("please enter a operand: a=add s=sub m=mul d=div h=sin j=cos l=tan p=log o=exp\n");
        scanf(" %c",&operation);
        if (operation == 'a'){
            printf("enter the first floating point number:\n");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            
            printf("enter the second floating point number:\n");
            scanf("%f", &usr_input);
            b = usr_input;
            fprintf(fp,"b: %.5f\n", b);
            
            add=a + b;
            result = add;
        fprintf(fp,"result: %.5f\n",add);
        }
          if (operation == 's'){
            printf("enter the first floating point number:\n");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            
            printf("enter the second floating point number:\n");
            scanf("%f", &usr_input);
            b = usr_input;
            fprintf(fp,"b: %.5f\n", b);
            
            sub=a - b;
            result=sub;
        fprintf(fp,"result: %.5f\n",sub);
        }
        if (operation == 'm'){
            printf("enter the first floating point number:\n");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            
            printf("enter the second floating point number:\n");
            scanf("%f", &usr_input);
            b = usr_input;
            fprintf(fp,"b: %.5f\n", b);
            
            mul=a * b;
            result = mul;
        fprintf(fp,"result: %.5f\n",mul);
        }
         if (operation == 'd'){
            printf("enter the first floating point number:\n");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            
            printf("enter the second floating point number:\n");
            scanf("%f", &usr_input);
            b = usr_input;
            fprintf(fp,"b: %.5f\n", b);
            if (b == 0){
            fprintf(fp,"math error");
            break;
            }
            div=a / b;
            result=div;
        fprintf(fp,"result: %.5f\n",div);
        }
        if (operation == 'h'){
            printf("enter the floating point number:\n");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            
            sina=sin(a);
            result=sina;
        fprintf(fp,"result: %.5f\n",sina);
        }
        if (operation == 'j'){
            printf("enter the floating point number:\n");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            
            cosa=cos(a);
            result=cosa;
        fprintf(fp,"result: %.5f\n",cosa);
        }
           if (operation == 'l'){
            printf("enter the floating point number:\n");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            
            tana=tan(a);
            result=tana;
        fprintf(fp,"result: %.5f\n",tana);
        }
           if (operation == 'p'){
            printf("enter the floating point number:\n");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            if (a == 0){
            fprintf(fp,"math error");
            break;
            }
            loga=log10(a);
            result=loga;
        fprintf(fp,"result: %.5f\n",loga);
        }
        if (operation == 'o'){
            printf("enter the floating point number:\n");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            if (a == 0){
            fprintf(fp,"math error");
            break;
            }
            expa=exp(a);
            result=expa;
        fprintf(fp,"result: %.5f\n",expa);
        }
    break;
    case 2: // memory store
      if ( result != 0){
      mem = result;
      }
      //mem_add_2 = sub;
      //mem_add_3 = mul;
      //mem_add_4 = div;
     // mem_add_5 = sina;
      //mem_add_6 = cosa;
      //mem_add_7 = tana;
      //mem_add_8 = loga;
      //mem_add_9 = expa;
     fprintf(fp,"stored to memory.\n");
    break;
    case 4: // next operation
      
      printf("please enter a operand: a=add s=sub m=mul d=div h=sin j=cos l=tan p=log o=exp i=memory\n");
        scanf(" %c",&operation2);
        if (operation2 == 'i'){
           printf("please enter a operand: a=add s=sub m=mul d=div h=sin j=cos l=tan p=log o=exp\n"); 
           scanf(" %c",&operation3);
            
            if (operation3 == 'a'){
 
            add=mem + mem;
            result = add;
        fprintf(fp,"result: %.5f\n",add);
        }
          if (operation3 == 's'){
           
            sub=mem - mem;
            result=sub;
        fprintf(fp,"result: %.5f\n",sub);
        }
        if (operation3 == 'm'){
          
            mul=mem * mem;
            result = mul;
        fprintf(fp,"result: %.5f\n",mul);
        }
         if (operation3 == 'd'){
            if (mem == 0){
            fprintf(fp,"math error");
            break;
            }
            div=mem / mem;
            result=div;
        fprintf(fp,"result: %.5f\n",div);
        }
        if (operation3 == 'h'){
        
            sina=sin(mem);
            result=sina;
        fprintf(fp,"result: %.5f\n",sina);
        }
        if (operation3 == 'j'){
            
            cosa=cos(mem);
            result=cosa;
        fprintf(fp,"result: %.5f\n",cosa);
        }
           if (operation3 == 'l'){
          
            tana=tan(mem);
            result=tana;
        fprintf(fp,"result: %.5f\n",tana);
        }
           if (operation3 == 'p'){
            if (mem == 0){
            fprintf(fp,"math error");
            break;
            }
            loga=log10(mem);
            result=loga;
        fprintf(fp,"result: %.5f\n",loga);
        }
        if (operation3 == 'o'){
          
            expa=exp(mem);
            result=expa;
        fprintf(fp,"result: %.5f\n",expa);
        }       
            
        }
        if (operation2 == 'a'){
            printf("enter the floating point number:");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
             
            add=a + mem;
            result= add;
        fprintf(fp,"result: %.5f\n",add);
        }
          if (operation2 == 's'){
            printf("enter the floating point number:");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
       
            sub=mem - a;
            result= sub;
        fprintf(fp,"result: %.5f\n",sub);
        }
        if (operation2 == 'm'){
            printf("enter the floating point number:");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            
            mul=a * mem;
            result = mul;
        fprintf(fp,"result: %.5f\n",mul);
        }
         if (operation2 == 'd'){
            printf("enter the first floating point number:");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            if (a == 0){
            fprintf(fp,"math error");
            break;
            }
            div=mem / a;
            result = div;
        fprintf(fp,"result: %.5f\n",div);
        }
        if (operation2 == 'h'){
            printf("enter the floating point number:");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            
            sina=sin(a);
            fprintf(fp,"result: %.5f\n",sina);
            
            printf("do you wish to a-add s-sub m-mul d-div sin(a)");
            scanf(" %c",&operation2);
            if (operation2 == 'a'){
                sina= sina+mem;
                result = sina;
                 fprintf(fp,"result: %.5f\n",sina);
            }
            if (operation2 == 's'){
                sina= mem-sina;
                result = sina;
                fprintf(fp,"result: %.5f\n",sina);
            }
            if (operation2 == 'm'){
                sina= sina*mem;
                result = sina;
                 fprintf(fp,"result: %.5f\n",sina);
            }
            if (operation2 == 'd'){
                sina= mem/sina;
                result = sina;
                 fprintf(fp,"result: %.5f\n",sina);
            }
        }
        if (operation2 == 'j'){
            printf("enter the floating point number:");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            
            cosa=cos(a);
            
        fprintf(fp,"result: %.5f\n",cosa);
        
          printf("do you wish to a-add s-sub m-mul d-div cos(a)");
            scanf(" %c",&operation2);
            if (operation2 == 'a'){
                cosa= cosa+mem;
                result = cosa;
                 fprintf(fp,"result: %.5f\n",cosa);
            }
            if (operation2 == 's'){
                cosa= mem-cosa;
                result = cosa;
                fprintf(fp,"result: %.5f\n",cosa);
            }
            if (operation2 == 'm'){
                cosa= cosa*mem;
                result = cosa;
                 fprintf(fp,"result: %.5f\n",cosa);
            }
            if (operation2 == 'd'){
                cosa= mem/cosa;
                result = cosa;
                 fprintf(fp,"result: %.5f\n",cosa);
            }
        
        }
           if (operation2 == 'l'){
            printf("enter the floating point number:");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            
            tana=tan(a);
        fprintf(fp,"result: %.5f\n",tana);
            
              printf("do you wish to a-add s-sub m-mul d-div tan(a)");
            scanf(" %c",&operation2);
            if (operation2 == 'a'){
                tana= tana+mem;
                result = tana;
                 fprintf(fp,"result: %.5f\n",tana);
            }
            if (operation2 == 's'){
                tana= mem-tana;
                 result = tana;
                fprintf(fp,"result: %.5f\n",tana);
            }
            if (operation2 == 'm'){
                tana= tana*mem;
                 result = tana;
                 fprintf(fp,"result: %.5f\n",tana);
            }
            if (operation2 == 'd'){
                tana= mem/tana;
                 result = tana;
                 fprintf(fp,"result: %.5f\n",tana);
            }
        
        }
           if (operation2 == 'p'){
            printf("enter the floating point number:");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            if (a == 0){
            fprintf(fp,"math error");
            break;
            }
            loga=log10(a);
        fprintf(fp,"result: %.5f\n",loga);
        
             printf("do you with to a-add s-sub m-mul d-div log(a)");
            scanf(" %c",&operation2);
            if (operation2 == 'a'){
                loga= loga+mem;
                 result = loga;
                 fprintf(fp,"result: %.5f\n",loga);
            }
            if (operation2 == 's'){
                loga= mem-loga;
                     result = loga;
                fprintf(fp,"result: %.5f\n",loga);
            }
            if (operation2 == 'm'){
                loga= loga*mem;
                     result = loga;
                 fprintf(fp,"result: %.5f\n",loga);
            }
            if (operation2 == 'd'){
                loga= mem/loga;
                     result = loga;
                 fprintf(fp,"result: %.5f\n",loga);
            }
        }
        if (operation2 == 'o'){
            printf("enter the floating point number:");
            scanf("%f", &usr_input);
            a = usr_input;
            fprintf(fp,"a: %.5f\n", a);
            
            expa=exp(a);
            fprintf(fp,"result: %.5f\n",expa);
        
             printf("do you with to a-add s-sub m-mul d-div exp(a)");
            scanf(" %c",&operation2);
            if (operation == 'a'){
                expa= expa+mem;
                     result = expa;
                 fprintf(fp,"result: %.5f\n",expa);
            }
            if (operation2 == 's'){
                expa= mem-expa;
                 result = expa;
                fprintf(fp,"result: %.5f\n",expa);
            }
            if (operation2 == 'm'){
                expa= expa*mem;
                 result = expa;
                 fprintf(fp,"result: %.5f\n",expa);
            }
            if (operation2 == 'd'){
                expa= mem/expa;
                 result = expa;
                 fprintf(fp,"result: %.5f\n",expa);
            }
        }
    break;  
}
}
return 0;
}




