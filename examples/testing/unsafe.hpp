#ifndef UNSAFE_H
#define UNSAFE_H

#include <raylib.h>

namespace unsafe {
inline void PauseLogger() { SetTraceLogExit(LOG_ERROR); }
inline void ResumeLogger() { SetTraceLogExit(LOG_WARNING); }
}  // namespace unsafe

#endif  // UNSAFE_H