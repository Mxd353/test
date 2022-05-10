QT += widgets

HEADERS += \
    ball.h
SOURCES += \
	ball.cpp \
	main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/Question2
INSTALLS += target
