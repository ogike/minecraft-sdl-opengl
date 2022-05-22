#pragma once

#include <map>
#include "ChunkPosition.h"
#include "Chunk.h"

class World
{
public:
	void GenerateTerrain();
	void Draw();


private:
	std::map<ChunkPosition, Chunk*> chunks;


};
