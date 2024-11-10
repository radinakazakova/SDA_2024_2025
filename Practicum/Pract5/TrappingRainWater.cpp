// Виж README.md файла за по-подробно обяснение с картинки.
class Solution {
public:
    int trap(std::vector<int>& height) {
        // пазим двойки { височина, индекс } в монотонно намаляващ дек.
        std::deque<std::pair<int, int>> blocks;
        int trappedWater = 0;

        for (int i = 0; i < height.size(); ++i) {
            while (blocks.size() && blocks.back().first < height[i]) { // блокчето height[i] е дясна преграда.
                auto block = blocks.back(); // взимаме си блокчето, върху което ще броим блокчетата вода.
                blocks.pop_back();          // попваме, за да може да достъпим предното блокче.
                if (blocks.empty()) {       // нашето блокче е било единствено и няма как да задържи вода.
                    continue;
                }
                
                int waterBlocks = std::min(height[i]/*дясна преграда*/, blocks.front().first /*лява преграда*/) - block.first; //колко блокчета над текущото според височината на преградите без неговата си височина
                int interval = block.second - blocks.back().second; //разстояние между предходния и текущия
                trappedWater += waterBlocks * interval;
            }

            blocks.push_back({ height[i], i });
        }

        return trappedWater;
    }
};
