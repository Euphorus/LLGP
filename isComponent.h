#pragma once
#include <concepts>
#include "Component.h"

//Template to make sure only a component is being used
template<class T>
concept isComponent = std::derived_from<T, Component> == true;