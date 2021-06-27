#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*)malloc(sizeof(LinkedList));

    if (this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if (this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node *node;
	int length = ll_len(this);
	node = NULL;
	if (this != NULL && nodeIndex < length && nodeIndex > -1)
	{
		node = this->pFirstNode;
		for (int i = 0; i < nodeIndex; i++)
		{
			node = node->pNextNode;
		}
	}

    return node;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	Node *newNode;
	Node *prevNode;
	int len;
	len = ll_len(this);
	newNode = (Node*)malloc(sizeof(Node));

	if (this != NULL && nodeIndex <= len && nodeIndex > -1 && newNode != NULL){
		newNode->pElement = pElement; // se guarda el elemento al nodo

		if (nodeIndex == 0){ // si esta al principio
			newNode->pNextNode = this->pFirstNode;
			this->pFirstNode = newNode;
		}
		else{
			prevNode = getNode(this, nodeIndex - 1);
			if (len == nodeIndex){
				newNode->pNextNode = NULL;
				prevNode->pNextNode = newNode;
			}
			else{
				newNode->pNextNode = prevNode->pNextNode;
				prevNode->pNextNode = newNode;
			}
		}

		this->size ++;
		return 0;
	}
	free(newNode);//elimina el nodo creado en caso de que no se realice la carga
    return -1;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int len;
	len = ll_len(this);

    if (this != NULL)
    {
    	addNode(this, len, pElement);
    	return 0;
    }

    return -1;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	int len = ll_len(this);
    void* aux = NULL;

    if (this != NULL && index < len && index > -1){

    	Node *node;
    	node = getNode(this, index);
    	aux = node->pElement;
    }

    return aux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int len = ll_len(this);

    if (this != NULL && index < len && index > -1){

    	Node *node;
    	node = getNode(this, index);
    	node->pElement = pElement;
    	return 0;
    }
    return -1;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int len = ll_len(this);

	if (this != NULL && index < len && index > -1){
		Node *node;
		Node *prevNode;

		node = getNode(this, index);
		prevNode = getNode(this, index - 1);
		if (node != NULL)
		{
			if (index == 0){
				this->pFirstNode = node->pNextNode;// se salta al siguiente del que se elimina
			}
			else{
				if (index == len){
					prevNode->pNextNode=NULL;
				}
				else{
					prevNode->pNextNode = node->pNextNode;// el siguiente nodo del previo pasa a ser el siguiente
				}
			}
		}

		free(node);// libera el espacio en memoria
		this->size--;
		return 0;
	}
    return -1;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    if(this != NULL){
    	for(int i=ll_len(this);i>-1;i--){
    		ll_remove(this, i);
    	}
    	return 0;
    }

    return -1;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    if(this !=NULL){
    	ll_clear(this);
    	free(this);
    	return 0;
    }
    return -1;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    if(this != NULL){
    	int index;
    	int len;
    	Node *aux;

    	len=ll_len(this);
    	for(int i=0;i<len;i++){
    		aux=getNode(this, i);
    		if(aux->pElement==pElement){
    			index=i;
    	    	return index;
    		}
    	}
    }
    return -1;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	if(this != NULL){
		if(this->pFirstNode!=NULL){
			return 0;
		}else{
			return 1;
		}
	}

	return -1;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int len;
    len=ll_len(this);
    if(this != NULL && index > -1 && index < len+1){
		addNode(this, index, pElement);
		return 0;
    }

    return -1;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index>-1 && index<ll_len(this)+1){
    	returnAux=ll_get(this, index);
    	ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	if (this != NULL){
		if (ll_indexOf(this, pElement) != -1){
			return 1;
		}
		return 0;
	}
	return -1;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	if(this != NULL && this2 != NULL ){
		int aux;
		for(int i=0;i<ll_len(this2);i++){
			aux=ll_contains(this, ll_get(this2, i));
			if(aux==0){
				return 0;
			}
		}
		return 1;
	}
	return -1;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len;
    len=ll_len(this);

    if(this != NULL && from > -1 && from < len+1 && to>from && to<len+1){
    	void* element;
    	cloneArray=ll_newLinkedList();

    	if(cloneArray!=NULL){
    		for(int i=from;i<to;i++){
    			element=ll_get(this, i);
    			ll_add(cloneArray, element);
    		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this!=NULL){
    	cloneArray=ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    if(this !=NULL && pFunc!= NULL && (order==0 || order==1)){
    	int len;
    	void* iElement;
    	void * jElement;
    	void* aux;
    	int stand;
    	len=ll_len(this);
    	for(int i=0;i<len-1;i++){

    		for(int j=i+1 ;j<len;j++){
    			jElement=ll_get(this, j);
    			iElement=ll_get(this, i);
    			stand=pFunc(iElement, jElement);

    			if( stand== -1 && order==0 ){
    				aux = iElement;
    				ll_set(this, i, jElement);
    				ll_set(this, j, aux);
    			}else{
    				if(stand == 1 && order==1){
    					aux = iElement;
    					ll_set(this, i, jElement);
    					ll_set(this, j, aux);
    				}
    			}

    		}
    	}
    	return 0;
    }
    return -1;

}

