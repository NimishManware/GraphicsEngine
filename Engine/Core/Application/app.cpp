#include <Engine/Core/Window/window.hpp>

namespace Engine {

    class Application {
    public:
        Application() {
            window_ptr_ = Window::Create(1280,720,"Game Engine");
        }

        void Run() {
            while (is_running_) {
                window_ptr_->OnUpdate();
            }
        }

    private:
        std::unique_ptr<Window> window_ptr_;
        bool is_running_ = true;
    };

}