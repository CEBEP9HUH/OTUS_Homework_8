#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <array>
#include <limits>
#include <queue>
#include <unordered_set>

using ind_t = size_t;
const ind_t undef = std::numeric_limits<ind_t>::max();

int main() {
  std::string name = "Isenbaev";
  const ind_t teamSize = 3;
  std::array<std::string, teamSize> team;
  std::unordered_map<std::string, std::unordered_set<std::string> > teammates;
  std::map<std::string, ind_t> result;
  ind_t teamsCount;
  std::cin >> teamsCount;
  for(ind_t i=0;i<teamsCount; ++i){
    std::cin >> team[0] >> team[1] >> team[2];
    teammates[team[0]].emplace(team[1]);
    teammates[team[0]].emplace(team[2]);
    teammates[team[1]].emplace(team[0]);
    teammates[team[1]].emplace(team[2]);
    teammates[team[2]].emplace(team[0]);
    teammates[team[2]].emplace(team[1]);
  }
  if(teammates.count(name)>0){
    std::queue<std::string> q;
    result.emplace(name,0);
    q.push(name);
    while(!q.empty()){
      auto person = q.front();
      q.pop();
      auto& t = teammates[person];
      for(auto& i : t){
        if(!result.count(i)){
          result.emplace(i, result[person]+1);
          q.push(i);
        } else {
          result[i] = std::min(result[person]+1, result[i]);
        }
      }
    }
  }
  for(auto& i: teammates){
    result.emplace(i.first, undef);
  }
  for(auto& i: result){
    if(i.second!=undef){
      std::cout << i.first << " " << i.second << "\n";
    } else {
      std::cout << i.first << " undefined\n";
    }
  }
}