project(rtsp_lib)

add_library(rtsp_lib STATIC net/EventLoop.cpp net/EventLoop.h xop/RTSPServer.cpp xop/RTSPServer.h xop/rtsp.h net/TaskScheduler.cpp net/TaskScheduler.h net/Pipe.cpp net/Pipe.h net/RingBuffer.h net/SelectTaskScheduler.cpp net/SelectTaskScheduler.h net/Socket.h net/Channel.h)
target_include_directories(rtsp_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})