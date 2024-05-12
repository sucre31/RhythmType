#include "Parameter.h"
/*
@brief パラメータのセット
*/
void Parameter::set(std::string key, int val) {
	_map[key] = val;
}

/*
@brief パラメータの取得
*/
int Parameter::get(std::string key) const {
	auto it = _map.find(key);
	if (_map.end() == it) {
		return Error;
	}
	else {
		return it->second;
	}
}