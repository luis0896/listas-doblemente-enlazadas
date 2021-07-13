
/*inicialización
Esta operación tiene que ser realizada antes de otra operación sobre la lista.
Esta empezará indicando el puntero inicio y también el puntero fin con el puntero NULL y, además, el tamaño con el valor 0.
*/
void inicialización (dl_Lista * lista)
{  
lista->inicio = NULL;  
lista->fin = NULL; 
lista->tamaño = 0;}

/*inserción_en_lista_vacia
Los corredores anterior y siguiente serán unidos al nuevo elemento  Y  estos apuntan a NULL,  los punteros de inicio y fin señalará hacia el nuevo elemento y el tamaño es actualizado.
Este es el esquema basico tanto para insertar al inicio con al final.
*/
int inserción_en_lista_vacia (dl_Lista * lista, char *dato){  
dl_Elemento *nuevo_elemento;  
if ((nuevo_elemento = alloc (nuevo_elemento)) == NULL)    
return -1;  
strcpy (nuevo_elemento->dato, dato);  
nuevo_elemento->anterior = NULL; 
nuevo_elemento->siguiente = NULL;  
lista->inicio = nuevo_elemento; 
 lista->fin = nuevo_elemento;  
lista->tamaño++;  
return 0;
}
int ins_inicio_lista(dl_Lista * lista, char *dato)
{  
dl_Elemento *nuevo_elemento; 
if ((nuevo_elemento = alloc (nuevo_elemento)) == NULL)    
return -1;  
strcpy (nuevo_elemento->dato, dato);  
nuevo_elemento->anterior = NULL;  
nuevo_elemento->siguiente = lista->inicio; 
lista->inicio->anterior = nuevo_elemento;  
lista->inicio = nuevo_elemento;  
lista->tamaño++; 
return 0;}
int ins_fin_lista(dl_Lista * lista, char *dato)
{  
dl_Elemento *nuevo_elemento;
if ((nuevo_elemento = alloc (nuevo_elemento)) == NULL)    
return -1; 
strcpy (nuevo_elemento->dato, dato);  
nuevo_elemento->siguiente = NULL;  
nuevo_elemento->anterior = lista->fin; 
lista->fin->siguiente = nuevo_elemento;  
lista->fin = nuevo_elemento;  
lista->tamaño++;  
return 0;}

int ins_después (dl_Lista * lista, char *dato, int pos)
{  
int i;  
dl_Elemento *nuevo_elemento, *actual;  
if ((nuevo_elemento = alloc (nuevo_elemento)) == NULL)    
return -1;  
strcpy (nuevo_elemento->dato, dato);  
actual = lista->inicio;  
for (i = 1; i < pos; i++)   
actual = actual->siguiente;  
nuevo_elemento->siguiente = actual->siguiente;  
nuevo_elemento->anterior = actual;  
if(actual->siguiente == NULL)    
lista->fin = nuevo_elemento;  
else    
actual->siguiente->anterior = nuevo_elemento;  
actual->siguiente = nuevo_elemento;  
lista->tamaño++;  
return 0;
}

