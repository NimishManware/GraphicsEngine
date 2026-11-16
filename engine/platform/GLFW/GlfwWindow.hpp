#pragma once

#include <engine/core/window/window.hpp>
#include <GLFW/glfw3.h>

namespace Engine {

    class GlfwWindow : public Window {
    public:
        GlfwWindow(const uint32_t& width, const uint32_t& height, const std::string& title);
        ~GlfwWindow() override;

        // Overridden virtual methods
        void onUpdate() override;

        uint32_t getWidth() const override { return window_data_.width; }
        uint32_t getHeight() const override { return window_data_.height; }


    private:
        void init(const uint32_t& width, const uint32_t& height, const std::string& title);
        void shutdown();

    private:
        GLFWwindow* glfw_window_ptr_ = nullptr;

        struct WindowData {
            std::string title;
            uint32_t width = 0;
            uint32_t height = 0;
        };

        WindowData window_data_;
    };

}