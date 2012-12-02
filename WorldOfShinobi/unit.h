
#pragma once

#ifndef __UNIT_H
#define __UNIT_H

struct UNIT;
typedef struct UNIT UNIT;

#include "effect.h"
#include "category.h"

struct UNIT //тип данных определ€ющий юнитов
{
	char Name[16];
	int Rang;
	
	/* Full HitPoints */
	int FullHP;
	/* HitPoints in combat*/
	int HP;

	int FullDefense;
	int Defense;

	int FullSpeed;
	int Speed;

	int FullMana;
	int Mana;

	int FullAttack;
	int Attack;

	int Concentration;
	int AttPoints;
	int EvPoints;

	EFFECT *pStatus;	
	 
	CATEGORY *pCotegory;
	UNIT *pNext, *pPrev;

};

#endif
