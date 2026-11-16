#pragma once

#include <engine/core/events/event.hpp>
#include <engine/core/core.hpp>


namespace Engine{

    class EventDispatcher
    {
        template <typename T>
        using Handler = std::function<bool (T&)>;

    public:

        EventDispatcher(Event& event) : event_(event) {}

        template<typename T>
        bool Dispatch(Handler<T> handler)
        {
            if(event_.getType() == T::getStaticType())
            {
                event_.handled |= handler(static_cast<T&>(event_));
                return true; 
            }
            return false;
        }

    private:

        Event& event_;
    };
}