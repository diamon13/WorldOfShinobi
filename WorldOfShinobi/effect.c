#include <malloc.h>
#include <stddef.h>
#include <stdio.h>

#include "effect.h"

EFFECT* createEffect(void)
{
	EFFECT *pEffect;

	/* allocate the object */
	pEffect = malloc(sizeof(*pEffect));
	if (NULL == pEffect)
	{
		return NULL;
	}

	/* reset the object */
	memset(pEffect, 0, sizeof(*pEffect));

	return (EFFECT *) pEffect;
}

void deleteEffect(EFFECT* pEffect)
{
	if (pEffect->pPrev!=NULL)
	{
		pEffect->pPrev->pNext = pEffect->pNext;
	}
	if (pEffect->pPrev!=NULL)
	{
		pEffect->pNext->pPrev = pEffect->pPrev;
	}
	free(pEffect);
}

void Paralysis(EFFECT* pEffect, UNIT* pObj, UNIT* pSubj)
{
	pObj->Speed = pObj->Speed - pEffect->Force;
	if (pObj->Speed < 0)
	{
		pObj->Speed = 0;
	}
	pEffect->Duration = pEffect->Duration - 1;
}

void Burning( EFFECT* pEffect,  UNIT* pObj,  UNIT* pSubj)
{
	pObj->HP = pObj->HP - pEffect->Force;
	if (pObj->HP < 0)
	{
		pObj->HP = 0;
	}
	pEffect->Duration = pEffect->Duration - 1;
}

void Poison( EFFECT* pEffect,  UNIT* pObj,  UNIT* pSubj)
{
	pObj->HP = pObj->HP - pEffect->Force;
	if (pObj->HP < 0)
	{
		pObj->HP = 0;
	}
	pObj->Attack = pObj->Attack - pEffect->Force;
	if (pObj->Attack < 0)
	{
		pObj->Attack = 0;
	}
	pObj->Speed = pObj->Speed - pEffect->Force;
	if (pObj->Speed < 0)
	{
		pObj->Speed = 0;
	}
	pEffect->Duration = pEffect->Duration - 1;
}

void Treatment( EFFECT* pEffect,  UNIT* pObj,  UNIT* pSubj)
{
	pObj->HP = pObj->HP + pEffect->Force;
	pEffect->Duration = pEffect->Duration - 1;
}
void VampireHP( EFFECT* pEffect,  UNIT* pObj,  UNIT* pSubj)
{
	if (pObj->HP < pEffect->Force)
	{
		pSubj->HP = pSubj->HP + pObj->HP;
		pObj->HP=0;
	}
	else
	{
		pObj->HP = pObj->HP - pEffect->Force;
		pSubj->HP = pSubj->HP + pEffect->Force;
	}
	pEffect->Duration = pEffect->Duration - 1;
}

void VampireMana( EFFECT* pEffect,  UNIT* pObj,  UNIT* pSubj)
{
	if (pObj->Mana < pEffect->Force)
	{
		pSubj->Mana = pSubj->Mana + pObj->Mana;
		pObj->Mana=0;
	}
	else
	{
		pObj->Mana = pObj->Mana - pEffect->Force;
		pSubj->Mana = pSubj->Mana + pEffect->Force;
	}
	pEffect->Duration = pEffect->Duration - 1;
}

void UpAttack( EFFECT* pEffect,  UNIT* pObj,  UNIT* pSubj)
{
	pSubj->Attack = pSubj->Attack + pEffect->Force;
	pEffect->Duration = pEffect->Duration - 1;
}

void UpSpeed( EFFECT* pEffect, UNIT* pObj, UNIT* pSubj)
{
	pSubj->Speed = pSubj->Speed + pEffect->Force;
	pEffect->Duration = pEffect->Duration - 1;
}

char* NameParalysis(void)
{
	return "Paralysis";
}
char* NameBurning(void)
{
	return "Burning";
}
char* NamePoison(void)
{
	return "Poison";
}
char* NameTreatment(void)
{
	return "Treatment";
}
char* NameVampireHP(void)
{
	return "VampireHP";
}
char* NameVampireMana(void)
{
	return "VampireMana";
}
char* NameUpAttack(void)
{
	return "UpAttack";
}
char* NameUpSpeed(void)
{
	return "UpSpeed";
}

EFFECT* createAllEffect(FILE* f)
{
	EFFECT *pList;
	char word[16];
	pList=NULL;
		do {
			EFFECT *pEffect;
			pEffect=createEffect();
			fscanf(f, "%s", word);
			if (word[0] != '@')
			{
				fscanf(f, "%d %d %d", &(pEffect->Duration), &(pEffect->Chance), &(pEffect->Force));
				if (word == "Paralysis")
				{
					pEffect->getName=&NameParalysis;
					pEffect->execute=&Paralysis;
				}
				else if (word == "Burning")
				{
					pEffect->getName=&NameBurning;
					pEffect->execute=&Burning;
				}
				else if (word == "Poison")
				{
					pEffect->getName=&NamePoison;
					pEffect->execute=&Poison;
				}
				else if (word == "Treatment")
				{
					pEffect->getName=&NameTreatment;
					pEffect->execute=&Treatment;
				}
				else if (word == "VampireHP")
				{
					pEffect->getName=&NameVampireHP;
					pEffect->execute=&VampireHP;
				}
				else if (word == "VampireMana")
				{
					pEffect->getName=&NameVampireMana;
					pEffect->execute=&VampireMana;
				}
				else if (word == "UpAttack")
				{
					pEffect->getName=&NameUpAttack;
					pEffect->execute=&UpAttack;
				}
				else if (word == "UpSpeed")
				{
					pEffect->getName=&NameUpSpeed;
					pEffect->execute=&UpSpeed;
				}
				if (pList==NULL)
				{
					pList=pEffect;
				}
				else
				{
					pList->pNext=pEffect;
					pList=pEffect;
				}
			}
		} while(word[0] != '@');

	return pList;
}

/*void verifyEffects(UNIT* Obj)
{
	if (Obj.pStatus!=NULL)
	{
		EFFECT *pEffect;
		pEffect = Obj->pStatus;
		pEffect->execute;
		if (pEffect->Duration == 0)
		{
		deleteEffect(pEffect);
		}
			
		}
		else
		{

		}*/
		
