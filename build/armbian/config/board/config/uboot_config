// Конфигурация для U-Boot на Orange PI
#define CONFIG_SYS_TEXT_BASE       0x4A000000  // Адрес начала памяти для U-Boot
#define CONFIG_SYS_SDRAM_BASE      0x40000000  // Базовый адрес оперативной памяти
#define CONFIG_SYS_MMC_ENV_DEV     0            // Используемое устройство для загрузки
#define CONFIG_SYS_MMC_ENV_PART    0            // Раздел для загрузки с карты памяти
#define CONFIG_BOOTDELAY           3            // Задержка перед автоматическим запуском
#define CONFIG_BOOTCOMMAND        "mmc dev 0; mmc rescan; run bootcmd_mmc"  // Команда загрузки

// Параметры запуска
#define CONFIG_BAUDRATE            115200      // Скорость порта
#define CONFIG_SYS_LOAD_ADDR       0x42000000  // Адрес загрузки
