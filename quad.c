#include "quad.h"

Quad* genQuad(int s1, int s2, int s3) {
    Quad *newQuad = NULL;

    newQuad = addQuadList(&quadTable, quadNumber);

    newQuad->s1 = s1;
    newQuad->s2 = s2;
    newQuad->s3 = s3;

	//on incremente la variable global du nombre de quad genere
    quadNumber++;

    return newQuad;
}

Quad* addQuadList(Quad **quad, int index) {
    Quad *newQuad;

	//on verifie si on peut encore generer un quad (memoire)
    if(!(newQuad = malloc(sizeof(Quad)))) {
        return (NULL);
    }

    newQuad->index = index;
    newQuad->next  = NULL;

	//on met a jour la table des quads avec le quad genere
    if(*quad == NULL) {
        *quad = newQuad;
    } else {
        Quad *temp = *quad;

		//on recupere le dernier quad genere dans la table des symbols pour mettre a jour son pointeur next
        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newQuad;
    }

    return newQuad;
}

void printQuad(Quad *quad) {
    printf("\n\n##### QUADS TABLE #####\n");

    while(quad){
		printf("Quad #%d: ", quad->index);

		int label = quad->s3;
		
		symbol* tmp1 = (symbol*)symTable[quad->s1];
		symbol* tmp2 = (symbol*)symTable[quad->s2];
		symbol* tmp3 = (symbol*)symTable[quad->s3];

        switch(quad->quadType) {

        }

        printf("\n");
        
        quad = quad->next;
    }

    printf("\n----------------------------------------------");
}

void printMips(Quad *quad) {
    printf("\t.text\n");

    while(quad) {
		int label = quad->s3;
		
		symbol* tmp1 = (symbol*)symTable[quad->s1];
		symbol* tmp2 = (symbol*)symTable[quad->s2];
		symbol* tmp3 = (symbol*)symTable[quad->s3];
		
		if(quad->quadType != Q_FUNC) printf("j_%d\n", quad->index);
		
        switch(quad->quadType) {

        }
        printf("\n");
        quad = quad->next;
	}

    printf("\n----------------------------------------------\n");
}
