#include "World.h"
#include "ChunkPosition.h"
#include <iostream>

void World::GenerateTerrain()
{
	Chunk* startingChunk = new Chunk(ChunkPosition(0, 0));

	//insert debug chunk w blocks
	for (int x = 0; x < 1; x++)
	{
		for (int y = 0; y <= x; y++)
		{
			for (int z = 0; z < 1; z++)
			{
				std::cout << "Generating block at: (" << x << ", " << y << ", " << z << ")" << std::endl;
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

