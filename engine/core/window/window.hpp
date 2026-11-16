#pragma once

#include <string>
#include <memory>
#include <engine/core/events/event.hpp>
namespace Engine {

    class Window {
        public:
        // child class destrutor is called when freeing unique_ptr<Window>
        // if destructor is virtual
        virtual ~Window() = default;

        virtual void onUpdate() = 0;
        virtual uint32_t getWidth() const = 0;
        virtual uint32_t getHeight() const = 0;
        static std::unique_ptr<Window> create(const uint32_t& width, const uint32_t& height, const std::string& title);

        private:

        std::string Title;
        uint32_t Width;
        uint32_t Height;

    };

    // class WindowResizeEvent : public Event {
    //     const uint32_t width, height;
    // };
}