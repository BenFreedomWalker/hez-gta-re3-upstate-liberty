#include "common.h"

#include "General.h"
#include "ModelIndices.h"

#define X(name, var) int16 var = -1;
	MODELINDICES
#undef X

static bool g_modelTraits[MODEL_TRAIT_COUNT][MODELINFOSIZE];

void
ClearModelTraits(void)
{
	memset(g_modelTraits, 0, sizeof(g_modelTraits));
}

void
SetModelTrait(int16 id, eModelTrait trait)
{
	if(id >= 0 && id < MODELINFOSIZE && trait >= 0 && trait < MODEL_TRAIT_COUNT)
		g_modelTraits[trait][id] = true;
}

bool
IsGlass(int16 id)
{
	return (id >= 0 && id < MODELINFOSIZE && g_modelTraits[MODEL_TRAIT_GLASS][id]) ||
		id == MI_GLASS1 || id == MI_GLASS2 || id == MI_GLASS3 || id == MI_GLASS4 ||
		id == MI_GLASS5 || id == MI_GLASS6 || id == MI_GLASS7 || id == MI_GLASS8;
}

bool
IsTreeModel(int16 id)
{
	return (id >= 0 && id < MODELINFOSIZE && g_modelTraits[MODEL_TRAIT_TREE][id]) ||
		id == MI_TREE1 || id == MI_TREE2 || id == MI_TREE3 || id == MI_TREE4 ||
		id == MI_TREE5 || id == MI_TREE6 || id == MI_TREE7 || id == MI_TREE8 ||
		id == MI_TREE9 || id == MI_TREE10 || id == MI_TREE11 || id == MI_TREE12 ||
		id == MI_TREE13 || id == MI_TREE14;
}

bool
IsBannerModel(int16 id)
{
	return (id >= 0 && id < MODELINFOSIZE && g_modelTraits[MODEL_TRAIT_BANNER][id]) ||
		id == MI_CHINABANNER1 || id == MI_CHINABANNER2 || id == MI_CHINABANNER3 ||
		id == MI_CHINABANNER4 || id == MI_CHINABANNER5 || id == MI_CHINABANNER6 ||
		id == MI_CHINABANNER7 || id == MI_CHINABANNER8 || id == MI_CHINABANNER9 ||
		id == MI_CHINABANNER10 || id == MI_CHINABANNER11 || id == MI_CHINABANNER12 ||
		id == MI_ITALYBANNER1 || id == MI_CHINALANTERN;
}

bool
IsDoorModel(int16 id)
{
	return id >= 0 && id < MODELINFOSIZE && g_modelTraits[MODEL_TRAIT_DOOR][id];
}

void
InitModelIndices(void)
{
	ClearModelTraits();
#define X(name, var) var = -1;
	MODELINDICES
#undef X
}

void
MatchModelString(const char *modelname, int16 id)
{
#define X(name, var) \
	if(!CGeneral::faststrcmp(name, modelname)){ \
		var = id; \
		return; \
	}
	MODELINDICES
#undef X
}

void
TestModelIndices(void)
{
	;
}
