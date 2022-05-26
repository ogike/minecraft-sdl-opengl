#include "Chunk.h"

Block& Chunk::GetBlockAt(int x, int y, int z)
{
	return blocks[(x + (z * CHUNK_SIZE)) * CHUNK_HEIGHT + y];
}

void Chunk::SetBlock(int x, int y, int z, BlockType newType)
{
	GetBlockAt(x, y, z).type = newType;

	//TODO: set collision data...?
}

void Chunk::BuildMesh()
{
	//for ( auto const& block : blocks)
	//{
	//	//block.second->AddToMesh(myMesh, CheckNeighbours(block.second));
	//}

	for (int x = 0; x < CHUNK_SIZE; x++)
	{
		for (int z = 0; z < CHUNK_SIZE; z++)
		{
			for (int y = 0; y < CHUNK_HEIGHT; y++)
			{
				BlockType type = GetBlockAt(x, y, z).type;
				if (type == BlockType::Air) continue; //break early if no need to draw

				glm::vec3 origPos = glm::vec3(x + myChunkPos.GetX() * CHUNK_SIZE, y, z + myChunkPos.GetZ() * CHUNK_SIZE);
				int topTexInd = GetTexInd(type, TextureSide::Top);
				int btmTexInd = GetTexInd(type, TextureSide::Bottom);
				int sideTexInd = GetTexInd(type, TextureSide::Side);

				if (!IsSolidAt( x, y, z + 1  )) { //front
					myMesh.addFace(
						origPos,
						//vertices
						glm::vec3(-0.5, -0.5, +0.5), //btm left
						glm::vec3(+0.5, -0.5, +0.5), //btm right
						glm::vec3(-0.5, +0.5, +0.5), //top left
						glm::vec3(+0.5, +0.5, +0.5), //top right
						glm::vec3(0, 0, 1), //normal
						sideTexInd //TODO: should be a tex index
					);
				}

				if (!IsSolidAt( x, y, z - 1 )) { //back
					myMesh.addFace(
						origPos,
						//vertices
						glm::vec3(+0.5, -0.5, -0.5),
						glm::vec3(-0.5, -0.5, -0.5),
						glm::vec3(+0.5, +0.5, -0.5),
						glm::vec3(-0.5, +0.5, -0.5),
						glm::vec3(0, 0, -1), //normal
						sideTexInd //tex
					);
				}

				if (!IsSolidAt( x + 1, y, z )) { //right
					myMesh.addFace(
						origPos,
						//vertices
						glm::vec3(+0.5, -0.5, +0.5),
						glm::vec3(+0.5, -0.5, -0.5),
						glm::vec3(+0.5, +0.5, +0.5),
						glm::vec3(+0.5, +0.5, -0.5),
						glm::vec3(1, 0, 0), //normal
						sideTexInd //tex
					);
				}

				if (!IsSolidAt( x - 1, y, z )) { //left
					myMesh.addFace(
						origPos,
						//vertices
						glm::vec3(-0.5, -0.5, -0.5),
						glm::vec3(-0.5, -0.5, +0.5),
						glm::vec3(-0.5, +0.5, -0.5),
						glm::vec3(-0.5, +0.5, +0.5),
						glm::vec3(-1, 0, 0), //normal
						sideTexInd //tex
					);
				}

				if (!IsSolidAt( x, y + 1, z )) { //top
					myMesh.addFace(
						origPos,
						//vertices
						glm::vec3(-0.5, +0.5, +0.5),
						glm::vec3(+0.5, +0.5, +0.5),
						glm::vec3(-0.5, +0.5, -0.5),
						glm::vec3(+0.5, +0.5, -0.5),
						glm::vec3(0, 1, 0), //normal
						topTexInd //tex
					);
				}

				if (!IsSolidAt( x, y - 1, z)) { //bottom
					myMesh.addFace(
						origPos,
						//vertices
						glm::vec3(-0.5, -0.5, -0.5),
						glm::vec3(+0.5, -0.5, -0.5),
						glm::vec3(-0.5, -0.5, +0.5),
						glm::vec3(+0.5, -0.5, +0.5),
						glm::vec3(0, -1, 0), //normal
						btmTexInd //tex
					);
				}
			}
		}
	}

	myMesh.initBuffers();
}


bool Chunk::IsSolidAt(int x, int y, int z)
{
	if (y < 0) return false; //under the world limit
	if (y >= CHUNK_HEIGHT) return false; //above the world limit

	//Block is in the chunk to the left
	if (x < 0) {
		Chunk* toLeftChunk = myWorld->getChunkAt( myChunkPos.ToLeft() );
		if (toLeftChunk == nullptr) return false;
		return toLeftChunk->IsSolidAt( CHUNK_SIZE - 1, y, z );
	}

	//Block is in the chunk to the right
	if (x >= CHUNK_SIZE) {
		Chunk* toRightChunk = myWorld->getChunkAt(myChunkPos.ToRight());
		if(toRightChunk == nullptr) return false;
		return toRightChunk->IsSolidAt( 0, y, z);
	}

	//Block is in the chunk to the back
	if (z < 0) {
		Chunk* toBackChunk = myWorld->getChunkAt(myChunkPos.ToBack());
		if(toBackChunk == nullptr) return false;
		return toBackChunk->IsSolidAt( x, y, CHUNK_SIZE -1 );
	}

	//Block is in the chunk to the right
	if (z >= CHUNK_SIZE) {
		Chunk* toFrontChunk = myWorld->getChunkAt(myChunkPos.ToFront());
		if(toFrontChunk == nullptr) return false;
		return toFrontChunk->IsSolidAt( x, y, 0 );
	}

	//Block is in this chunk

	return GetBlockAt(x, y, z).type != BlockType::Air;
}
