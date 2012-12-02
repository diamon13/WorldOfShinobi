#pragma once

#ifndef __ATTACK_H
#define __ATTACK_H

#include "effect.h"

typedef
struct ATTACK //тип данных предназначенный для обозначения видов атак
{
	/* name of attack */
	char Name[16];
	/* description of attack */
	char Description[64];
	/* damage inflicted on the attack */
	int Damage;
	/* cost attack in store */
	int Cost;
	/*list of effects from the attack*/
	struct EFFECT *pEffect;
	/* pointer to a next element in the list */
    struct ATTACK *pNext;
    /* pointer to a previous element in the list */
    struct ATTACK *pPrev;
} ATTACK;

#endif
