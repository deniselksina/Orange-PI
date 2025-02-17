#!/bin/bash

# Проверка, установлен ли make
if ! command -v make &> /dev/null
then
    echo "Make not found, please install it."
    exit 1
fi

# Сборка приложения
echo "Building app1..."
make all

# Проверка, был ли создан бинарник
if [ -f "app1.bin" ]; then
    echo "Build successful!"
else
    echo "Build failed!"
    exit 1
fi
