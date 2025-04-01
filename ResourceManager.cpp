#include "ResourceManager.h"

//Set the key and matching value to the key with the file path
const std::unordered_map<std::string, std::string> ResourceManager::TexturePaths =
{
	{"Player", "src/sprites/robotronsprites.png"},
	{"Enemy", "src/sprites/robotronsprites.png"},

};

std::unordered_map<std::string, sf::Texture> ResourceManager::Textures;

//Returns the texture path by passing in the matching key as a string
const std::string& ResourceManager::getTexturePath(const std::string& TextureName)
{
	//Check if the texture name exists in the map
	if (TexturePaths.find(TextureName) != TexturePaths.end())
	{
		std::cout << "Texture path was found of key: " << TextureName << std::endl;
		return TexturePaths.at(TextureName);
	}
	else
	{
		//If the passed in string value doesn't match any keys within the map do this
		std::cout << "Texture path name not found: " << TextureName << ", created Default Texture " << std::endl;

		static const std::string defaultPath = "src/sprites/robotronsprites.png";
		return defaultPath;
	}
}

sf::Texture& ResourceManager::getTexture(const std::string& TextureName)
{
	//Check if the texture is on the map
	if (Textures.find(TextureName) == Textures.end())
	{
		//Load the texture based on the file path
		sf::Texture texture;
		if (!texture.loadFromFile(getTexturePath(TextureName)))
		{
			std::cout << "Texture not found: " << TextureName << std::endl;
		}
		else
		{
			//Move the created texture onto the "Textures" map
			Textures.emplace(TextureName, std::move(texture));
		}
	}

	//If the textures already existed just return it
	return Textures.at(TextureName);
}

void ResourceManager::ClearTextureMap()
{
	Textures.clear();
}