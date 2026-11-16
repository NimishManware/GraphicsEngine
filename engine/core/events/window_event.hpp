#pragma once
#include <engine/core/events/event.hpp>

namespace Engine
{
    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(uint width, uint height) : width_(width), height_(height){}

        uint getHeight() const {return height_; }
        uint getWidth()  const {return width_;  }

        static EventType getStaticType()
        {
            return EventType::WINDOW_RESIZE;
        }
		virtual EventType getType() const override
        {
            return getStaticType();
        }

    private:
        uint width_, height_;
    };

    class WindowCloseEvent  :public Event
    {
    public:
        WindowCloseEvent() = default;

        static EventType getStaticType()
        {
            return EventType::WINDOW_CLOSE;
        }
		virtual EventType getType() const override
        {
            return getStaticType();
        }
    };
}