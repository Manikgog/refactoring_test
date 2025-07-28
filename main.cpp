#include <iostream>
#include <vector>
#include <memory>

std::vector<int> GetVector() {
    std::vector<int> v(10);
    for (size_t i = 0; i < 10; ++i) {
        v[i] = i+1;
    }
    std::vector<int> v1 = std::move(v);
    std::cout << v.size() << std::endl;
    return std::move(v1);
}


/*void GetVector(std::vector<int> & v)
{
    std::lock_guard<(metem m);
    std::vector<int> v1;

    for (size_t i = 0; i < 10; ++i) {
        v1.push_back(i+1);
    }

    v1.swap(v);

}*/

int main() {
    std::vector<int> res = GetVector();
    for (const auto& i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}