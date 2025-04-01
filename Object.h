#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "UUID.h"
#include <iostream>
#include "Vector2.h"
#include <unordered_map>
#include <array>
#include <string>
#include <memory>

class Object
{
public:
	Object() : uuid() {}

	Object(const Object&) = default;

	LLGP::UUID uuid;

	//Compares two Object instances, compares the uuids by casting them to a uint_64, returns true if two Objects are equal
	inline bool operator==(const Object& rhs) { return (uint64_t)this->uuid == (uint64_t)rhs.uuid; }

	//Compares two Object instances, return true if they don't match
	inline bool operator!=(const Object& rhs) { return !(*this == rhs); }

};