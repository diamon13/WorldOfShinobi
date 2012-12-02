
#pragma once

#ifndef __CATEGORY_H
#define __CATEGORY_H

#include "attack.h"

typedef
struct CATEGORY //тип данных определяющий котегигорию, как совокупность, атак
{
	/* name of category */
	char name[16];
	/* pointer to attack from this category*/
	struct ATTACK *FirstAttack;
	/* pointer to a next element in the list */
	struct CATEGORY *pNext;
    /* pointer to a previous element in the list */
	struct CATEGORY *pPrev;
} CATEGORY;

#endif
