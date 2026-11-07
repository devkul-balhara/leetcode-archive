vector<int> countServers(const int n, vector<vector<int>>& logs, const int x, const vector<int>& queries) {
       return [&, pq = queries | std::views::enumerate |
                       std::ranges::to<std::vector>()] mutable {
           return std::ranges::sort(
                      pq, {}, [](const auto& p) { return std::get<1>(p); }),
                  std::ranges::sort(logs, {},
                                    [](const auto& vc) { return vc[1]; }),
                  std::get<0>(std::ranges::fold_left(
                      pq,
                      std::tuple<std::vector<int>, std::vector<int>, int, int, int>{std::vector<int>(queries.size()), std::vector<int>(n + 1, 0), 0, 0, 0},
                      [&](auto&& acc, const auto& p) {
                          while (std::get<3>(acc) < logs.size() && logs[std::get<3>(acc)][1] <= std::get<1>(p)) std::get<4>(acc) += std::get<1>(acc)[logs[std::get<3>(acc)++][0]]++ == 0 ? 1 : 0;
                          while (std::get<2>(acc) < std::get<3>(acc) && logs[std::get<2>(acc)][1] < std::get<1>(p) - x)  std::get<4>(acc) -= --std::get<1>(acc)[logs[std::get<2>(acc)++][0]] == 0 ? 1 : 0;
                          return std::get<0>(acc)[std::get<0>(p)] = n - std::get<4>(acc), std::forward<decltype(acc)>(acc);
                      }));
       }();
   }