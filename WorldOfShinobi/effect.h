
#pragma once

#ifndef __EFFECT_H
#define __EFFECT_H

struct EFFECT;
typedef struct EFFECT EFFECT;

#include "unit.h"

struct EFFECT
{
	int Duration; // Продолжительность
	int Chance; // Вероятность
	int Force; // Сила
	struct EFFECT *pNext, *pPrev;
	char (*getName) (void);
	void (*execute) (struct EFFECT* Effect, UNIT* Obj, UNIT* Subj);
};

#endif
