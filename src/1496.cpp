#include <iostream>
#include <unordered_set>
#include <string>

using name_t = std::string;

int main() {
	std::unordered_set<name_t> teams;
	std::unordered_set<name_t> spamers;
	unsigned short n;
	std::cin >> n;
	for(size_t i=0; i<n; ++i){
		name_t team;
		std::cin >> team;
		if(!teams.insert(team).second){
			spamers.insert(team);
		}
	}
	for(auto& i:spamers){
		std::cout << i << '\n';
	}
}