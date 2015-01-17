#include "Mesh.h"

Mesh::Mesh(const std::string& filePath) :
		count(0) {

	// load mesh data with Assimp.
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(filePath,
			aiProcess_CalcTangentSpace |
			aiProcess_Triangulate |
			aiProcess_FlipUVs |
			aiProcess_FixInfacingNormals |
			aiProcess_JoinIdenticalVertices |
			aiProcess_GenSmoothNormals);

	if(!scene) {
		std::cout << "File corrupted." << std::endl;
		return;
	}

	// get the imported model.
	const aiMesh* model = scene->mMeshes[0];

	// create the vectors for the information.
	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> tangents;
	std::vector<glm::vec3> normals;
	std::vector<unsigned int> indices;

	count = model->mNumFaces * 3;

	positions.reserve((size_t) model->mNumVertices);
	texCoords.reserve((size_t) model->mNumVertices);
	tangents.reserve((size_t) model->mNumVertices);
	normals.reserve((size_t) model->mNumVertices);
	indices.reserve((size_t) model->mNumFaces * 3);

	aiVector3D zero(0, 0, 0);
	for(unsigned int i = 0; i < model->mNumVertices; i++) {
		const aiVector3D pos = model->mVertices[i];
		const aiVector3D tex = model->HasTextureCoords(0) ? model->mTextureCoords[0][i] : zero;
		const aiVector3D tan = model->mTangents[i];
		const aiVector3D nor = model->mNormals[i];

		positions.push_back(glm::vec3(pos.x, pos.y, pos.z));
		texCoords.push_back(glm::vec2(tex.x, tex.y));
		tangents.push_back(glm::vec3(tan.x, tan.y, tan.z));
		normals.push_back(glm::vec3(nor.x, nor.y, nor.z));
	}

	// here I'm inverting the faces, don't know why yet.
	for(unsigned int i = 0; i < model->mNumFaces; i++) {
		const aiFace& face = model->mFaces[i];
		indices.push_back(face.mIndices[2]);
		indices.push_back(face.mIndices[1]);
		indices.push_back(face.mIndices[0]);
	}

	// generate the Vertex Array Object named VAO.
	glGenVertexArrays(1, &vao);

	// set the current Vertex Array to the VAO.
	glBindVertexArray(vao);

	// generate needed buffers for this mesh that will be included in the VAO.
	glGenBuffers(1, &vboPos);
	glGenBuffers(1, &vboTex);
	glGenBuffers(1, &vboNor);
	glGenBuffers(1, &vboTan);
	glGenBuffers(1, &ibo);

	// Buffer for Positions.
	glBindBuffer(GL_ARRAY_BUFFER, vboPos);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions[0]) * model->mNumVertices, &positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);

	// Buffer for TexCoords.
	glBindBuffer(GL_ARRAY_BUFFER, vboTex);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords[0]) * model->mNumVertices, &texCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);

	// Buffer for TexCoords.
	glBindBuffer(GL_ARRAY_BUFFER, vboNor);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normals[0]) * model->mNumVertices, &normals[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);

	// Buffer for TexCoords.
	glBindBuffer(GL_ARRAY_BUFFER, vboTan);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tangents[0]) * model->mNumVertices, &tangents[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);

	// Buffer for indices.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

	// unbind the vao.
	glBindVertexArray(0);
}

Mesh::Mesh(util::HeapArray<Vertex*> &vertices, std::vector<int> indices) :
		count((GLuint) indices.size()) {

	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;

	positions.reserve((size_t) vertices.Size());
	texCoords.reserve((size_t) vertices.Size());

	for(int i = 0; i < vertices.Size(); i++) positions.push_back(vertices[i]->GetPosition());
	for(int i = 0; i < vertices.Size(); i++) texCoords.push_back(vertices[i]->GetTexCoord());

	// generate the Vertex Array Object named VAO.
	glGenVertexArrays(1, &vao);

	// set the current Vertex Array to the VAO.
	glBindVertexArray(vao);

	// generate needed buffers for this mesh that will be included in the VAO.
	glGenBuffers(1, &vboPos);
	glGenBuffers(1, &vboTex);
	glGenBuffers(1, &ibo);

	// Buffer for Positions.
	glBindBuffer(GL_ARRAY_BUFFER, vboPos);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions[0]) * vertices.Size(), &positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);

	// Buffer for TexCoords.
	glBindBuffer(GL_ARRAY_BUFFER, vboTex);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords[0]) * vertices.Size(), &texCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);

	// Buffer for indices.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

	// unbind the vao.
	glBindVertexArray(0);
}

void Mesh::Draw() {
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &vao);
}