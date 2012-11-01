
#pragma once

#ifndef __WOS_H
#define __WOS_H

#include <stdio.h>

typedef
struct list
{
	char name[16];
	struct list *pNext;

} list;

typedef
struct attack //тип данных предназначенный для обозначения видов атак
{
	/* name of attack */
	char name[16];
	/* description of attack */
	char description[64];
	/* damage inflicted on the attack */
	int damage;
	/* cost attack in store */
	int cost;
	/*list of effects from the attack*/
	struct list effects;
	/* pointer to a next level*/
	struct attack *pUpLevel;
	/* pointer to a previous level */
	struct attack *pDownLevel;
	/* pointer to a next element in the list */
    struct attack *pNext;
    /* pointer to a previous element in the list */
    struct attack *pPrev;
} attack;

typedef
struct CategoryOfAttacks //тип данных определяющий котегигорию, как совокупность, атак
{
	/* name of category */
	char name[16];
	/* pointer to attack from this category*/
	struct attack *FirstAttack;
	/* pointer to a next element in the list */
	struct CategoryOfAttacks *pNext;
    /* pointer to a previous element in the list */
	struct CategoryOfAttacks *pPrev;
} CategoryOfAttacks;



typedef
struct unit //тип данных определяющий юнитов
{
	char name[16];
	int HitPoints[2];
	int Defense;
	int Mana;
	int Attack;
	int Concentration;
	int Experiance[2];
	int EvolutionPoints;
	int AttackPoints;
	struct CategoryOfAttacks *pCotegory;
} unit;

typedef
struct team
{
	int money;
	unit *unit1;
	unit *unit2;
	unit *unit3;
	unit *unit4;
	unit *unit5;
	unit *unit6;
} team;


#endif;