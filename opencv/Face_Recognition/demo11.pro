TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
LIBS +=/usr/lib/i386-linux-gnu/libopencv_calib3d.so -lopencv_calib3d /usr/lib/i386-linux-gnu/libopencv_contrib.so -lopencv_contrib /usr/lib/i386-linux-gnu/libopencv_core.so -lopencv_core /usr/lib/i386-linux-gnu/libopencv_features2d.so -lopencv_features2d /usr/lib/i386-linux-gnu/libopencv_flann.so -lopencv_flann /usr/lib/i386-linux-gnu/libopencv_gpu.so -lopencv_gpu /usr/lib/i386-linux-gnu/libopencv_highgui.so -lopencv_highgui /usr/lib/i386-linux-gnu/libopencv_imgproc.so -lopencv_imgproc /usr/lib/i386-linux-gnu/libopencv_legacy.so -lopencv_legacy /usr/lib/i386-linux-gnu/libopencv_ml.so -lopencv_ml /usr/lib/i386-linux-gnu/libopencv_objdetect.so -lopencv_objdetect /usr/lib/i386-linux-gnu/libopencv_ocl.so -lopencv_ocl /usr/lib/i386-linux-gnu/libopencv_photo.so -lopencv_photo /usr/lib/i386-linux-gnu/libopencv_stitching.so -lopencv_stitching /usr/lib/i386-linux-gnu/libopencv_superres.so -lopencv_superres /usr/lib/i386-linux-gnu/libopencv_ts.so -lopencv_ts /usr/lib/i386-linux-gnu/libopencv_video.so -lopencv_video /usr/lib/i386-linux-gnu/libopencv_videostab.so -lopencv_videostab
INCLUDEPATH +=/usr/include/opencv
