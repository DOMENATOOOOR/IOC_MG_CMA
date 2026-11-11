По умолчанию в `configure/RELEASE` указан путь `/opt/epics/base`. Если ваш EPICS установлен в другую директорию, создайте файл `configure/RELEASE.local` и пропишите ваш путь:

EPICS_BASE = /путь/к/вашему/epics/base


../../bin/linux-x86_64/CMA st.cmd

(Для macOS на Apple Silicon `../../bin/darwin-aarch64/CMA st.cmd`)


В `st.cmd` по умолчанию подключена тестовая база `sim_server.db` (Soft Channel рекорды) для эмуляции работы без реального оборудования.


