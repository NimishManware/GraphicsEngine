#include <Engine/Core/Window/window.hpp>

int main() {
    auto window = Engine::Window::Create(1280,720,"test");
    while (true) {
        window->OnUpdate();
    }
    return 0;
}
