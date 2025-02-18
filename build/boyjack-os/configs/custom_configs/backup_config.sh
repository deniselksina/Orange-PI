#!/bin/bash

# Настройки резервного копирования
BACKUP_DIR="/home/user/backups"
BACKUP_INTERVAL="daily"
BACKUP_TIME="03:00"
ENABLE_COMPRESSION="true"

# Источник данных для бэкапа
SOURCE_DIRS=("/home/user/docs" "/home/user/pictures")

# Удаление старых бэкапов
DELETE_OLD_BACKUPS="true"
BACKUP_RETENTION="30"
