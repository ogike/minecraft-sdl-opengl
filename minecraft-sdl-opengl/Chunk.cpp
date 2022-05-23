#include "Chunk.h"

void Chunk::BuildMesh() 
{

	for ( auto const& block : blocks)
	{
		block.second->AddToMesh(myMesh, CheckNeighbours(block.second));
	}

	myMesh.initBuffers();
}

Block::NeighbourCollision Chunk::CheckNeighbours(Block* block)
{
	Block::NeighbourCollision colls;

	colls.front = IsSolidAt(block->blockPos.ToFront());
	colls.back  = IsSolidAt(block->blockPos.ToBack());
	colls.right = IsSolidAt(block->blockPos.ToRight());
	colls.left  = IsSolidAt(block->blockPos.ToLeft());
	colls.top   = IsSolidAt(block->blockPos.ToTop());
	colls.bottom = IsSolidAt(block->blockPos.ToBottom());

	return colls;
}

bool Chunk::IsSolidAt(BlockPosition pos)
{
	//auto iterator = blocks.find(pos)
	if (blocks.find(pos) == blocks.end() ) return false;

	if (blocks[pos]->IsSolid()) return true;
	else return false;
}
