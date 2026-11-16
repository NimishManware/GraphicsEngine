#include <engine/core/window/window.hpp>

int main() {
    auto window = Engine::Window::create(1280,720,"test");
    while (true) {
        window->onUpdate();
    }
    return 0;
}
