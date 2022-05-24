#include "World.h"
#include "ChunkPosition.h"

void World::GenerateTerrain()
{
	for (int x = -5; x < 5; x++)
	{
		for (int y = -5; y < 5; y++)
		{
			GenerateSolidChunk(ChunkPosition(x, y));
		}
	}
	/*GenerateSolidChunk(ChunkPosition(0, 0));
	GenerateSolidChunk(ChunkPosition(-1, 0));*/
	//GenerateSingleCube( ChunkPosition(0,0) );
	BuildChunkMeshes();
}

void World::GenerateSolidChunk(ChunkPosition chunkPos)
{
	Chunk* solidChunk = new Chunk(chunkPos, this);

	//insert debug chunk w blocks
	for (int x = 0; x < CHUNK_WIDTH; x++)
	{
		int maxHeight = x + 1;
		for (int y = 0; y <= maxHeight; y++)
		{
			for (int z = 0; z < CHUNK_LENGTH; z++)
			{
				BlockPosition blockPos = BlockPosition(x, y, z);
				BlockType blockType;
				if (y == maxHeight)			blockType = BlockType::Grass;
				else if (y >= maxHeight-3)	blockType = BlockType::Dirt;
				else						blockType = BlockType::Stone;

				solidChunk->AddBlock(new Block(blockType, blockPos, chunkPos), blockPos);
			}
		}
	}

	chunks[chunkPos] = solidChunk;
}

void World::GenerateSingleCube(ChunkPosition chunkPos)
{
	Chunk* solidChunk = new Chunk(chunkPos, this);

	BlockPosition blockPos = BlockPosition(0, 0, 0);
	solidChunk->AddBlock(new Block(BlockType::Dirt, blockPos, chunkPos), blockPos);

	chunks[chunkPos] = solidChunk;
}

void World::BuildChunkMeshes()
{
	for (auto const& chunk : chunks)
	{
		chunk.second->BuildMesh();
	}
}

void World::Draw()
{
	for (auto const& chunk : chunks)
	{
		chunk.second->draw();
	}
}

Chunk* World::getChunkAt(ChunkPosition chunkPos)
{
	auto iter = chunks.find(chunkPos);
	if (iter == chunks.end()) return nullptr;
	return iter->second;
}

