
#include "unit.h"
#include <malloc.h>
#include <stddef.h>
#include <stdio.h>

UNIT* createUnit(void)
{
	UNIT *pUnit;

	/* allocate the object */
	pUnit = malloc(sizeof(*pUnit));
	if (NULL == pUnit)
	{
		return NULL;
	}

	/* reset the object */
	memset(pUnit, 0, sizeof(*pUnit));

	return (UNIT *) pUnit;
}

void sortUnits(UNIT* pUnit)
{
	while(pUnit->pPrev!=NULL)
	{
		pUnit=pUnit->pPrev;
	}
}

UNIT* createAllUnits(void)
{
	FILE *f;
	UNIT *pList;
	pList = NULL;

	f = fopen("units.txt", "r");
	while (!feof(f))
	{
		UNIT *pUnit;
		pUnit=createUnit();
		fscanf(f, "%s %d %d %d %d %d %d", &(pUnit->Name), &(pUnit->Rang), &(pUnit->FullHP), &(pUnit->FullDefense), &(pUnit->FullMana), &(pUnit->FullAttack), &(pUnit->Concentration));
		if (pList==NULL)
		{
			pList=pUnit;
		}
		else
		{
			pList->pNext=pUnit;
			pUnit->pPrev=pList;
			pList=pUnit;
		}		
	}
	fclose(f);
	return (UNIT *) pList;
}
