#pragma once

// C++ includes
#include <memory>

// GLEW
#include <GL/glew.h>

// SDL
#include <SDL.h>
#include <SDL_opengl.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>

#include "includes/gCamera.h"

#include "includes/ProgramObject.h"
#include "includes/BufferObject.h"
#include "includes/VertexArrayObject.h"
#include "includes/TextureObject.h"

// mesh
#include "includes/ObjParser_OGL3.h"

// terrain
#include "World.h"

#include "Constants.h"

class CMyApp
{
public:
	CMyApp();
	~CMyApp();

	bool Init();
	void Clean();

	void Update();
	void Render();

	void KeyboardDown(SDL_KeyboardEvent&);
	void KeyboardUp(SDL_KeyboardEvent&);
	void MouseMove(SDL_MouseMotionEvent&);
	void MouseDown(SDL_MouseButtonEvent&);
	void MouseUp(SDL_MouseButtonEvent&);
	void MouseWheel(SDL_MouseWheelEvent&);
	void Resize(int, int);

protected:
	// shaderekhez szükséges változók
	ProgramObject		m_program;			// mesh shader
	ProgramObject		m_programSkybox;	// skybox shader
	ProgramObject		m_programAxis;		//coordinate axis
	ProgramObject		m_programCrossHair; //crosshair

	VertexArrayObject	m_SkyboxVao;
	IndexBuffer			m_SkyboxIndices;	
	ArrayBuffer			m_SkyboxPos;	


	gCamera				m_camera;

	Texture2D			m_textureAtlas;
	TextureCubeMap		m_skyboxTexture;

	World				m_world;

	struct Vertex
	{
		glm::vec3 p;
		glm::vec3 n;
		glm::vec2 t;
	};


	void InitShaders();
	void InitSkyBox();

	float window_ratio = 1.0f;
};

