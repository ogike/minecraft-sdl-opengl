#pragma once

#include "Block.h"
#include <glm/vec2.hpp>
#include "Constants.h"

enum class TextureSide { Top, Side, Bottom };

static int GetTexInd(BlockType blockType, TextureSide side) {
	switch (blockType)
	{
		case BlockType::Dirt:				return 2;	break;
		case BlockType::Grass:
			switch (side)
			{
				case TextureSide::Top:		return 0;	break;
				case TextureSide::Bottom:	return 2;	break;
				default: /*sides*/			return 3;	break;
			}
			break;
		case BlockType::Stone:				return 1;	break;
		case BlockType::Iron:				return 33;	break;
		case BlockType::Coal:				return 34;	break;
		default: /*invalid texture*/		return 38;	break;
	}
}

/// <summary>
/// Returns the top left coordinate of the texture in the texture atlas
/// </summary>
static glm::vec2 getTexPos(int ind)
{
	return glm::vec2(
		ind % 16 * TEX_SIZE,
		1 - (ind / 16 * TEX_SIZE)
	);
}