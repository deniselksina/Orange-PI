#!/bin/bash

# Настройки фаервола
FIREWALL_ENABLED="true"
DEFAULT_POLICY="DROP"

# Разрешённые порты
ALLOWED_PORTS=("22" "80" "443")

# Логи фаервола
LOGGING_ENABLED="true"
LOG_FILE="/var/log/firewall.log"
