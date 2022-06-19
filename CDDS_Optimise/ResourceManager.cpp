#include "ResourceManager.h"
/*-------------------------------------------------------------------------------------------------------
For this task you will modify the CDDS_Optimise program by creating a Resource Manager class that will store loaded resources (i.e., Texture2D objects) within a hash table.
In this scenario, the key will be the resource filename and the value is the Texture2D object (or a reference to the object).
Each time you request a texture to be loaded, you will ask the Resource Manager for it.
The Resource Manager will look up the texture in the hash table and return a reference to the texture if it has previously been loaded.
If it has not been loaded, the Resource Manager will load the texture and store it in the hash table.
-------------------------------------------------------------------------------------------------------*/

ResourceManager::~ResourceManager()
{
}

Texture2D ResourceManager::loadTexture(const char* file)
{
	std::string key(file);
	auto iter = m_textures.find(key); /* find is a feature needed in the hash table */
	if (iter != m_textures.end())
	{	/* Texture already loaded */
		return iter->second;
	}
	else
	{
		Texture2D texture = LoadTexture(file);	/* Loads texture */
		m_textures[key] = texture;				/* Stores in the Hash Table */
		return texture;
	}

}
