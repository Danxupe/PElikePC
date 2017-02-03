#pragma once

#include "mcpe/client/renderer/BlockTessellator.h"

class ArmorstandTessellator : public BlockTessellator
{
public:
	bool tessellate(Block const& block,BlockPos const& pos,unsigned char data,bool b)
	{
		_setShapeAndTessellate({0,0,0},{1,0.1,1},block,pos,0);
	}
};
