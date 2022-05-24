#include "ChunkMesh.h"

ChunkMesh::~ChunkMesh(void)
{
	if (inited)
	{
		glDeleteVertexArrays(1, &vertexArrayObject);

		glDeleteBuffers(1, &vertexBuffer);
		glDeleteBuffers(1, &indexBuffer);
	}
}

void ChunkMesh::initBuffers()
{
	if (inited) //flush if overriding already existing buffers
	{
		inited = false;
		glDeleteVertexArrays(1, &vertexArrayObject);

		glDeleteBuffers(1, &vertexBuffer);
		glDeleteBuffers(1, &indexBuffer);
	}

	glGenVertexArrays(1, &vertexArrayObject);
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &indexBuffer);

	glBindVertexArray(vertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), (void*)&vertices[0], GL_STREAM_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec3)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec3) * 2));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), (void*)&indices[0], GL_STREAM_DRAW);

	glBindVertexArray(0);

	inited = true;
}

void ChunkMesh::addFace(glm::vec3 origoPos, glm::vec3 facePosBtmLeft, glm::vec3 facePosBtmRight, glm::vec3 facePosTopLeft, glm::vec3 facePosTopRight, glm::vec3 normal, glm::vec2 texPos)
{
	int startingInd = vertices.size();

	//struct Vertex{ glm::vec3 position; glm::vec3 normals; glm::vec2 texture; };
	vertices.push_back({ origoPos + facePosBtmLeft, normal, glm::vec2(texPos.x, texPos.y - TEX_SIZE) });
	vertices.push_back({ origoPos + facePosBtmRight, normal, glm::vec2(texPos.x + TEX_SIZE, texPos.y - TEX_SIZE) });
	vertices.push_back({ origoPos + facePosTopLeft, normal, texPos });
	vertices.push_back({ origoPos + facePosTopRight, normal, glm::vec2(texPos.x + TEX_SIZE, texPos.y) });

	// upper triangle
	indices.push_back( startingInd + 0 );
	indices.push_back( startingInd + 1 );
	indices.push_back( startingInd + 2 );
	//lower triangle
	indices.push_back( startingInd + 1 );
	indices.push_back( startingInd + 3 );
	indices.push_back( startingInd + 2 );
}

void ChunkMesh::draw()
{
	glBindVertexArray(vertexArrayObject);

	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);

	glBindVertexArray(0);
}