
#include <stdio.h>

#include "unit.h"

int compareStrings (char str1[16], char str2[16]) // функция сравнивает строки
{
	 int i, similarity, lenghtstr1,lenghtstr2;
	 lenghtstr1=0;
	 lenghtstr2=0;
	 similarity=0;
	 for(i=0; str1[i]!='\0'; i++)
	 {
		 lenghtstr1++;
	 }
	 for(i=0; str2[i]!='\0'; i++)
	 {
		 lenghtstr2++;
	 }
	 if (lenghtstr1==lenghtstr2)
	 {
		 for(i=0; i<lenghtstr1; i++)
		 {
			 if (str1[i]==str2[i])
			 {
				 similarity++;
			 }
		 }
		 if (similarity==lenghtstr1)
		 {
			 return 1;
		 }
		 else
		 {
			 return 0;
		 }
	 }
	 else
	 {
		 return 0;
	 }
 }




int main()
{
	UNIT *pUnit;
	ATTACK *pAttack;
	char str[32]="fire";
	pUnit=createAllUnits();
	while (pUnit!=NULL)
	{
		printf("%s\n", pUnit->Name);
		pUnit = pUnit->pPrev;
	}
	printf("=D\n");
	pAttack=createAllAttack(str);
	sortAttack(pAttack);
	while (pAttack!=NULL)
	{
		printf("%s\n", pAttack->Name);
		printf("%s\n", pAttack->Description);
		pAttack=pAttack->pNext;
	}
	system("pause");
	return 0;
}
