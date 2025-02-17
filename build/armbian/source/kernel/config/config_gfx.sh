#!/bin/bash

# Настройка графических параметров для платформы

echo "Настройка графических параметров..."

# Включаем поддержку HDMI
echo "Включаем поддержку HDMI..."
echo "CONFIG_FB_HDMI=m" >> .config  # Включаем поддержку фреймбуфера для HDMI

# Включаем поддержку GPU ускорения
echo "Включаем поддержку GPU ускорения..."
echo "CONFIG_GPU_VIVANTE=m" >> .config  # Поддержка Vivante GPU (например, для некоторых платформ с ARM)

# Настройка драйвера для графики
echo "Настроим драйвера для графики..."
echo "CONFIG_DRM_VIVANTE=m" >> .config  # Подключение драйвера для Vivante GPU
echo "CONFIG_DRM_KMS_HELPER=m" >> .config  # Помощник для настройки режима графического экрана

# Устанавливаем параметры для вывода на экран
echo "Настроим параметры экрана..."
echo "CONFIG_FB_SIMPLE=m" >> .config  # Простая настройка для графического вывода

# Поддержка улучшенного видео-выхода
echo "Включаем улучшенные видео-выходы..."
echo "CONFIG_DRM_HDMI_AUDIO=m" >> .config  # Подключение аудио через HDMI
echo "CONFIG_HDMI_V2=m" >> .config  # Поддержка версии HDMI 2.0 для более высоких разрешений и частот

# Конфигурация для нескольких мониторов (если необходимо)
echo "Настроим поддержку нескольких мониторов..."
echo "CONFIG_DRM_MESA=m" >> .config  # Подключаем Mesa драйверы для работы с несколькими мониторами

# Подключаем поддержку OpenGL для ускорения рендеринга
echo "Включаем поддержку OpenGL..."
echo "CONFIG_DRM_VIVANTE_OPENGL=m" >> .config  # Подключаем OpenGL для графической обработки на Vivante GPU

# Включаем framebuffer для вывода на экран
echo "Настроим framebuffer..."
echo "CONFIG_FB_CFB_FILLRECT=m" >> .config  # Поддержка операций с прямоугольными областями на фреймбуфере

# Установка драйвера для конкретных видеокарт (например, для Mali или PowerVR)
echo "Настроим драйверы для видеокарт..."
echo "CONFIG_MALI_GPU=m" >> .config  # Подключаем драйвер для GPU Mali (если используется)
echo "CONFIG_POWERVR_GPU=m" >> .config  # Подключаем драйвер для PowerVR GPU (если используется)

# Устанавливаем утилиты для диагностики и настройки графики
echo "Устанавливаем утилиты для диагностики графики..."
apt-get install -y mesa-utils

echo "Графические параметры настроены успешно."
