#include "wos.h"

#include <stdio.h>


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
	 char string1[16], string2[16];
	 int i;
	 printf("Введите строку 1\n");
	 scanf("%s", &string1);
	 printf("Введите строку 2\n");
	 scanf("%s", &string2);
	 i=compareStrings(string1, string2);
	 printf("%d",i);
	 return 0;
 }
