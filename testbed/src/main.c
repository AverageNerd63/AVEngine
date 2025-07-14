#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
    AVFATAL("This is a Message: %f", 3.14f);
    AVERROR("This is a Message: %f", 3.14f);
    AVWARN("This is a Message: %f", 3.14f);
    AVINFO("This is a Message: %f", 3.14f);
    AVDEBUG("This is a Message: %f", 3.14f);
    AVTRACE("This is a Message: %f", 3.14f);

    AVASSERT(1 == 0);
    return 0;
}