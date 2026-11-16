#include <engine/platform/GLFW/GlfwWindow.hpp>
#include <iostream>

namespace Engine {

    std::unique_ptr<Window> Window::create(const uint32_t& width, const uint32_t& height, const std::string& title) {
        return std::make_unique<GlfwWindow>(width,height,title);
    }

    GlfwWindow::GlfwWindow(const uint32_t& width, const uint32_t& height, const std::string& title) {
        init(width,height,title);
    }
    void GlfwWindow::init(const uint32_t& width, const uint32_t& height, const std::string& title) {
        window_data_.title = title;
        window_data_.width = width;
        window_data_.height = height;

        static bool s_GLFWInitialized = false;
        if (!s_GLFWInitialized) {
            int success = glfwInit();
            if (!success) {
                std::cerr << "Failed to initialize GLFW!\n";
                return;
            }
            s_GLFWInitialized = true;
        }

        glfw_window_ptr_ = glfwCreateWindow((int)width, (int)height, title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(glfw_window_ptr_);
    }

    GlfwWindow::~GlfwWindow() {
        shutdown();
    }

    void GlfwWindow::shutdown() {
        if (glfw_window_ptr_) {
            glfwDestroyWindow(glfw_window_ptr_);
        }
        glfwTerminate();
    }

    void GlfwWindow::onUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(glfw_window_ptr_);
    }

}