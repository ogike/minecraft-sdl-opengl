#pragma once

#include <map>
#include "ChunkPosition.h"
#include "Chunk.h"
#include "FastNoiseLite.h"
#include "Constants.h"


class Chunk;

class World
{
public:
	void GenerateTerrain();

	void GeneratePerlinChunk(ChunkPosition chunkPos, FastNoiseLite& noise);

	//generates one solid chunk (temporarily: a stair)
	void GenerateSolidChunk(ChunkPosition chunkPos);
	void GenerateSingleCube(ChunkPosition chunkPos);
	void BuildChunkMeshes();

	void Draw();
	/// <summary>
	/// Gets chunk at specified location, returns nullptr if it doesnt exist
	/// </summary>
	/// <param name="chunkPos"></param>
	/// <returns></returns>
	Chunk* getChunkAt(ChunkPosition chunkPos);


private:
	std::map<ChunkPosition, Chunk*> chunks;


};
