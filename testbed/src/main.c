#include <core/logger.h>
#include <core/asserts.h>

// TODO: Test
#include <platform/platform.h>

int main(void) {
    AVFATAL("A test message: %f", 3.14f);
    AVERROR("A test message: %f", 3.14f);
    AVWARN("A test message: %f", 3.14f);
    AVINFO("A test message: %f", 3.14f);
    AVDEBUG("A test message: %f", 3.14f);
    AVTRACE("A test message: %f", 3.14f);

    platform_state state;
    if(platform_startup(&state, "Kohi Engine Testbed", 100, 100, 1280, 720)) {
        while(TRUE) {
            platform_pump_messages(&state);
        }
    }
    platform_shutdown(&state);

    return 0;
}