#!/bin/bash
set -e #Оборвет выполение скрипта при выпадении ошибки

if [ ! -f ../.env ]; then
    echo ".env не найден."
    exit 1
fi

source ../.env

cd ..
if [ -f ../labs ]; then
    rm -rf labs
fi

git clone "https://${BMSTU_GITLAB_USER}:${BMSTU_GITLAB_PASS}@${BMSTU_REPO_1_SEMESTER_URL}" "labs"

cd labs
rm -rf .git
cd ..

echo "Готово. Лабы находятся в папке labs."

exit 0

