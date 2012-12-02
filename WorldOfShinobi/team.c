
#include "team.h"

#include <malloc.h>
#include <stddef.h>

TEAM* createTeam(void)
{
	TEAM *pTeam;

	/* allocate the object */
	pTeam = malloc(sizeof(*pTeam));
	if (NULL == pTeam)
	{
		return NULL;
	}

	/* reset the object */
	memset(pTeam, 0, sizeof(*pTeam));

	return (TEAM *) pTeam;
}
