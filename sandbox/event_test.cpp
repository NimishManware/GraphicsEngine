#include "engine/core/events/event.hpp"
#include "engine/core/events/event_dispatch.hpp"
#include "engine/core/events/key_event.hpp"
#include "engine/core/events/window_event.hpp"

using namespace Engine;

int main() {
    KeyPressedEvent event(1);

    // Create your dispatcher
    EventDispatcher dispatcher(event);

    // Actually invoke Dispatch with KeyPressedEvent
    dispatcher.Dispatch<KeyPressedEvent>([](KeyPressedEvent) -> bool {return true;});
}