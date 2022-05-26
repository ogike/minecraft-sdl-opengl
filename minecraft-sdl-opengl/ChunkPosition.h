#pragma once

#include <glm/vec3.hpp>
#include "Constants.h"

class ChunkPosition
{
public:
	ChunkPosition(int x, int z) : _x(x), _z(z) {}
	int GetX() const { return _x; }
	int GetZ() const { return _z; }

	//for correct use as std::map keys
	bool operator<(const ChunkPosition& pos) const {
		if (_x < pos._x) return true;
		if (_x > pos._x) return false;
		//x == coord.x
		if (_z < pos._z) return true;
		if (_z > pos._z) return false;
		//*this == coord
		return false;
	}

	bool operator==(const ChunkPosition& pos) const {
		return pos._x == _x && pos._z == _z;
	}

	glm::vec3 getGlobalPos() {
		return glm::vec3( _x * CHUNK_SIZE, 0, _z * CHUNK_SIZE);
	}

	ChunkPosition ToFront()  const { return ChunkPosition(_x    , _z + 1); }
	ChunkPosition ToBack()   const { return ChunkPosition(_x    , _z - 1); }
	ChunkPosition ToRight()  const { return ChunkPosition(_x + 1, _z    ); }
	ChunkPosition ToLeft()   const { return ChunkPosition(_x - 1, _z    ); }

private:
	int _x;
	int _z;

};
