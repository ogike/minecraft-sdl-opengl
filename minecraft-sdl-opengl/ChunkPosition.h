#pragma once

class ChunkPosition
{
public:
	ChunkPosition(int x, int z) : _x(x), _z(z) {}
	int GetX() { return _x; }
	int GetZ() { return _z; }

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

private:
	int _x;
	int _z;

};
