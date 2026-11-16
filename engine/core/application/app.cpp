#include <engine/core/window/window.hpp>

namespace Engine {

    class Application {
    public:
        Application() {
            window_ptr_ = Window::create(1280,720,"Game Engine");
        }

        void Run() {
            while (is_running_) {
                window_ptr_->onUpdate();
            }
        }

    private:
        std::unique_ptr<Window> window_ptr_;
        bool is_running_ = true;
    };

}