#include "Chunk.h"

void Chunk::BuildMesh() 
{

	for ( auto const& block : blocks)
	{
		block.second->AddToMesh(myMesh);
	}

	myMesh.initBuffers();
}