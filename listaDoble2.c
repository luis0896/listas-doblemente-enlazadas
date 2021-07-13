

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#include "dlista.h"
#include "dlista_funcion.h"




/// INICIO DE MAIN

int main (void){  
int elección = 0,pos;  
char *dato;  
dato = malloc(50);  
dl_Lista *lista;  
dl_Elemento *piloto = NULL; 
lista = (dl_Lista *) malloc (sizeof(dl_Lista)); 
inicialización(lista);  
while(elección != 7){   
elección = menu(lista);    
switch(elección){      
case 1:             
printf("Ingrese un elemento: ");      
scanf("%s",dato);      
getchar();      
if(lista->tamaño == 0)               
inserción_en_lista_vacia(lista,dato);      
else               
ins_inicio_lista(lista, dato);      
printf("%d elementos: deb=%s,fin=%s ", lista->tamaño,lista->inicio->dato,lista->fin->dato);      muestra(lista);      
break;      
case 2:      
printf("Ingrese un elemento: ");      
scanf("%s",dato);      
getchar();      
ins_fin_lista(lista, dato);      
printf("%d elementos: deb=%s,fin=%s ",  lista->tamaño,lista->inicio->dato,lista->fin->dato);      muestra(lista);     
break;      
case 3:      
if(lista->tamaño == 1){           
printf("Utilizar la inserción al inicio o al final (Ingrese Menu: 1 ó 2)\n");        
break;      }      
printf("Ingrese un elemento: ");      
scanf("%s",dato);      
getchar();      
do{                 
printf("Ingrese la posición: ");   
scanf("%d",&pos);      }
while (pos < 1 || pos > lista->tamaño);      
getchar();      
ins_antes(lista,dato,pos);      
printf("%d elementos: deb=%s fin=%s ",         lista->tamaño,lista->inicio->dato,lista->fin->dato);      
muestra(lista);      
break;      
case 4:      
if(lista->tamaño == 1){             
printf("Utilizar la inserción al inicio o al final (Ingrese Menu: 1 ó 2)\n");      
break;      
}      
printf("Ingrese un elemento: ");      
scanf("%s",dato);      
getchar();      
do{                 
printf("Ingrese la posicion: ");   
scanf("%d",&pos);      
}
while (pos < 1 || pos > lista->tamaño);      
getchar();      
ins_después(lista,dato,pos);      
printf("%d elementos: deb=%s,fin=%s ",                    lista->tamaño,lista->inicio->dato,lista->fin->dato);      
muestra(lista);      
break;      
case 5:      
do{                 
printf("Ingrese la posición : ");   
scanf("%d",&pos);      
}
while (pos < 1 || pos > lista->tamaño);      
getchar();      
sup(lista,pos);      
if(lista->tamaño != 0)               
printf("%d elementos: deb=%s,fin=%s ",     lista->tamaño,lista->inicio->dato,lista->fin->dato);      else               
printf("liste vide : %d elementos",lista->tamaño);      
muestra(lista);      
break;      
case 6:      
destruir(lista);      
printf("la lista ha sido destruida: %d elementos\n",lista->tamaño);      
break;    
}  
}  
return 0;}





