/* 
 * File:   main.cpp
 * Author: slenderman
 *
 * Created on 11 de marzo de 2014, 10:10 PM
 */
#include<iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

/*
 * 
 */
int esBisiesto(int anio){
    if((anio%4==0)&&!(anio%100==0)){
        //Bisiesto
        cout<< " Es Bisiesto";
                
        
    }else{
        if(anio%400==0){
        //Bisiesto
            cout<< " Es Bisiesto";
        }else{
        //no Bisiesto
            cout<< " No Es Bisiesto";
        }
    }
}

void esSemana(int Anio,int Mes, int dia){
    int a,b,c,s,e,f,semana;
    if((Mes == 01 || Mes == 02)){
         a = Anio-1;
         int x= a-1;
         //b = (a%4)-(a%100)+(a%400);
        b   =   floor(a/4)-floor(a/100)+floor(a/400);
      c   =   floor((x)/4)-floor((x)/100)+floor((x)/400);
      s   =   b-c;
      e   =   0;
        
         f   =   dia-1+(31*(Mes-1));
    }else{
           a   =   Anio;
           b   =   floor(a/4)-floor(a/100)+floor(a/400);
           c   =   floor((a-1)/4)-floor((a-1)/100)+floor((a-1)/400);
           s   =   b-c;
           e   =   s+1;
           f   =   dia+fabs(((153*(Mes-3))+2)/5)+58+s;
    }
    
    int g=(a+b)%7;
    int d= (f+g-e)%7;
    int n= f+3-d;
   
   
    if (n<0){
      //Si la variable n es menor a 0 se trata de una semana perteneciente al año anterior
      semana   =   53-floor((g-s)/5);
      
   } else if (n>(364+s)) {
      //Si n es mayor a 364 + $s entonces la fecha corresponde a la primera semana del año siguiente.
      semana   = 1;
      
   } else {
      //En cualquier otro caso es una semana del año actual.
      semana   =   floor(n/7)+1;
   };
   
   //return semana; //La función retorna una cadena de texto indicando la semana y el año correspondiente a la fecha ingresada 
  cout<< semana;  
};

int main(int argc, char** argv) {

    
    esBisiesto(2000);
    cout<<endl;
    //cout<< esSemana(2014,3,12);
    esSemana(2014,03,14);
    return 0;
}

