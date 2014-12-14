#include "quad.h"

*Quad genQuad(QuadType qt, *Symbol arg1, *Symbol arg2, *Symbol res) {
    *Quad newQuad = NULL;

    newQuad = addQuadList(&quadTable, quadNumber);

    newQuad->arg1 = arg1;
    newQuad->arg2 = arg2;
    newQuad->res = res;
	newQuad->quadType = qt;
	
	//on incremente la variable global du nombre de quad genere
    quadNumber++;

    return newQuad;
}

*Quad addQuadList(**Quad quad, int index) {
    *Quad newQuad;

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
        *Quad temp = *quad;

		//on recupere le dernier quad genere dans la table des symbols pour mettre a jour son pointeur next
        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newQuad;
    }

    return newQuad;
}

void quadFree(*Quad q) {
	*Quad nextQuad = q->next;

	while(nextQuad != NULL){

		nextQuad = q->next;
		free(q);
		q = nextQuad;
	}
}

void printQuad(*Quad quad) {
    printf("\n\n##### START QUADS TABLE #####\n");

	while(quad != NULL){
		printf("Quad : LABEL : %d | ", quad->index);
		switch(quad->quadType){
			case Q_ASSIGN:
				printf("OP : Q_ASSIGNMENT | ");
				break;
			case Q_PLUS:
				printf("OP : Q_PLUS | ");
				break;
			case Q_MINUS:
				printf("OP : Q_MINUS | ");
				break;
			case Q_DIV:
				printf("OP : Q_DIVIDE | ");
				break;
			case Q_MULT:
				printf("OP : Q_MULTIPLY | ");
				break;
			default:
				printf("OP : UKNOWN | ");
				break;
		}
		printf("arg1 : %d ", quad->arg1->value);
		if(quad->arg2 != NULL){
			printf("| arg2 : %d ", quad->arg2->value);
		}
		printf("||| result : %s\n", quad->res->id);
		quad = quad->next;
	}
	
	printf("##### END QUADS TABLE #####\n");
    printf("\n----------------------------------------------");
}

void printMips(Quad *quad) {
    printf("\n\n##### START MIPS #####\n");

    while(quad) {
        switch(quad->quadType) {
			case Q_ASSIGN:
				printf("\tla $a0,%s\n", quad->res->id);
			    printf("\tli $v0 %s\n", quad->arg1->id);
			    printf("\tsw $t0 $a0");
				break;

			case Q_PLUS:
				printf("\tlw $t1,%s \n",quad->arg1->id); 
				printf("\tlw $t2,%s \n",quad->arg2->id); 
				printf("\tadd $t0,$t1,$t2\n");
				printf("\tsw $t0, %s",quad->res->id);
				break;

			case Q_MINUS:
				printf("\tlw $t1,%s\n", quad->arg1->id);
				printf("\tlw $t2,%s\n",quad->arg2->id);
				printf("\tsub $t0,$t1,$t2\n");
				printf("\tsw $t0 ,%s",quad->res->id);
				break;

			case Q_DIV:
				 printf("\tlw $t1,%s\n",quad->arg1->id);
				printf("\tlw $t2,%s\n",quad->arg2->id);
				printf("\tdiv $t0,$t1,$t2\n");
				printf("\tsw $t0 ,%s",quad->res->id);
				break;

			case Q_MULT:
				printf("\tlw $t1,%s\n",quad->arg1->id);
				printf("\tlw $t2,%s\n",quad->arg2->id);
				printf("\tmul $t0,$t1,$t2\n");
				printf("\tsw $t0, %s",quad->res->id);
				break;

			default:
				break;
        }
        printf("\n");
        quad = quad->next;
	}

	printf("##### END MIPS #####\n");
    printf("\n----------------------------------------------\n");
}
