#pragma once
#include <engine/core/events/event.hpp>

namespace Engine
{
    class KeyEvent : public Event
    {
    public:
        uint getCode() const {return keycode_;} // might need to change to type of keycode to some enum
        
    protected:
        KeyEvent(const uint code) : keycode_(code) {}

        uint keycode_;
    };
    
    class KeyPressedEvent : public KeyEvent
    {   
    public:
        KeyPressedEvent(const uint code, bool isRepeat = false) : KeyEvent(code), isRepeat_(isRepeat) {}

        static EventType getStaticType()
        {
            return EventType::KEY_PRESSED;
        }
		virtual EventType getType() const override
        {
            return getStaticType();
        }
    private:
        bool isRepeat_;
    };

    class KeyReleasedEvent : public KeyEvent
    {   
    public:
        KeyReleasedEvent(const uint code) : KeyEvent(code) {}

        static EventType getStaticType()
        {
            return EventType::KEY_RELEASED;
        }
		virtual EventType getType() const override
        {
            return getStaticType();
        }
    private:
        bool isRepeat_;
    };

    class KeyTypedEvent : public KeyEvent
    {   
    public:
        KeyTypedEvent(const uint code) : KeyEvent(code) {}

        static EventType getStaticType()
        {
            return EventType::KEY_TYPED;
        }
		virtual EventType getType() const override
        {
            return getStaticType();
        }
    private:
        bool isRepeat_;
    };
}