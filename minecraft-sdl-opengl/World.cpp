#include "World.h"
#include "ChunkPosition.h"

void World::GenerateTerrain()
{
	Chunk* startingChunk = new Chunk(ChunkPosition(0, 0));

	//insert debug chunk w blocks
	for (int x = 0; x < 16; x++)
	{
		for (int y = 0; y < x; y++)
		{
			for (int z = 0; z < 16; z++)
			{
				BlockPosition pos = BlockPosition(x, y, z);
				startingChunk->AddBlock(new Block(BlockType::Dirt, pos), pos);
			}
		}
	}

	startingChunk->BuildMesh();
	chunks[ChunkPosition(0, 0)] = startingChunk;
}

void World::Draw()
{
	for (auto const& chunk : chunks)
	{
		chunk.second->draw();
	}
}

