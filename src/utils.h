#pragma once

#include <algorithm>
#include <vector>
#include <list>

bool listContains(std::list<std::string> list, std::string value) {
	return (std::find(list.begin(), list.end(), value) != list.end());
}
