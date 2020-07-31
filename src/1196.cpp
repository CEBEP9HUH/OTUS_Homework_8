#include <vector>
#include <iostream>
#include <algorithm>

int main(){
  std::vector<size_t> dates;
  size_t n;
  scanf("%lu", &n);
  dates.reserve(n);
  size_t date;
  for(size_t i=0; i<n; ++i){
    scanf("%lu", &date);
    if(dates.back()!=date)
      dates.emplace_back(date);
  }
  scanf("%lu", &n);
  size_t count = 0;
  for(size_t i=0; i<n; ++i){
    scanf("%lu", &date);
    if(std::binary_search(dates.begin(), dates.end(), date)){
      ++count;
    }
  }
  std::cout << count;
}