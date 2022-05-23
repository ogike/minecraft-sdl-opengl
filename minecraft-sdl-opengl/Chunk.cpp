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
	Block::NeighbourCollision colls{};

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
	if (pos.GetY() < 0) return false; //under the world limit
	if (pos.GetY() >= CHUNK_HEIGHT) return false; //above the world limit

	//Block is in the chunk to the left
	if (pos.GetX() < 0) {
		Chunk* toLeftChunk = myWorld->getChunkAt( myChunkPos.ToLeft() );
		if (toLeftChunk == nullptr) return false;
		return toLeftChunk->IsSolidAt( BlockPosition(CHUNK_WIDTH - 1, pos.GetY(), pos.GetY()) );
	}

	//Block is in the chunk to the right
	if (pos.GetX() >= CHUNK_WIDTH) {
		Chunk* toRightChunk = myWorld->getChunkAt(myChunkPos.ToRight());
		if(toRightChunk == nullptr) return false;
		return toRightChunk->IsSolidAt(BlockPosition(0, pos.GetY(), pos.GetY()));
	}

	//Block is in the chunk to the back
	if (pos.GetZ() < 0) {
		Chunk* toBackChunk = myWorld->getChunkAt(myChunkPos.ToBack());
		if(toBackChunk == nullptr) return false;
		return toBackChunk->IsSolidAt(BlockPosition(pos.GetX(), pos.GetY(), CHUNK_LENGTH-1));
	}

	//Block is in the chunk to the right
	if (pos.GetZ() >= CHUNK_WIDTH) {
		Chunk* toFrontChunk = myWorld->getChunkAt(myChunkPos.ToFront());
		if(toFrontChunk == nullptr) return false;
		return toFrontChunk->IsSolidAt(BlockPosition(pos.GetX(), pos.GetY(), 0));
	}

	//Block is in this chunk

	auto iterator = blocks.find(pos);
	if (iterator == blocks.end() ) return false;

	if (iterator->second->IsSolid()) return true;
	else return false;
}
