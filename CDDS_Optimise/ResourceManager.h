#pragma once
/*-------------------------------------------------------------------------------------------------------
For this task you will modify the CDDS_Optimise program by creating a Resource Manager class that will store loaded resources (i.e., Texture2D objects) within a hash table. 
In this scenario, the key will be the resource filename and the value is the Texture2D object (or a reference to the object).
Each time you request a texture to be loaded, you will ask the Resource Manager for it.
The Resource Manager will look up the texture in the hash table and return a reference to the texture if it has previously been loaded.
If it has not been loaded, the Resource Manager will load the texture and store it in the hash table.
-------------------------------------------------------------------------------------------------------*/

#include "raylib.h"
#include <unordered_map>	/* Need to change to own hash table */
#include <string>			/* place holder for hash key */

class ResourceManager
{
public:
	~ResourceManager();

	Texture2D loadTexture(const char* file); /* Must use lower case "L" as this conflicted with an inbuilt function with the same name  */

private:
	std::unordered_map<std::string, Texture2D> m_textures; /* Hash table used, key is 'string' */
};