/*ins_antes
Creamos memoria al nuevo elemento.
Rellenado del campo de datos del nuevo elemento.
Elección de una posición en la lista (la inserción se hará después de la posición elegida).
El puntero siguiente del nuevo elemento apunta hacia el elemento actual.
*/
int ins_antes (dl_Lista * lista, char *dato, int pos)
{ 
int i;  
dl_Elemento *nuevo_elemento, *actual;  if ((nuevo_elemento = alloc (nuevo_elemento)) == NULL)    
return -1;  
strcpy (nuevo_elemento->dato, dato);  
actual = lista->inicio; 
for (i = 1; i < pos; i++)    
actual = actual->siguiente;  
nuevo_elemento->siguiente = actual;  
nuevo_elemento-> anterior = actual->anterior;  
if(actual->anterior == NULL)   
lista->inicio = nuevo_elemento;  
else    
actual->anterior->siguiente = nuevo_elemento;  
actual->anterior = nuevo_elemento;  
lista->tamaño++;  
return 0;
}
int sup(dl_Lista *lista, int pos){  
int i;  
dl_Elemento *sup_elemento,*actual;    
if(lista->tamaño == 0)    
return -1;  
if(pos == 1){ 

/* eliminación de 1er elemento 
La posición elegida es 1 el caso de eliminación del primer elemento de la lista, el puntero sup_elemento va a contener la dirección del primer elemento.
El puntero inicio contendrá la dirección contenida por el puntero siguiente del primero de los elemento que deseamos eliminar,si este puntero vale NULL entonces actualizamos el puntero fin ya que estamos en el caso de una lista con un solo elemento, si no hacemos apuntar el puntero anterior del 2do elemento hacia NULL.
*/  
sup_elemento = lista->inicio;   
lista->inicio = lista->inicio->siguiente;    
if(lista->inicio == NULL)      
lista->fin = NULL;    
else      
lista->inicio->anterior == NULL;  }
else if(pos == lista->tamaño){

 /* eliminacion del ultimo elemento 
 La posición elegida es igual al número de elementos de la lista, el puntero sup_elemento contendrá la dirección del último elemento.
Hacemos apuntar al puntero siguiente del penúltimo elemento,es el elemento hacia el que apunta el puntero anterior del último elemento, hacia NULL y actualizamos el puntero fin.
 */    
sup_elemento = lista->fin;    
lista->fin->anterior->siguiente = NULL;   
lista->fin = lista->fin->anterior;  }
else { 
/* eliminacion en otra parte
La posición elegida es aleatoria en la lista, el puntero sup_elemento contendrá la dirección del elemento a eliminar.
El puntero siguiente del elemento que antecede al elemento a eliminar apunta hacia la dirección contenida en el puntero siguiente del elemento a eliminar.
El puntero anterior del elemento que va después del elemento a eliminar apunta hacia la dirección contenida en el puntero anterior del elemento a eliminar y el tamaño de la lista será disminuida en 1 elemento.

 */    
actual = lista->inicio;    
for(i=1;i<pos;i++)    
actual = actual->siguiente;    
sup_elemento = actual;    
actual->anterior->siguiente = actual->siguiente;    
actual->siguiente->anterior = actual->anterior;  }  
free(sup_elemento->dato); 
free(sup_elemento);  
lista->tamaño--;  
return 0;
}
void destruir(dl_Lista *lista){  
while(lista->tamaño > 0)    sup(lista,1);}
dl_Elemento *alloc (dl_Elemento * nuevo_elemento){  
if ((nuevo_elemento = (dl_Elemento *) malloc (sizeof (dl_Elemento))) == NULL)    
return NULL;  
if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char)))      == NULL)    
return NULL;  
return nuevo_elemento;}
int menu (dl_Lista *lista){  
int elección;  if (lista->tamaño == 0){    
printf ("1. Adición del 1er elemento\n");    
printf ("2. Eliminar\n");  }  
else{    
printf ("1. Añadir al inicio de la lista\n");    
printf ("2. Añadir al final de la lista\n");    
printf ("3. Añadir antes de la posición especificada\n");    
printf ("4. Añadir después de la posición especificada\n");    
printf ("5. Eliminacion en la posicion especificada\n");    
printf ("6. Destruir la lista\n");    
printf ("7. Eliminar\n");  }  
printf ("\n\nElija: ");  
scanf ("%d", &elección);  getchar();  
if(lista->tamaño == 0 && elección == 2)    
elección = 7;  
return elección;}
int sup(dl_Lista *lista, int pos);

/*muestra
Para mostrar la lista entera podemos posicionarnos al inicio o al final de la lista (el puntero inicio o fin lo permitirá).
Luego utilizando el puntero siguiente o anterior de cada elemento, la lista es recorrida del 1er al ultimo elemento o del ultimo al 1er elemento.
La condición para detener es dada por el puntero siguiente del ultimo elemento que vale NULL en el caso de la lectura del inicio hacia el fin de la lista, o por el puntero anterior del 1er elemento que vale NULL, en el caso de una lectura del final hacia el inicio de la lista.
*/
void muestra(dl_Lista *lista){ 
dl_Elemento *actual; actual = lista->inicio; printf("[ ");
while(actual != NULL){  
printf("%s ",actual->dato);  actual = actual->siguiente; } 
printf("]\n");}void muestra_inv(dl_Lista *lista){
dl_Elemento *actual; actual = lista->fin; while(actual != NULL){  
printf("%s : ",actual->dato);  actual = actual->anterior; } 
printf("\n");}



