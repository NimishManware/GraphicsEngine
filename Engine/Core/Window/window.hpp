#pragma once

#include <string>
#include <memory>
namespace Engine {

    class Window {
        public:
        // child class destrutor is called when freeing unique_ptr<Window>
        // if destructor is virtual
        virtual ~Window() = default;

        virtual void OnUpdate() = 0;
        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;
        static std::unique_ptr<Window> Create(const uint32_t& width, const uint32_t& height, const std::string& title);

        private:

        std::string Title;
        uint32_t Width;
        uint32_t Height;

    };
}