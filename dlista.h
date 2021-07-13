


//#include "dlista_funcion.h"

 typedef struct dl_ElementoLista{ 
 char *dato; 
 struct dl_ElementoLista *anterior;
 struct dl_ElementoLista *siguiente; 
 } dl_Elemento;

 typedef struct dl_ListaIdentificar{
 dl_Elemento *inicio;
 dl_Elemento *fin;
 int tamaño;
 } dl_Lista;

 /* inicialización de la lista */
 void inicialización (dl_Lista * lista); 
 dl_Elemento *alloc (dl_Elemento * nuevo_elemento);

 /* INSERCION */ 
 int ins_en_lista_vacia (dl_Lista * lista, char *dato);
 int ins_inicio_lista(dl_Lista * lista, char *dato);
 int ins_fin_lista(dl_Lista * lista, char *dato);
 int ins_después (dl_Lista * lista, char *dato, int pos);
 int ins_antes (dl_Lista * lista, char *dato, int pos);

 /*ELIMINACION*/
 int sup(dl_Lista *liste, int pos);
 void muestra (dl_Lista * lista);

/**************************/ 
 void muestra_inv (dl_Lista * lista);
 void destruir (dl_Lista * lista);




