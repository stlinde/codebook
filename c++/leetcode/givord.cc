#include <vector>
#include <iostream>

auto createTargetArray(std::vector<int>& nums, std::vector<int>& index) -> std::vector<int> {
    std::vector<int> target;
    for (int i = 0; i < index.size(); i++) {
        target.insert(target.begin() + i, nums[index]);
    }
    return target;
}

auto main() -> int {
  std::vector<int> inp1 = {0, 1, 2, 3, 4};
  std::vector<int> inp2 = {0, 1, 2, 2, 1};
  std::vector<int> ans;

  ans = createTargetArray(inp1, inp2);

  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << " ";
  }

  std::cout << "\n";
  return 0; 
}
