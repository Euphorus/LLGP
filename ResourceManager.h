#pragma once
#include "Object.h"

class ResourceManager : public Object
{
public:
	

	//Get Texture path
	static const std::string& getTexturePath(const std::string& TextureName);

	//Get Texture
	static sf::Texture& getTexture(const std::string& TextureName);

	//clears map "Texture"
	static void ClearTextureMap();

private:

	//A map that has a string matched to a file path
	static const std::unordered_map<std::string, std::string> TexturePaths;

	//A map that has a string matched to a texture
	static std::unordered_map<std::string, sf::Texture> Textures;
};

