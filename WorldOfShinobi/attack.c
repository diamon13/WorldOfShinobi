
#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "attack.h"


ATTACK* createAttack(void)
{
	ATTACK *pAttack;

	/* allocate the object */
	pAttack = malloc(sizeof(*pAttack));
	if (NULL == pAttack)
	{
		return NULL;
	}

	/* reset the object */
	memset(pAttack, 0, sizeof(*pAttack));

	return (ATTACK *) pAttack;
}

ATTACK* createAllAttack(char* NameCategory[])
{
	FILE *f;
	ATTACK *pList;
	char path[32]="attack\\";
	char word[16];

	pList = NULL;
	strcat(NameCategory, ".txt");
	strcat(path, NameCategory);
	f = fopen(path, "r");
	while (!feof(f))
	{
		ATTACK *pAttack;
		pAttack=createAttack();
		fscanf(f, "%s %d %d", &(pAttack->Name), &(pAttack->Damage), &(pAttack->Cost));
		pAttack->pEffect = createAllEffect(f);
		word[0] = '\0';
		do {
			if (pAttack->Description[0] != '\0')
			{
				strcat(pAttack->Description, " ");
			}
			strcat(pAttack->Description, word);	
			fscanf(f, "%s", word);
		} while(word[0] != '@');
		if (pList==NULL)
		{
			pList=pAttack;
		}
		else
		{
			pList->pNext=pAttack;
			pAttack->pPrev=pList;
			pList=pAttack;
		}		
	}
	fclose(f);
	return (ATTACK *) pList;
}

ATTACK* sortAttack(ATTACK* pAttack)
{
	if (pAttack->pPrev != NULL)
	{
		pAttack = pAttack->pPrev;
	}
}