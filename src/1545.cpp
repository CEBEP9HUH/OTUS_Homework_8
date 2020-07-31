#include <iostream>
#include <map>

using ch_t = std::string;

int main() {
  std::multimap<char, char> dict;
  size_t n;
  std::cin>>n;
  for(size_t i=0;i<n;++i){
    std::cin.get();
    dict.emplace(std::cin.get(), std::cin.get());
  }
  std::cin.get();
  auto res = dict.equal_range(std::cin.get());
  for(auto i = res.first; i!=res.second; ++i)
  {
    std::cout << (*i).first<< (*i).second << "\n";
  }
}