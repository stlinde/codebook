#include <iostream>
#include <vector>

auto getConcatenation(std::vector<int>& nums) -> std::vector<int> {
  int len = nums.size();
  for (int i=0; i < len; i++) {
    nums.push_back(nums[i]);
  }
  return nums;
}

auto getConcatEmplace(std::vector<int>& nums) -> std::vector<int> {
  nums = nums.emplace_back(nums.begin());
  return nums;
}


auto main() -> int {
  std::vector<int> inp = {1, 2, 1};
  auto ans = getConcatEmplace(inp);
  for (auto i: ans)
    std::cout << i << ' ';
  
  return 0;
}
