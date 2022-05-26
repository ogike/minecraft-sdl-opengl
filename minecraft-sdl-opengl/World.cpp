#include "World.h"
#include <stdlib.h>
#include <time.h>


void World::GenerateTerrain()
{
	/*for (int x = -5; x < 5; x++)
	{
		for (int y = -5; y < 5; y++)
		{
			GenerateSolidChunk(ChunkPosition(x, y));
		}
	}*/
	/*GenerateSolidChunk(ChunkPosition(0, 0));
	GenerateSolidChunk(ChunkPosition(-1, 0));*/
	//GenerateSingleCube( ChunkPosition(0,0) );

	FastNoiseLite noise;
	noise.SetSeed(time(NULL));
	noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);

	for (int x = -WORLD_SIZE_CHUNKS/2; x <= WORLD_SIZE_CHUNKS/2; x++)
	{
		for (int z = -WORLD_SIZE_CHUNKS / 2; z <= WORLD_SIZE_CHUNKS / 2; z++)
		{
			GeneratePerlinChunk(ChunkPosition(x, z), noise);
		}
	}

	BuildChunkMeshes();
}

void World::GeneratePerlinChunk(ChunkPosition chunkPos, FastNoiseLite& noise)
{
	Chunk* newChunk = new Chunk(chunkPos, this);
	srand(time(NULL));

	for (int x = 0; x < CHUNK_SIZE; x++)
	{
		for (int z = 0; z < CHUNK_SIZE; z++)
		{
			float randomNoise = noise.GetNoise((float)(x + chunkPos.GetX() * CHUNK_SIZE), (float)(z + chunkPos.GetZ() * CHUNK_SIZE));
			int randomHeight = (randomNoise * TERRAIN_LAND_CEILING / 2) + TERRAIN_LAND_CEILING / 2;
			
			if (randomHeight > highestPoint.y - 1) {
				highestPoint = glm::vec3(CHUNK_SIZE * chunkPos.GetX() + x + 0.5f, randomHeight + 1, CHUNK_SIZE * chunkPos.GetZ() + z + 0.5f);
			}

			for (int y = 0; y <= randomHeight; y++)
			{
				BlockPosition blockPos = BlockPosition(x, y, z);
				BlockType blockType;
				if (y == randomHeight)
					blockType = BlockType::Grass;
				else if (y >= randomHeight - 3)
					blockType = BlockType::Dirt;
				else { //stone
					int oreRand = rand() % 100;
					if (oreRand <= IRON_CHANCE) {
						blockType = BlockType::Iron;
					}
					else if (oreRand <= COAL_CHANCE + IRON_CHANCE) {
						blockType = BlockType::Coal;
					}
					else {
						blockType = BlockType::Stone;
					}
				}

				newChunk->AddBlock(new Block(blockType, blockPos, chunkPos), blockPos);
			}
		}
	}

	chunks[chunkPos] = newChunk;
}



void World::GenerateSolidChunk(ChunkPosition chunkPos)
{
	Chunk* solidChunk = new Chunk(chunkPos, this);

	//insert debug chunk w blocks
	for (int x = 0; x < CHUNK_SIZE; x++)
	{
		int maxHeight = x + 1;
		for (int y = 0; y <= maxHeight; y++)
		{
			for (int z = 0; z < CHUNK_SIZE; z++)
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

