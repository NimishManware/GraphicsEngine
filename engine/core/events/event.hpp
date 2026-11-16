#pragma once
#include <string>

namespace Engine {

    enum class EventType{
        NONE,       

        // Window related events        
        WINDOW_CLOSE,
        WINDOW_RESIZE,
        WINDOW_FOCUS,
        WINDOW_LOST_FOCUS,

        // Key Inputs
        KEY_PRESSED,
        KEY_RELEASED,
        KEY_TYPED,

        // Mouse Inputs
        MOUSE_BUTTON_PRESSED,
        MOUSE_BUTTON_RELEASED,
        MOUSE_MOVED,
        MOUSE_SCROLLED
    };

    class Event
    {
        public:

            bool handled = false;

            virtual ~Event() = default;
            virtual EventType getType() const = 0;
        
        private:
            
    };
    
}

