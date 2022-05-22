#pragma once

#include <glm/vec3.hpp>
#include "ChunkPosition.h"

class BlockPosition
{
public:
	BlockPosition(int x, int y, int z) : _x(x), _y(y), _z(z) {}
	int GetX() const { return _x; }
	int GetY() const { return _y; }
	int GetZ() const { return _z; }

	glm::vec3 GetAbsolutePos(ChunkPosition chunkPos) {
		return glm::vec3(16 * chunkPos.GetX() + _x, _y, 16 * chunkPos.GetZ() + _z);
	}

	//for correct use as std::map keys
	bool operator<(const BlockPosition& pos) const {
		if (_x < pos._x) return true;
		if (_x > pos._x) return false;
		//x == coord.x
		if (_y < pos._y) return true;
		if (_y > pos._y) return false;
		//x == coord.x && y == coord.y
		if (_z < pos._z) return true;
		if (_z > pos._z) return false;
		//*this == coord
		return false;
	}

private:
	int _x;
	int _y;
	int _z;

};